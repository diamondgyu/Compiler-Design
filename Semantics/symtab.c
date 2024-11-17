/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "globals.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

static Scope scopeTree = NULL;

// Hash function
static int hash(char* key) {
    int temp = 0;
    int i = 0;
    while (key[i] != '\0') {
        temp = ((temp << SHIFT) + key[i]) % SIZE;
        ++i;
    }
    return temp;
}

// utility function: create a new scope
Scope insert_scope(char* name, Scope parent) {
    Scope newScope = (Scope)calloc(1, sizeof(struct Scope));
    newScope->name = copyString(name);
    newScope->parent = parent;
    newScope->num_symbols = 0;
    newScope->index_children = 0;

    // In case of creating the root node
    if (parent != NULL)
      parent->children[parent->index_children++] = newScope;

    return newScope;
}

// Search for a scope by name. starts from the current scope
Scope check_scope(Scope scope, char* name) 
{
  Scope scope_cpy = scope;
   while(scope_cpy != NULL) {
      // check if any symbol has the same name
      for(int i=0; i<scope_cpy->num_symbols; i++) {
         if (strcmp(scope_cpy->symbols[i]->name, name) == 0) {
            return scope_cpy;
         }
      }
      scope_cpy = scope_cpy->parent;
   }
   return NULL;
}

int st_lookup(Scope scope, TreeNode* node) {
  
  Scope scope_cpy = scope;
   while(scope_cpy != NULL) {
      // check if any symbol has the same name
      for(int i=0; i<scope_cpy->num_symbols; i++) {
         if (strcmp(scope_cpy->symbols[i]->name, node->name) == 0) {
            add_line(scope_cpy, node);
            return 1;
         }
      }
      scope_cpy = scope_cpy->parent;
   }
  // returns 0 if not found
   return 0;
}

  // add new symbol to current scope
  // if type is void and kind is variable, add 'undetermined'
int add_new_symbol(Scope scope, TreeNode* node, int loc)
{
  Symbol sym = (Symbol)calloc(1, sizeof(struct Symbol));
  sym->name = copyString(node->name);
  
      
  // printf("");
  // printf("sym: %S, sym->kind: %S\n", sym->name, sym->kind);
  switch (node->type)
  {
    case Integer:
      sym->type = copyString("Integer");
      break;
    case Void:
      sym->type = copyString("Void");
      break;
    case IntegerArray:
      sym->type = copyString("Integer[]");
      break;
    case VoidArray:
      sym->type = copyString("Void[]");
      break;
    case Undeclared:
      sym->type = copyString("undeclared");
      break;
  }

  if (node->node_type == Dec || node->node_type == Expr)
    if (node->dec_type == FuncDec || node->expr_type == CallExpr){
      sym->kind = copyString("Function");
    }
    else{
      sym->kind = copyString("Variable");
    }
  
  // sym->type = node->type;
  sym->scope = scope;

  LineList line = (LineList)calloc(1, sizeof(struct LineListRec));
  line->lineno = node->lineno;
  line->next = NULL;
  sym->lines = line;
  sym->location = loc;
  scope->symbols[scope->num_symbols++] = sym;
}

int add_line(Scope scope, TreeNode* node) 
{

  for(int i=0; i<scope->num_symbols; i++) 
  {
    // found the symbol
    if (strcmp(scope->symbols[i]->name, node->name) == 0) 
    {
      LineList line = (LineList)calloc(1, sizeof(struct LineListRec));
      line->lineno = node->lineno;
      line->next = NULL;
      LineList lastLine;
      lastLine = scope->symbols[i]->lines;
      while(lastLine->next != NULL) lastLine = lastLine->next;
      lastLine->next = line;
      return 0;
    }
  }

  return -1;
}

