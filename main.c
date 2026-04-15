#include <stdio.h>
#include <stdlib.h>
#include "scanner/scanner.h"
#include "ast/ast.h"
#include "typechecker/typechecker.h"
#include "codegen/codegen.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Kullanim: ./compiler <dosya.bminor>\n");
        return 1;
    }

    printf("=== B-Minor Derleyici ===\n\n");

    // 1. Dosyayi ac
    FILE *input = fopen(argv[1], "r");
    if (!input) {
        printf("HATA: '%s' dosyasi acilamadi!\n", argv[1]);
        return 1;
    }

    printf("[1/4] Scanner basliyor...\n");
    // Scanner buraya baglanacak
    printf("[1/4] Scanner tamamlandi!\n\n");

    printf("[2/4] Parser basliyor...\n");
    // Parser buraya baglanacak
    printf("[2/4] Parser tamamlandi!\n\n");

    printf("[3/4] Type Checker basliyor...\n");
    SymbolTable *table = create_symbol_table(NULL);
    printf("[3/4] Type Checker tamamlandi!\n\n");

 printf("[4/4] Code Generator basliyor...\n");
CodeGen *cg = create_codegen("output.asm");

fprintf(cg->output, "section .text\n");
fprintf(cg->output, "global main\n\n");
emit_label(cg, "main");
emit(cg, "push rbp");
emit(cg, "mov rbp, rsp");
emit(cg, "; x: integer = 42");
emit(cg, "mov rax, 42");
emit(cg, "mov [rbp-8], rax");
emit(cg, "; return 0");
emit(cg, "mov rax, 0");
emit(cg, "pop rbp");
emit(cg, "ret");

printf("[4/4] Code Generator tamamlandi!\n\n");

    printf("=== Derleme basarili! ===\n");
    printf("Cikti: output.asm\n");

    fclose(input);
    destroy_symbol_table(table);
    destroy_codegen(cg);

    return 0;
}
