#ifndef CODEGEN_H
#define CODEGEN_H

#include <stdio.h>

typedef enum {
    REG_RAX,
    REG_RBX,
    REG_RCX,
    REG_RDX,
    REG_RSI,
    REG_RDI
} Register;

typedef struct {
    FILE *output;
    int label_count;
    int temp_count;
} CodeGen;

CodeGen* create_codegen(const char *filename);
void emit(CodeGen *cg, const char *format, ...);
void emit_label(CodeGen *cg, const char *label);
int new_label(CodeGen *cg);
void destroy_codegen(CodeGen *cg);
const char* reg_to_string(Register reg);

#endif