// Insert a symbol into the current scope
Scope st_insert(Scope current_scope, TreeNode* node, int loc)
{
   // when root node is null, init the root node and add two functions at lineno 0
   if (scopeTree == NULL) {
      scopeTree = insert_scope("global", NULL);
      printf("Global scope created\n");
      current_scope = scopeTree;

      TreeNode* inputftn_node = (TreeNode*)calloc(1, sizeof(TreeNode));
      inputftn_node->lineno = 0;
      inputftn_node->name = copyString("input");
      inputftn_node->node_type = Dec;
      inputftn_node->dec_type = FuncDec;
      inputftn_node->type = Integer;

      TreeNode* outputftn_node = (TreeNode*)calloc(1, sizeof(TreeNode));
      outputftn_node->lineno = 0;
      outputftn_node->name = copyString("output");
      outputftn_node->node_type = Dec;
      outputftn_node->dec_type = FuncDec;
      outputftn_node->type = Void;

      add_new_symbol(current_scope, inputftn_node, 0);
      add_new_symbol(current_scope, outputftn_node, 0);
      printf("Input and output functions added\n");
   }

   if (node->name != NULL && strcmp(node->name, "x") == 0)
   {

   }
   // shallow copy current_scope
   Scope saved_current_scope = current_scope;
   Scope current_scope_cpy = current_scope;
   Scope scope_of_var;
   if (node->name != NULL)
    scope_of_var = check_scope(current_scope_cpy, node->name);
   else
    scope_of_var = NULL;
  
  printf("scope_of_var: %ld, name_var: %S\n", scope_of_var, node->name);
  
   if (scope_of_var != NULL)
    printf("scope_of_var: %S, name_var: %S\n", scope_of_var->name, node->name);
   
   // the symbol is not in the current scope
   if (scope_of_var == NULL)
   {
      // add undeclared error variable to the scope
      if (node->node_type == Expr)
      {
        node->type = Undeclared;
        add_new_symbol(saved_current_scope, node, loc);
      }
      // add declared variable to the scope
      else if (node->node_type == Dec)
      {
        // in case of funcdec, create a new scope
        if (node->dec_type == FuncDec)
        {
          // printf("Declaring function %s\n", node->name);
          // add scope, newScope is a child of current scope
          Scope newScope = insert_scope(node->name, current_scope_cpy);
          // add function to the parent scope
          add_new_symbol(saved_current_scope, node, loc);
          // update currentScope
          saved_current_scope = newScope;
        }
        else
        {
          if (node->dec_type == ParamDec && node->type == Void) return saved_current_scope;
          // add new symbol
          add_new_symbol(saved_current_scope, node, loc);
        }
      }
      else 
      {
        // using undeclared symbol: semantic error
        // fprintf(listing, "Error message here: using undeclared symbol\n");
        return NULL;
      }
   }
   // the symbol is in the saved_current_scope
   else
   {
      if (node->node_type == Dec)
      {
        // declaring the symbol twice: semantic error
        fprintf(listing, "Error: Symbol \"%s\" is redefined at line %d (already defined at line ", node->name, node->lineno);
       int i=0;
       Symbol sym = scope_of_var->symbols[i];
       while(sym != NULL && strcmp(sym->name, node->name) != 0) { sym = scope_of_var->symbols[++i]; }
       for (LineList line = sym->lines; line != NULL; line = line->next)
        fprintf(listing, "%d ", line->lineno);

        fprintf(listing, ")\n");
        return NULL;
      }
      else
      {
        add_line(scope_of_var, node);
      }
   }

   return saved_current_scope;
}

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */

void printScope(Scope scope, FILE* listing) {
  for (int i = 0; i < SIZE; i++) {
      Symbol sym = scope->symbols[i];
      if (sym == NULL) break;
      fprintf(listing, "%-10s\t%-10s\t%-10s\t%-10s\t%-10d\t", 
              sym->name, sym->kind, sym->type, scope->name, sym->location);
      LineList lines = sym->lines;
      while (lines != NULL) {
          fprintf(listing, "%d ", lines->lineno);
          lines = lines->next;
      }
      fprintf(listing, "\n");
  }

  for (int i = 0; i < scope->index_children; i++) {
      printScope(scope->children[i], listing);
  }
}

void printSymTab(FILE * listing){
  fprintf(listing, "Symbol Table:\n");
  fprintf(listing, "Name      \tKind      \tType      \tScopeName \tLocation  \tLine Numbers\n");
  fprintf(listing, "----------\t----------\t----------\t----------\t----------\t------------\n");
  printScope(scopeTree, listing);
}