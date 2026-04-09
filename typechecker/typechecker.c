#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typechecker.h"

SymbolTable* create_symbol_table(SymbolTable *parent) {
    SymbolTable *table = malloc(sizeof(SymbolTable));
    table->head = NULL;
    table->parent = parent;
    return table;
}

void add_symbol(SymbolTable *table, char *name, DataType type) {
    Symbol *sym = malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->type = type;
    sym->next = table->head;
    table->head = sym;
}

Symbol* lookup_symbol(SymbolTable *table, char *name) {
    if (!table) return NULL;
    Symbol *sym = table->head;
    while (sym) {
        if (strcmp(sym->name, name) == 0) return sym;
        sym = sym->next;
    }
    return lookup_symbol(table->parent, name);
}

void destroy_symbol_table(SymbolTable *table) {
    if (!table) return;
    Symbol *sym = table->head;
    while (sym) {
        Symbol *next = sym->next;
        free(sym->name);
        free(sym);
        sym = next;
    }
    free(table);
}

const char* type_to_string(DataType type) {
    switch (type) {
        case TYPE_INTEGER: return "integer";
        case TYPE_BOOLEAN: return "boolean";
        case TYPE_CHAR:    return "char";
        case TYPE_STRING:  return "string";
        case TYPE_VOID:    return "void";
        default:           return "unknown";
    }
}
