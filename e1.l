%{
//Lexical Analyser to identify single letters as identifiers and operators
//eg:'a','+','b'
#include<stdio.h>
#include "y.tab.h"
%}

id [a-zA-Z]
op [-+*/%]

%%
{id}	{yylval=*yytext;return ID;}
{op}	{return *yytext;}
[\n]	{return '\n';}
%%

yywrap(){
	return 1;
}

