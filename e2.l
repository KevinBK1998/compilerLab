%{
//Lexical Analyser to identify operators and string as tokens
//eg:"hello",'+',"world"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "y.tab.h"
%}

id [a-zA-Z]+
op [-+*/%]

%%
{id}	{yylval=(char*)malloc(yyleng*sizeof(char));strcpy(yylval,yytext);return ID;}
{op}	{return *yytext;}
[\n]	{return '\n';}
%%

yywrap(){
	return 1;
}
