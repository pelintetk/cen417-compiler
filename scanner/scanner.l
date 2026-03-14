%{
#include <stdio.h>
%}

%%

[ \t\n\r]       { /* boşlukları atla */ }

"integer"       { printf("KEYWORD: %s\n", yytext); }
"boolean"       { printf("KEYWORD: %s\n", yytext); }
"char"          { printf("KEYWORD: %s\n", yytext); }
"string"        { printf("KEYWORD: %s\n", yytext); }
"if"            { printf("KEYWORD: %s\n", yytext); }
"else"          { printf("KEYWORD: %s\n", yytext); }
"for"           { printf("KEYWORD: %s\n", yytext); }
"return"        { printf("KEYWORD: %s\n", yytext); }
"print"         { printf("KEYWORD: %s\n", yytext); }
"true"          { printf("KEYWORD: %s\n", yytext); }
"false"         { printf("KEYWORD: %s\n", yytext); }
"void"          { printf("KEYWORD: %s\n", yytext); }
"function"      { printf("KEYWORD: %s\n", yytext); }
"while"         { printf("KEYWORD: %s\n", yytext); }

[0-9]+          { printf("INTEGER: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*  { printf("IDENTIFIER: %s\n", yytext); }

"+"             { printf("OP: +\n"); }
"-"             { printf("OP: -\n"); }
"*"             { printf("OP: *\n"); }
"/"             { printf("OP: /\n"); }
"="             { printf("OP: =\n"); }
"=="            { printf("OP: ==\n"); }
"!="            { printf("OP: !=\n"); }
"<"             { printf("OP: <\n"); }
">"             { printf("OP: >\n"); }
"<="            { printf("OP: <=\n"); }
">="            { printf("OP: >=\n"); }
";"             { printf("PUNCT: ;\n"); }
":"             { printf("PUNCT: :\n"); }
","             { printf("PUNCT: ,\n"); }
"("             { printf("PUNCT: (\n"); }
")"             { printf("PUNCT: )\n"); }
"{"             { printf("PUNCT: {\n"); }
"}"             { printf("PUNCT: }\n"); }

.               { printf("UNKNOWN: %s\n", yytext); }

%%

int yywrap() { return 1; }

int main() {
    yylex();
    return 0;
}