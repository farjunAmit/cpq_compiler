%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"
%}

LETTER [a-zA-z]
DIGIT[0-9]
WHITESPACE [ \t\r]
%x STAR_COMMENT
%option noyywrap
%option yylineno
%%
"/*" {BEGIN(STAR_COMMENT);}
<STAR_COMMENT>{
[^*\n]+ 
\n 
"*"
"*/" {BEGIN(0);}
}
"case" {return CASE;}
"default" {return DEFAULT;}
"else" {return ELSE;}
"float" {return FLOAT;}
"if" {return IF;}
"input" {return INPUT;}
"int" {return INT;}
"output" {return OUTPUT;}
"while" {return WHILE;}
"==" {yylval.compraisonOpp = EQUAL; return RELOP;}
"!=" {yylval.compraisonOpp = NOTEQUAL; return RELOP;}
"<"  {yylval.compraisonOpp = SMALL; return RELOP;}
">"  {yylval.compraisonOpp = BIG; return RELOP;}
">=" {yylval.compraisonOpp = BEQUAL; return RELOP;}
"<=" {yylval.compraisonOpp = SEQUAL; return RELOP;}
"("|")"|"{"|"}"|","|":"|";"|"=" {return yytext[0];}
"+" {yylval.modifierOpp = PLUS; return ADDOP;}
"-" {yylval.modifierOpp = MINUS; return ADDOP;}
"*" {yylval.modifierOpp = MUL; return MULOP;}
"/" {yylval.modifierOpp = DIV; return MULOP;}
"||" {return OR;}
"&&" {return AND;}
"!" {return NOT;}
"static_cast<int>" {yylval.tval = INTTYPE; return CAST;}
"static_cast<float>" {yylval.tval = FLOATTYPE; return CAST;}
{LETTER}({LETTER}|{DIGIT})* {yylval.variable = (char *) malloc(sizeof(char)*(yyleng+1)); strcpy(yylval.variable,yytext); return ID;}
{DIGIT}+ {yylval.variable = (char *) malloc(sizeof(char)*(yyleng+1)); strcpy(yylval.variable,yytext); return NUM;}
{DIGIT}+"."{DIGIT}* {yylval.variable = (char *) malloc(sizeof(char)*(yyleng+1)); strcpy(yylval.variable,yytext); return NUM;}
({WHITESPACE}+)
[\n] 
{DIGIT}+([^:;,(){}=!<>*+'-'/&\t\r' ''])+ {fprintf (stderr, "line %d: unrecognized token %s\n", 
                               yylineno, yytext);}
. {fprintf (stderr, "line %d: unrecognized token %c\n", 
                               yylineno, yytext[0]);}

%%
