#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "codegen.h"

CodeGen* create_codegen(const char *filename) {
    CodeGen *cg = malloc(sizeof(CodeGen));
    cg->output = fopen(filename, "w");
    cg->label_count = 0;
    cg->temp_count = 0;
    return cg;
}

void emit(CodeGen *cg, const char *format, ...) {
    va_list args;
    va_start(args, format);
    fprintf(cg->output, "    ");
    vfprintf(cg->output, format, args);
    fprintf(cg->output, "\n");
    va_end(args);
    
    va_start(args, format);
    printf("    ");
    vprintf(format, args);
    printf("\n");
    va_end(args);
}

void emit_label(CodeGen *cg, const char *label) {
    fprintf(cg->output, "%s:\n", label);
    printf("%s:\n", label);
}

int new_label(CodeGen *cg) {
    return cg->label_count++;
}

void destroy_codegen(CodeGen *cg) {
    if (cg->output) fclose(cg->output);
    free(cg);
}

const char* reg_to_string(Register reg) {
    switch (reg) {
        case REG_RAX: return "rax";
        case REG_RBX: return "rbx";
        case REG_RCX: return "rcx";
        case REG_RDX: return "rdx";
        case REG_RSI: return "rsi";
        case REG_RDI: return "rdi";
        default:      return "unknown";
    }
}

int main() {
    printf("Code Generator basliyor...\n\n");

    CodeGen *cg = create_codegen("output.asm");

    fprintf(cg->output, "section .text\n");
    fprintf(cg->output, "global main\n\n");
    printf("section .text\n");
    printf("global main\n\n");

    emit_label(cg, "main");
    emit(cg, "push rbp");
    emit(cg, "mov rbp, rsp");

    // x: integer = 42
    emit(cg, "; x: integer = 42");
    emit(cg, "mov rax, 42");
    emit(cg, "mov [rbp-8], rax");

    // return x
    emit(cg, "; return x");
    emit(cg, "mov rax, [rbp-8]");
    emit(cg, "pop rbp");
    emit(cg, "ret");

    destroy_codegen(cg);

    printf("\nAssembly kodu 'output.asm' dosyasina yazildi!\n");
    printf("Code Generator basarili!\n");
    return 0;
}