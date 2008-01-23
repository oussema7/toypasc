#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "base.h"

typedef struct _symbol {
    char *name;
    Type type;
    Value value;
    int decl_linenum;
    int params;
    bool is_procfunc;
    bool is_global;
    Type *param_types;
    struct _symbol *next;
} Symbol;

static Symbol *global_symbol_table;

Symbol *symbol_new(char const * name);
Symbol *symbol_lookup(Symbol *symtab, char const *name);
Symbol *symbol_insert(Symbol *symtab, Symbol *symbol);

void symbol_table_destroy(Symbol *table);
void symbol_table_dump(Symbol *table);
void symbol_print(Symbol *symbol);

#endif // SYMBOL_TABLE_H