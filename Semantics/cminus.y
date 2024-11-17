/****************************************************/
/* File: tiny.y                                     */
/* The TINY Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *

static char * savedName; /* for use in assignments */
static int savedType;
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int savedNum;
static int savedOp;
static int yylex(void); // added 11/2/11 to ensure no conflict with lex
static int yyerror(char* s);

%}

// Token definitions

    /* special symbols */
    
   

%token IF WHILE RETURN INT VOID INTARRAY VOIDARRAY
%token NUM ID
%token ENDFILE ERROR

%token EQ NE LT LE GT GE LPAREN RPAREN LBRACE RBRACE LCURLY RCURLY SEMI COMMA

// To resolve conflicts
%nonassoc IFONLY
%nonassoc PARAMONLY
%right ELSE

%left PLUS MINUS
%left TIMES OVER

%right ASSIGN


// Grammar rules
%%
// nonterminals: 
program: declaration_list { savedTree = $1; };

declaration_list : declaration_list declaration { 
                    YYSTYPE t = $1;
                     if (t != NULL) {
                       while (t->sibling != NULL) { t = t->sibling; }
                       t->sibling = $2;
                       $$ = $1;
                     } else {
                       $$ = $2;
                     }
                   }
                 | declaration { $$ = $1; }
                 ;

declaration: var_declaration { $$ = $1; }
           | func_declaration { $$ = $1; };

id : ID{ 
       savedName = copyString(tokenString);
       savedLineNo = lineno;
     };

num : NUM{ 
    savedNum = atoi(copyString(tokenString));
    savedLineNo = lineno;
    $$ = newExprNode(ConstExpr);
    $$->lineno=lineno;
    $$->val=atoi(copyString(tokenString));
  };

var_declaration: type_specifier id SEMI {
                    $$ = newDecNode(VarDec);
                    $$->lineno=lineno;
                    $$->name=copyString(savedName);
                    $$->type=savedType;
                 };
               | type_specifier id LBRACE num RBRACE SEMI { 
                    $$ = newDecNode(ArrDec);
                    $$->child[0] = $1;
                    $$->child[1] = $4;
                    $$->lineno=lineno;
                    $$->name=copyString(savedName);
                    if (savedType == Integer)
                      $$->type=IntegerArray;
                    else
                      $$->type=VoidArray;
                 };

type_specifier: INT { savedType=Integer; };
              | VOID { savedType=Void; };

func_declaration : type_specifier id {
                   $$ = newDecNode(FuncDec);
                   $$->lineno = lineno;
                   $$->name = copyString(savedName);
                   $$->type = savedType;
                 }
                 LPAREN params RPAREN compound_stmt
                 { $$ = $3;
                   $$->child[0] = $1;
                   $$->child[1] = $5;
                   $$->child[2] = $7;
                 };

// about functions
params: param_list { $$ = $1; }
      | VOID { $$ = newDecNode(ParamDec);
           $$->type = Void;
         };

param_list: param_list COMMA param { 
              YYSTYPE t = $1;
              if (t != NULL) {
                while (t->sibling != NULL) { t = t->sibling; }
                t->sibling = $3;
                $$ = $1;
              } else {
                $$ = $2;
              }
            }
          | param { $$ = $1; } %prec PARAMONLY;

param : type_specifier id { 
          $$ = newDecNode(ParamDec);
          $$->child[0] = $1;
          $$->type=savedType;
          $$->name = copyString(savedName);
        }
      | type_specifier id LBRACE RBRACE { 
          $$ = newDecNode(ArrParamDec);
          $$->child[0] = $1;
          if (savedType == Integer)
            $$->type=IntegerArray;
          else
            $$->type=VoidArray;
          $$->name = copyString(savedName);
        };

compound_stmt: LCURLY local_declarations statement_list RCURLY { 
          $$ = newStmtNode(CompoundStmt);
          $$->name = copyString("compound");
          $$->child[0] = $2;
          $$->child[1] = $3;
      };

local_declarations: local_declarations var_declaration{ 
                      YYSTYPE t = $1;
                       if (t != NULL) {
                         while (t->sibling != NULL) { t = t->sibling; }
                         t->sibling = $2;
                         $$ = $1;
                       } else {
                         $$ = $2;
                       }
                     }
                   | { $$ = NULL; };
  
