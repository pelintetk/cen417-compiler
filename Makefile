CC = gcc
FLEX = flex
BISON = bison

all: compiler

compiler: main.c ast/ast.c typechecker/typechecker.c codegen/codegen.c
	$(CC) main.c ast/ast.c typechecker/typechecker.c codegen/codegen.c -o compiler

parser: parser/parser.y
	$(BISON) -d parser/parser.y -o parser/parser.tab.c

scanner: scanner/scanner.l
	$(FLEX) -o scanner/lex.yy.c scanner/scanner.l

clean:
	rm -f compiler output.asm *.o

test:
	bash tests/run_tests.sh

.PHONY: all clean test