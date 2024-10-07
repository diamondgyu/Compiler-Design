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
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void); // added 11/2/11 to ensure no conflict with lex

%}

// Token definitions

    /* special symbols */
    
   

%token IF, ELSE, WHILE, RETURN, INT, VOID, INTARRAY, VOIDARRAY
%token NUM ID
%token ENDFILE, ERROR

%token ASSIGN, EQ, NE, LT, LE, GT, GE, LPAREN, RPAREN, LBRACE, RBRACE, LCURLY, RCURLY, SEMI, COMMA

// Operator precedence
%left PLUS, MINUS
%left TIMES, OVER

// Grammar rules
%%
// nonterminals: 
program: declaration_list { savedTree = $1; };

declaration_list: declaration_list declaration
                  { 
                    YYSTYPE t = $1;
                    if (t != NULL)
                    { 
                         while (t->sibling != NULL)
                         t = t->sibling;
                         t->sibling = $2;
                         $$ = $1; 
                    }
                     else $$ = $2;
                  }
                | declaration { 
                    $$ = $1; 
                  };

declaration: var_declaration { $$ = $1; }
           /* | func_declaration { $$ = $1; }; */

var_declaration: type_specifier ID SEMI { $$ = $2; }
               | type_specifier ID LBRACE NUM RBRACE SEMI { $$ = $2; };

/* func_declaration: type_specifier ID LPAREN params RPAREN compound_stmt { $$ = $2; }; */

type_specifier: INT { $$ = $1; }
              | VOID { $$ = $1; };
              | INTARRAY { $$ = $1; };
              | VOIDARRAY { $$ = $1; };


/* 




params: param_list { $$ = $1; }
      | VOID { $$ = 0; };

param_list: param_list COMMA param { $$ = $1; }
          | param { $$ = $1; };

param: type_specifier ID { $$ = $2; }
     | type_specifier ID LBRACE RBRACE { $$ = $2; };

compound_stmt: LCURLY local_declarations statement_list RCURLY { $$ = $2; };

local_declarations: local_declarations var_declaration { $$ = $1; }
                  |  { $$ = 0; };

statement_list: statement_list statement { $$ = $1; }
              |  { $$ = 0; };

statement: expression_stmt { $$ = $1; }
         | compound_stmt { $$ = $1; }
         | selection_stmt { $$ = $1; }
         | iteration_stmt { $$ = $1; }
         | return_stmt { $$ = $1; };

expression_stmt: expression SEMI { $$ = $1; }
               | SEMI { $$ = 0; };

selection_stmt: IF LPAREN expression RPAREN statement { $$ = $3; }
              | IF LPAREN expression RPAREN statement ELSE statement { $$ = $3; };

iteration_stmt: WHILE LPAREN expression RPAREN statement { $$ = $3; };

return_stmt: RETURN SEMI { $$ = 0; }
           | RETURN expression SEMI { $$ = $2; };

expression: var EQ expression { $$ = $3; }
          | simple_expression { $$ = $1; };

var: ID { $$ = $1; }
   | ID LBRACE expression RBRACE { $$ = $3; };

simple_expression: additive_expression relop additive_expression { $$ = $1; }
                 | additive_expression { $$ = $1; };

relop: LE { $$ = LE; } 
     | LT { $$ = LT; } 
     | GT { $$ = GT; } 
     | GE { $$ = GE; } 
     | EQ { $$ = EQ; } 
     | NE { $$ = NE; };

additive_expression: additive_expression addop term { 
                         $$ = newExpNode(OpK); 
                         $$ -> child[0] = $1
                         $$ -> child[1] = $3
                         $$ -> attr.op = addop
                    }
                   | term { $$ = $1; };

addop: PLUS { $$ = PLUS; }
     | MINUS { $$ = MINUS; };

term: term mulop factor { $$ = $1 * $3; }
    | factor { $$ = $1; };

mulop: TIMES { $$ = TIMES; }
     | OVER { $$ = OVER; };

factor: LPAREN expression RPAREN { $$ = $2; }
      | var { $$ = $1; }
      | call { $$ = $1; }
      | NUM { $$ = atoi(yytext); }; // Assuming NUM is a string of digits

call: ID LPAREN args RPAREN { };

args: arg_list {  }
    | ;

arg_list: arg_list COMMA expression { }
        | expression; */

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

