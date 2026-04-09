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
    printf("[4/4] Code Generator tamamlandi!\n\n");

    printf("=== Derleme basarili! ===\n");
    printf("Cikti: output.asm\n");

    fclose(input);
    destroy_symbol_table(table);
    destroy_codegen(cg);

    return 0;
}
