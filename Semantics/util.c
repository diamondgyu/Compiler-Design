/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "util.h"

/* Procedure printToken prints a token 
 * and its lexeme to the listing file
 */
void printToken( TokenType token, const char* tokenString )
{ switch (token)
  { case IF:
    case ELSE:
    case WHILE:
    case RETURN:
    case INT:
    case VOID:
      fprintf(listing,
         "reserved word: %s\n",tokenString);
      break;
    case ASSIGN: fprintf(listing,"=\n"); break;
    case EQ: fprintf(listing,"==\n"); break;
    case NE: fprintf(listing,"!=\n"); break;
    case LT: fprintf(listing,"<\n"); break;
    case LE: fprintf(listing,"<=\n"); break;
    case GT: fprintf(listing,"<\n"); break;
    case GE: fprintf(listing,">=\n"); break;
    case PLUS: fprintf(listing,"+\n"); break;
    case MINUS: fprintf(listing,"-\n"); break;
    case TIMES: fprintf(listing,"*\n"); break;
    case OVER: fprintf(listing,"/\n"); break;
    case LPAREN: fprintf(listing,"(\n"); break;
    case RPAREN: fprintf(listing,")\n"); break;
    case LBRACE: fprintf(listing,"[\n"); break;
    case RBRACE: fprintf(listing,"]\n"); break;
    case LCURLY: fprintf(listing,"{\n"); break;
    case RCURLY: fprintf(listing,"}\n"); break;
    case SEMI: fprintf(listing,";\n"); break;
    case COMMA: fprintf(listing,",\n"); break;
    case '\0': fprintf(listing,"EOF\n"); break;
    case NUM:
      fprintf(listing,
          "NUM, val= %s\n",tokenString);
      break;
    case ID:
      fprintf(listing,
          "ID, name= %s\n",tokenString);
      break;
    case ERROR:
      fprintf(listing,
          "ERROR: %s\n",tokenString);
      break;
    default: /* should never happen */
      fprintf(listing,"Unknown token: %d\n",token);
  }
}

char* getType(TypeType type)
{
  if (type == Void)
    return "void";
  else if (type == Integer)
    return "int";
  else if (type == VoidArray)
    return "void[]";
  else if (type == IntegerArray)
    return "int[]";
  else
    return "UNKNOWN TYPE";
}

char* getDecType(DecType type)
{
  if (type == VarDec)
    return "Var";
  else if (type == FuncDec)
    return "Func";
  else if (type == ArrDec)
    return "Arr";
  else if (type == ParamDec)
    return "Param";
  else if (type == ArrParamDec)
    return "ArrParam";
  else
    return "UNKNOWN TYPE";
}

char* getExprType(ExprType type)
{
  if (type == IdExpr)
    return "Id";
  else if (type == OpExpr)
    return "Op";
  else if(type == ConstExpr)
    return "Const";
  else if(type == AssignExpr)
    return "Assign";
  else if(type == AccessExpr)
    return "Access";
  else if(type == IndexExpr)
    return "Index";
  else if(type == CallExpr)
    return "Call";
  else
    return "UNKNOWN TYPE";
}

char* getOp(TokenType op)
{
  if (op == ASSIGN)
    return "=";
  else if (op == PLUS)
    return "+";
  else if (op == MINUS)
    return "-";
  else if (op == TIMES)
    return "*";
  else if (op == OVER)
    return "/";
  else if (op == LT)
    return "<";
  else if (op == LE)
    return "<=";
  else if (op == GT)
    return ">";
  else if (op == GE)
    return ">=";
  else if (op == EQ)
    return "==";
  else if (op == NE)
    return "!=";
  else
    return "UNKNOWN OP";
}

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode * newStmtNode(StmtType kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->node_type = Stmt;
    t->stmt_type = kind;
    t->lineno = lineno;
  }
  return t;
}

TreeNode * newDecNode(DecType kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->node_type = Dec;
    t->dec_type = kind;
    t->lineno = lineno;
  }
  return t;
}

