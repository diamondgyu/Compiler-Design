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
    
   

%token IF, ELSE, WHILE, RETURN, INT, VOID
%token NUM ID
%token ENDFILE, ERROR

%token ASSIGN, EQ, NE, LT, LE, GT, GE, LPAREN, RPAREN, LBRACE, RBRACE, LCURLY, RCURLY, SEMI, COMMA

// Operator precedence
%left PLUS, MINUS
%left TIMES, OVER

// Grammar rules
%%
program: declaration_list { $$ = $1; };

declaration_list: declaration_list declaration { $$ = $1; }
                | declaration { $$ = $1; };

declaration: var_declaration { $$ = $1; }
           | fun_declaration { $$ = $1; };

var_declaration: type_specifier ID ';' { $$ = $2; }
               | type_specifier ID '[' NUM ']' ';' { $$ = $2; };

type_specifier: INT { $$ = $1; }
              | VOID { $$ = $1; };

fun_declaration: type_specifier ID '(' params ')' compound_stmt { $$ = $2; };

params: param_list { $$ = $1; }
      | VOID { $$ = 0; };

param_list: param_list ',' param { $$ = $1; }
          | param { $$ = $1; };

param: type_specifier ID { $$ = $2; }
     | type_specifier ID '[' ']' { $$ = $2; };

compound_stmt: '{' local_declarations statement_list '}' { $$ = $2; };

local_declarations: local_declarations var_declaration { $$ = $1; }
                  | /* empty */ { $$ = 0; };

statement_list: statement_list statement { $$ = $1; }
              | /* empty */ { $$ = 0; };

statement: expression_stmt { $$ = $1; }
         | compound_stmt { $$ = $1; }
         | selection_stmt { $$ = $1; }
         | iteration_stmt { $$ = $1; }
         | return_stmt { $$ = $1; };

expression_stmt: expression ';' { $$ = $1; }
               | ';' { $$ = 0; };

selection_stmt: IF '(' expression ')' statement { $$ = $3; }
              | IF '(' expression ')' statement ELSE statement { $$ = $3; };

iteration_stmt: WHILE '(' expression ')' statement { $$ = $3; };

return_stmt: RETURN ';' { $$ = 0; }
           | RETURN expression ';' { $$ = $2; };

expression: var '=' expression { $$ = $3; }
          | simple_expression { $$ = $1; };

var: ID { $$ = $1; }
   | ID '[' expression ']' { $$ = $3; };

simple_expression: additive_expression relop additive_expression { $$ = $1; }
                 | additive_expression { $$ = $1; };

relop: LE { $$ = $1; } 
     | '<' { $$ = '<'; } 
     | '>' { $$ = '>'; } 
     | GE { $$ = GE; } 
     | EQ { $$ = EQ; } 
     | NE { $$ = NE; };

additive_expression: additive_expression addop term { $$ = $1 + $3; }
                   | term { $$ = $1; };

addop: '+' { $$ = '+'; }
     | '-' { $$ = '-'; };

term: term mulop factor { $$ = $1 * $3; }
    | factor { $$ = $1; };

mulop: '*' { $$ = '*'; }
     | '/' { $$ = '/'; };

factor: '(' expression ')' { $$ = $2; }
      | var { $$ = $1; }
      | call { $$ = $1; }
      | NUM { $$ = atoi(yytext); }; // Assuming NUM is a string of digits

call: ID '(' args ')' { /* function call logic */ };

args: arg_list { /* argument list logic */ }
    | /* empty */;

arg_list: arg_list ',' expression { /* list logic */ }
        | expression;

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

