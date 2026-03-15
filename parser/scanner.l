%{
#include "parser.tab.h"
%}

%%

[ \t\n\r]       { /* boşlukları atla */ }

"integer"       { return INTEGER; }
"boolean"       { return BOOLEAN; }
"char"          { return CHAR; }
"string"        { return STRING; }
"if"            { return IF; }
"else"          { return ELSE; }
"for"           { return FOR; }
"return"        { return RETURN; }
"print"         { return PRINT; }
"true"          { return TRUE; }
"false"         { return FALSE; }
"void"          { return VOID; }
"function"      { return FUNCTION; }
"while"         { return WHILE; }

[0-9]+                  { return INTEGER_LITERAL; }
[a-zA-Z_][a-zA-Z0-9_]* { return IDENTIFIER; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return STAR; }
"/"             { return SLASH; }
"=="            { return EQ; }
"!="            { return NEQ; }
"<="            { return LEQ; }
">="            { return GEQ; }
"<"             { return LT; }
">"             { return GT; }
"="             { return ASSIGN; }
";"             { return SEMICOLON; }
":"             { return COLON; }
","             { return COMMA; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }

.               { /* bilinmeyen karakteri atla */ }

%%

int yywrap() { return 1; }