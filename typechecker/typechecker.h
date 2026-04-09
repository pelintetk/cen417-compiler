#ifndef TYPECHECKER_H
#define TYPECHECKER_H

typedef enum {
    TYPE_INTEGER,
    TYPE_BOOLEAN,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_VOID,
    TYPE_UNKNOWN
} DataType;

typedef struct Symbol {
    char *name;
    DataType type;
    struct Symbol *next;
} Symbol;

typedef struct SymbolTable {
    Symbol *head;
    struct SymbolTable *parent;
} SymbolTable;

SymbolTable* create_symbol_table(SymbolTable *parent);
void add_symbol(SymbolTable *table, char *name, DataType type);
Symbol* lookup_symbol(SymbolTable *table, char *name);
void destroy_symbol_table(SymbolTable *table);
const char* type_to_string(DataType type);

#endif