/****************************************************/
/* File: symtab.h                                   */
/* Symbol table interface for the TINY compiler     */
/* (allows only one symbol table)                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _SYMTAB_H_
#define _SYMTAB_H_

#define SIZE 211
#define SHIFT 4
#define MAX_CHILDREN 100
#define MAX_NAME_LENGTH 100

#include "globals.h"
#include "util.h"

typedef struct LineListRec {
    int lineno;
    struct LineListRec* next;
} * LineList;

typedef struct Symbol {
    char* name;
    char* kind;
    char* type;
    struct Scope* scope;
    LineList lines;
    int location;
} * Symbol;

typedef struct Scope {
    char* name;
    int nest_level;
    Symbol symbols[SIZE];
    int num_symbols;
    struct Scope* children[MAX_CHILDREN];
    int index_children;
    struct Scope* parent;
} * Scope;

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */

Scope st_insert(Scope current_scope, TreeNode* node, int loc);

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup (Scope scope, TreeNode* node);

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing);

#endif
