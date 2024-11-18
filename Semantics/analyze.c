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
    // preProc(t);
    Scope new_scope = NULL;
    int does_exist = 0;
    {
      // add to symbol table
      if (t->node_type == Dec)
        new_scope = st_insert(currentScope_cpy, t, location++);

      // when the scope is added for the first time (global)
      if (currentScope == NULL)
      {
        if (new_scope->parent != NULL)
          currentScope = new_scope->parent;
        else
          currentScope = new_scope;
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
      // else location = 0;

      int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(t->child[i],preProc,postProc, new_scope);
    }
    // postProc(t);
    // if going to the sibling when it is a function, init the location
    // if (t->sibling != NULL && t->sibling->node_type == Dec && t->sibling->dec_type == FuncDec) location = 0;

    traverse(t->sibling,preProc,postProc, currentScope);
  }
}

static void traverse_for_type( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *, Scope),
               Scope currentScope )
{
  Scope currentScope_cpy = currentScope;
  if (t != NULL)
  { preProc(t);
    Scope new_scope = NULL;
    { int i;
      if (currentScope_cpy == NULL)
        currentScope_cpy = getScopeRoot();
      if (t->node_type == Dec && t->dec_type == FuncDec)
      {
        for(i=0; strcmp(t->name, currentScope_cpy->children[i]->name)!=0; i++) 
          new_scope = currentScope_cpy->children[i+1];
        if (new_scope == NULL)
          new_scope = currentScope_cpy->children[0];
      }
      else new_scope = currentScope_cpy;
        
      for (i=0; i < MAXCHILDREN; i++)
        traverse_for_type(t->child[i],preProc,postProc,new_scope);
    }
    postProc(t, currentScope_cpy);
    traverse_for_type(t->sibling,preProc,postProc,currentScope_cpy);
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
  traverse(syntaxTree,insertNode,checkNode, NULL);
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
static void checkNode(TreeNode * t, Scope scope)
{

  Scope scope_copy = scope;
  switch (t->node_type)
  {
    case Expr:
    switch (t->expr_type)
    {
      // to implement
      case AssignExpr:

        printf("%d: %ld %ld\n", t->op, t->child[0]->type, t->child[1]->type);
        printf("%d: %s %s\n", t->op, t->child[0]->name, t->child[1]->name);

        if ((t->child[0]->type == t->child[1]->type) 
        || (t->child[0]->type == IntegerWasArray && t->child[1]->type == Integer) 
        || (t->child[0]->type == Integer && t->child[1]->type == IntegerWasArray))
        {
          break;
        }
        else
        {
          fprintf(listing, "Error: invalid assignment at line %d\n", t->lineno);
          Error = TRUE;
        }
        // // printf()
        // if (t->child[0]->type == Integer && t->child[1]->type == Integer)
        //   break;
        // else
        // {
        //   fprintf(listing, "Error: invalid assignment at line %d\n", lineno);
        //   Error = TRUE;
        //   break;
        // }
        break;
      case AccessExpr:
        break;
      case IndexExpr:
        break;
      case CallExpr:
      // check if the function call is valid
        break;
      case TypeExpr:
        break;

      case OpExpr:
       // printf("%d %s %s\n", t->op, t->child[0]->type==Integer?"int":"int[]", t->child[1]->type==Integer?"int":"int[]");
        if ((t->child[0]->type != Integer && t->child[0]->type != IntegerWasArray) ||
            (t->child[1]->type != Integer && t->child[1]->type != IntegerWasArray))
          fprintf(listing, "Error: invalid operation at line %d\n", t->lineno);
          t->type = Undeclared;
        if ((t->op == EQ) || (t->op == LT) || (t->op == GT) || (t->op == LE) || (t->op == GE) || (t->op == NE))
          t->type = Bool;
          // t->type = Boolean;
        else
          t->type = Integer;
        break;

      case ConstExpr:
        t->type = Integer;
        break;

      case IdExpr:
        Scope var_scope = check_scope(scope_copy, t->name);
        // Undeclared: do nothing
        if (var_scope == NULL)
          break;
        
        
        Symbol s = var_scope->symbols[0];
        for(int i=0; strcmp(s->name, t->name)!=0; i++) s = var_scope->symbols[i];
        // type is an integer array and has const child
        if(strcmp(s->type, "Integer[]") == 0 && t->child[0] == NULL)
          t->type = IntegerArray;
        else if (strcmp(s->type, "Integer[]") == 0 && t->child[0] != NULL)
          t->type = IntegerWasArray;
        else
          t->type = Integer;
        
        // invalid array indexing: indexing of int
        printf("%s, %ld, %d\n", t->name, t->child[0], t->type);
        if (t->child[0] != NULL && t->type == Integer)
          fprintf(listing, "Error: Invalid array indexing at line %d (name : \"%s\"). indexing can only allowed for int[] variables\n", t->lineno, t->name);

        // invalid array indexing: index is not integer
        if (t->child[0] != NULL && t->child[0]->type != Integer)
          fprintf(listing, "Error: Invalid array indexing at line %d (name : \"%s\"). indicies should be integer\n", t->lineno, t->name);


        
        break;

      default:
        break;
    }
    break;
    case Stmt:
    switch (t->stmt_type)
    {
      
      case IfStmt:
        if (t->child[0] == NULL)
          fprintf(listing, "Error: invalid condition at line %d\n", t->lineno);
        else if (t->child[0]->type != Bool)
          fprintf(listing, "Error: invalid condition at line %d\n", t->lineno);
        break;
      case IfElseStmt:
        if (t->child[0] == NULL)
          fprintf(listing, "Error: invalid condition at line %d\n", t->lineno);
        else if (t->child[0]->type != Bool)
          fprintf(listing, "Error: invalid condition at line %d\n", t->lineno);
        break;
      case WhileStmt:
        if (t->child[0] == NULL)
          fprintf(listing, "Error: invalid condition at line %d\n", t->lineno);
        else if (t->child[0]->type != Bool)
          fprintf(listing, "Error: invalid condition at line %d\n", t->lineno);
        break;
      case ReturnStmt:
        Scope sc = check_scope(scope_copy, scope_copy->name);
        Symbol s = sc->symbols[0];
        for(int i=0; strcmp(s->name, scope_copy->name)!=0; i++) s = sc->symbols[i];
        if (strcmp(s->type, "Void") == 0)
        {
          if (t->child[0] != NULL)
            fprintf(listing, "Error: Invalid return at line %d\n", t->lineno);
        }
        else
        {
          if (t->child[0] == NULL)
            fprintf(listing, "Error: Invalid return at line %d\n", t->lineno);
        }
        break;
      case CompoundStmt:
        break;
      default:
        break;
    }
    break;
    case Dec:
      switch (t->dec_type)
      {
        case FuncDec:
          break;
        
        case VarDec:
        if (t->type == Void)
          fprintf(listing, "Error: The void-type variable is declared at line %d (name : \"%s\")\n", t->lineno, t->name);
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
{ traverse_for_type(syntaxTree,nullProc,checkNode, NULL);
}
