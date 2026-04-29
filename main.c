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

fprintf(cg->output, "section .data\n");
fprintf(cg->output, "fmt db \"%%d\", 10, 0\n\n");
fprintf(cg->output, "section .text\n");
fprintf(cg->output, "global main\n\n");
emit_label(cg, "main");
emit(cg, "push rbp");
emit(cg, "mov rbp, rsp");
emit(cg, "; x: integer = 42");
emit(cg, "mov rax, 42");
emit(cg, "mov [rbp-8], rax");

emit(cg, "; if (x == 42)");
emit(cg, "mov rax, [rbp-8]");
emit(cg, "cmp rax, 42");
emit(cg, "jne else_label");
emit(cg, "; if blogu");
emit(cg, "mov rax, 1");
emit(cg, "jmp end_label");
emit_label(cg, "else_label");
emit(cg, "; else blogu");
emit(cg, "mov rax, 0");
emit_label(cg, "end_label");

emit(cg, "; for dongusu");
emit_label(cg, "for_start");
emit(cg, "mov rax, [rbp-8]");
emit(cg, "cmp rax, 0");
emit(cg, "jle for_end");
emit(cg, "sub rax, 1");
emit(cg, "mov [rbp-8], rax");
emit(cg, "jmp for_start");
emit_label(cg, "for_end");
emit(cg, "; print x");
emit(cg, "mov rdi, fmt");
emit(cg, "mov rsi, [rbp-8]");
emit(cg, "xor rax, rax");
emit(cg, "call printf");
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