/* Function newExpNode creates a new expression 
 * node for syntax tree construction
 */
TreeNode * newExprNode(ExprType kind)
{ 
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    
    t->node_type = Expr;
    t->expr_type = kind;
    t->lineno = lineno;
    
    t->type = Void;
    
  }
  // printf("%d\n", sizeof(t));
  return t;
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char * copyString(char * s)
{ int n;
  char * t;
  if (s==NULL) return NULL;
  n = strlen(s)+1;
  t = malloc(n);
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else strcpy(t,s);
  return t;
}

/* Variable indentno is used by printTree to
 * store current number of spaces to indent
 */
static indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno+=2
#define UNINDENT indentno-=2

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{ int i;
  for (i=0;i<indentno;i++)
    fprintf(listing," ");
}

/* procedure printTree prints a syntax tree to the 
 * listing file using indentation to indicate subtrees
 */

/* 
What does printTree do
 1. Read token
 2. If token is Dec, print the declaration string
 3. If token is Stmt, print the statement string
 4. If token is Expr, print the expression string
 5. Dive into its children

*/
void printTree( TreeNode * tree )
{ 
  
  int i;
  INDENT;
  while (tree != NULL) {
    printSpaces();
    if (tree->node_type==Stmt)
    { 
      switch (tree->stmt_type) {
        case CompoundStmt:
          fprintf(listing,"Compound Statement:\n");
          break;
        case IfStmt: // IF
          fprintf(listing,"If Statement:\n");
          break;
        case IfElseStmt: // IF-ELSE
          fprintf(listing,"If-Else Statement:\n");
          break;
        case WhileStmt: // WHILE
          fprintf(listing,"While Statement:\n");
          break;
        case ReturnStmt:
          if (tree->type == Void){ fprintf(listing,"Void Return\n"); break;}
          fprintf(listing,"Return Statement:\n");
          break; 
        default:
          fprintf(listing,"Unknown ExpNode kind\n");
          break;
      }
    }
    else if (tree->node_type==Expr)
    { 
     switch (tree->expr_type) {
        case OpExpr:
          fprintf(listing,"Op: ");
          printToken(tree->op,"\0");
          break;
        case ConstExpr:
          fprintf(listing,"Const: %d\n",tree->val);
          break;
        case IdExpr:
          fprintf(listing,"Variable: name = %s\n",tree->name);
          break;
        case AssignExpr:
          fprintf(listing,"Assign:\n");
          break;
        // case TypeExpr:
        //   fprintf(listing,"Type: %s\n",getType(tree->type));
        case CallExpr:
          fprintf(listing,"Call: function name = %s\n",tree->name);
          break;
        default:
          fprintf(listing,"Unknown ExpNode kind\n");
          break;
      }
    }
    else if (tree->node_type==Dec)
    {
  
      switch(tree->dec_type)
      {
        case VarDec:
          fprintf(listing,"Variable Declaration: name = %s, type = %s\n",tree->name, getType(tree->type));
          break;
        case FuncDec:
          fprintf(listing,"Function Declaration: name = %s, type = %s\n",tree->name, getType(tree->type));
          break;
        case ArrDec:
          fprintf(listing,"Variable Declaration: name = %s, type = %s\n",tree->name, getType(tree->type));
          // fprintf(listing,"Const: %d\n",tree->arraySize);
          break;
        case ArrParamDec:
          fprintf(listing,"Parameter: name = %s, type = %s\n",tree->name, getType(tree->type));
          break;
        case ParamDec:
          if (tree->name == NULL) { fprintf(listing,"Void Parameter\n"); break; }
          fprintf(listing,"Parameter: name = %s, type = %s\n",tree->name, getType(tree->type));
          break;
        default:
          fprintf(listing,"Unknown Declaration Node Type\n");
          break;
      }
    }
    else fprintf(listing,"Unknown node kind\n");
    for (i=0;i<MAXCHILDREN;i++)
         printTree(tree->child[i]);
    tree = tree->sibling;
  }
  UNINDENT;
}
