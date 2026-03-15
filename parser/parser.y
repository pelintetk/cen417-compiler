%{
#include <stdio.h>
#include <stdlib.h>
#include "token.h"

void yyerror(const char *s);
int yylex();
%}

%token INTEGER BOOLEAN CHAR STRING
%token IF ELSE FOR RETURN PRINT
%token TRUE FALSE VOID FUNCTION WHILE
%token IDENTIFIER INTEGER_LITERAL
%token PLUS MINUS STAR SLASH
%token ASSIGN EQ NEQ LT GT LEQ GEQ
%token SEMICOLON COLON COMMA
%token LPAREN RPAREN LBRACE RBRACE

%%

program:
    decl_list
    ;

decl_list:
    decl_list decl
    | decl
    ;

decl:
    var_decl
    | func_decl
    ;

var_decl:
    IDENTIFIER COLON type SEMICOLON
    | IDENTIFIER COLON type ASSIGN expr SEMICOLON
    ;

type:
    INTEGER
    | BOOLEAN
    | CHAR
    | STRING
    | VOID
    ;

func_decl:
    IDENTIFIER COLON FUNCTION type LPAREN param_list RPAREN ASSIGN LBRACE stmt_list RBRACE
    ;

param_list:
    /* boş */
    | param
    | param_list COMMA param
    ;

param:
    IDENTIFIER COLON type
    ;

stmt_list:
    /* boş */
    | stmt_list stmt
    ;

stmt:
    var_decl
    | expr SEMICOLON
    | RETURN expr SEMICOLON
    | PRINT expr SEMICOLON
    | IF LPAREN expr RPAREN LBRACE stmt_list RBRACE
    | IF LPAREN expr RPAREN LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE
    | FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN LBRACE stmt_list RBRACE
    ;

expr:
    expr PLUS expr
    | expr MINUS expr
    | expr STAR expr
    | expr SLASH expr
    | expr EQ expr
    | expr NEQ expr
    | expr LT expr
    | expr GT expr
    | expr LEQ expr
    | expr GEQ expr
    | expr ASSIGN expr
    | IDENTIFIER
    | INTEGER_LITERAL
    | TRUE
    | FALSE
    | LPAREN expr RPAREN
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parse hatasi: %s\n", s);
}

int main() {
    printf("Parser basliyor...\n");
    yyparse();
    printf("Parse basarili!\n");
    return 0;
}