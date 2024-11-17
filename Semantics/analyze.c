/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"

/* counter for variable memory locations */
static int location = 0;

/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
static void traverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *),
               Scope currentScope )
{ 
  // add input, value to lineno 0
  
  Scope currentScope_cpy = currentScope;
  if (t != NULL)
  { 
    // if (currentScope != NULL)
    //   printf("%s %s %d\n", currentScope->name, t->name, t->lineno);
    preProc(t);
    Scope new_scope = NULL;
    int does_exist = 0;
    {
      // add to symbol table
      if (t->node_type == Dec)
        new_scope = st_insert(currentScope_cpy, t, location++);

      // when the scope is added for the first time (global)
      if (currentScope == NULL)
      {
        currentScope = new_scope->parent;
        currentScope_cpy = currentScope;
      }
        
      else if (t->node_type == Dec && t->dec_type == ParamDec && t->type == Void)
        does_exist = 1;

      // if id or call, check if it is defined
      else if (t->node_type == Expr && (t->expr_type == IdExpr || t->expr_type == CallExpr))
      {
        does_exist = st_lookup(currentScope_cpy, t);
        // if the symbol is not defined
        if (does_exist == 0)
        {
          st_insert(currentScope_cpy, t, location++);
          if (t->expr_type == CallExpr)
            fprintf(listing, "Error: undeclared function \"%s\" is called at line %d\n", t->name, t->lineno);
          else
            fprintf(listing, "Error: undeclared variable \"%s\" is used at line %d\n", t->name, t->lineno);
        }
          
      }
        
        
      // if the scope is not added, don't change the scope
      if(new_scope == NULL) new_scope = currentScope_cpy;

      int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(t->child[i],preProc,postProc, new_scope);
    }
    postProc(t);
    // if going to the sibling when it is a function, init the location
    if (t->node_type == Dec && t->dec_type == FuncDec) location = 0;

    traverse(t->sibling,preProc,postProc, currentScope);
  }
}

/* nullProc is a do-nothing procedure to 
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode * t)
{ if (t==NULL) return;
  else return;
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode( TreeNode * t)
{

}
// { switch (t->nodekind)
//   { case StmtK:
//       switch (t->kind.stmt)
//       { case AssignK:
//         case ReadK:
//           if (st_lookup(t->attr.name) == -1)
//           /* not yet in table, so treat as new definition */
//             st_insert(t->attr.name,t->lineno,location++);
//           else
//           /* already in table, so ignore location, 
//              add line number of use only */ 
//             st_insert(t->attr.name,t->lineno,0);
//           break;
//         default:
//           break;
//       }
//       break;
//     case ExpK:
//       switch (t->kind.exp)
//       { case IdK:
//           if (st_lookup(t->attr.name) == -1)
//           /* not yet in table, so treat as new definition */
//             st_insert(t->attr.name,t->lineno,location++);
//           else
//           /* already in table, so ignore location, 
//              add line number of use only */ 
//             st_insert(t->attr.name,t->lineno,0);
//           break;
//         default:
//           break;
//       }
//       break;
//     default:
//       break;
//   }
// }

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ 
  traverse(syntaxTree,insertNode,nullProc, NULL);
  if (TraceAnalyze)
  { fprintf(listing,"\nSymbol table:\n\n");
    printSymTab(listing);
  }
}

static void typeError(TreeNode * t, char * message)
{ fprintf(listing,"Type error at line %d: %s\n",t->lineno,message);
  Error = TRUE;
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode * t)
{
  switch (t->node_type)
  {
    case Expr:
    switch (t->expr_type)
    {
      // to implement
      case AssignExpr:
        // printf()
        if (t->child[0]->type == Integer && t->child[1]->type == Integer)
          break;
        else
        {
          fprintf(listing, "Error: invalid assignment at line %d\n", lineno);
          Error = TRUE;
          break;
        }
        t->type = Integer;
        break;
      case AccessExpr:
        break;
      case IndexExpr:
        break;
      case CallExpr:
        break;
      case TypeExpr:
        break;

      case OpExpr:
        if ((t->child[0]->type != Integer) ||
            (t->child[1]->type != Integer))
          typeError(t,"Op applied to non-integer");
        if ((t->op == EQ) || (t->op == LT))
          break;
          // t->type = Boolean;
        else
          t->type = Integer;
        break;
      case ConstExpr:
      case IdExpr:
        t->type = Integer;
        break;  
      default:
        break;
    }
    case Stmt:
    switch (t->stmt_type)
    {
      case IfStmt:
        break;
      case IfElseStmt:
        break;
      case WhileStmt:
        break;
      case ReturnStmt:
        break;
      case CompoundStmt:
        break;
      default:
        break;
    }
    case Dec:
    switch (t->stmt_type)
    {
      case ArrDec:
        break;
      case VarDec:
        break;
      case FuncDec:
        break;
      case ParamDec:
        break;
      case ArrParamDec:
        break;
      
      default:
        break;
    }
    /* code */
  // in case of operation expression
  
  }
}
// { switch (t->nodekind)
//   { case ExpK:
//       switch (t->kind.exp)
//       { case OpK:
//           if ((t->child[0]->type != Integer) ||
//               (t->child[1]->type != Integer))
//             typeError(t,"Op applied to non-integer");
//           if ((t->attr.op == EQ) || (t->attr.op == LT))
//             t->type = Boolean;
//           else
//             t->type = Integer;
//           break;
//         case ConstK:
//         case IdK:
//           t->type = Integer;
//           break;
//         default:
//           break;
//       }
//       break;
//     case StmtK:
//       switch (t->kind.stmt)
//       { case IfK:
//           if (t->child[0]->type == Integer)
//             typeError(t->child[0],"if test is not Boolean");
//           break;
//         case AssignK:
//           if (t->child[0]->type != Integer)
//             typeError(t->child[0],"assignment of non-integer value");
//           break;
//         case WriteK:
//           if (t->child[0]->type != Integer)
//             typeError(t->child[0],"write of non-integer value");
//           break;
//         case RepeatK:
//           if (t->child[1]->type == Integer)
//             typeError(t->child[1],"repeat test is not Boolean");
//           break;
//         default:
//           break;
//       }
//       break;
//     default:
//       break;

/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree)
{ traverse(syntaxTree,nullProc,checkNode, NULL);
}