//Statements and Expressions
statement_list : statement_list statement { 
                   YYSTYPE t = $1;
                   if (t != NULL) {
                     while (t->sibling != NULL) { t = t->sibling; }
                    t->sibling = $2;
                    $$ = $1;
                   } else {
                     $$ = $2;
                   }
                 }
               | { $$ = NULL; };


statement: expression_stmt { $$ = $1; };
         | compound_stmt { $$ = $1; }
         | selection_stmt { $$ = $1; }
         | iteration_stmt { $$ = $1; }
         | return_stmt { $$ = $1; };

expression_stmt: expression SEMI { $$ = $1; }
               | SEMI { $$ = 0; };

return_stmt: RETURN SEMI { 
              $$ = newStmtNode(ReturnStmt);
              $$->type=Void;
            }
           | RETURN expression SEMI { 
             $$ = newStmtNode(ReturnStmt);
             $$->type = Integer;
             $$->child[0] = $2;
             $$->name = copyString("return");
            };

expression: var ASSIGN expression { 
            $$ = newExprNode(AssignExpr);
            $$->child[0] = $1;
            $$->child[1] = $3;
            $$->name = copyString("expression");
          }
          | simple_expression { $$ = $1; };

var: id { $$ = newExprNode(IdExpr); $$->name=copyString(savedName);}
   | id LBRACE {
      $$ = newExprNode(IdExpr);
      $$->name=copyString(savedName); 
    }
    expression RBRACE { 
      $$ = $3;
      $$->child[0] = $4;
    };

simple_expression: additive_expression relop additive_expression { 
                     $$ = newExprNode(OpExpr);
                     $$->child[0] = $1;
                     $$->child[1] = $3;
                     $$->op = savedOp;
                     $$->name = copyString("simple_expression");
                   }
                 | additive_expression { $$ = $1; };

relop: LE { savedOp = LE; } 
     | LT { savedOp = LT; } 
     | GT { savedOp = GT; } 
     | GE { savedOp = GE; } 
     | NE { savedOp = NE; }
     | EQ { savedOp = EQ; };

additive_expression: additive_expression addop {
                        $$ = newExprNode(OpExpr);
                        $$->name = copyString("additive_expression");
                        $$->op=savedOp;
                    } term { 
                         $$ = $3;
                         $$ -> child[0] = $1;
                         $$ -> child[1] = $4;
                    }
                   | term { $$ = $1; };

addop: PLUS { savedOp = PLUS; }
     | MINUS { savedOp = MINUS; };

term: term mulop {
$$=newExprNode(OpExpr);
$$->op=savedOp;  
}
factor { 
  $$ = $3;
  $$->child[0]=$1; 
  $$->child[1]=$4; 
  
  }
    | factor { $$ = $1; };


mulop: TIMES { savedOp = TIMES; }
     | OVER { savedOp = OVER; };

factor: LPAREN expression RPAREN { $$ = $2; }
      | var { $$ = $1; }
      | call { $$ = $1; }
      | num { 
           $$ = newExprNode(ConstExpr);
           $$->type = Integer;
           $$->val = atoi(copyString(tokenString));
         };

// Function Calls
call: id {
  $$ = newExprNode(CallExpr);
  $$->name = copyString(savedName);
} LPAREN args RPAREN { 
  $$ = $2;
  $$->child[0] = $4;
};

args: arg_list { $$=$1; }
    | { $$ = NULL; };

arg_list: arg_list COMMA expression { 
   YYSTYPE t = $1;
             if (t != NULL) {
               while (t->sibling != NULL) { t = t->sibling; }
               t->sibling = $3;
               $$ = $1;
             } else {
               $$ = $3;
             }
}
        | expression {$$ = $1;}; 

// If, If/Else
selection_stmt: IF LPAREN expression RPAREN statement { 
                  $$ = newStmtNode(IfStmt);
                  $$->child[0] = $3;
                  $$->child[1] = $5;
                } %prec IFONLY
              | IF LPAREN expression RPAREN statement ELSE statement { 
                  $$ = newStmtNode(IfElseStmt);
                  $$->child[0] = $3;
                  $$->child[1] = $5;
                  $$->child[2] = $7;
                };

iteration_stmt: WHILE LPAREN expression RPAREN statement { 
                  $$ = newStmtNode(WhileStmt);
                  $$->child[0] = $3;
                  $$->child[1] = $5;
                };

%%


int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

