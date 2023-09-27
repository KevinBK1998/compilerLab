%{
//Lexical Analyser to identify operators and numbers as tokens and create nodes
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
int opDec(char);
%}

num [0-9]+
op [-+*/%()]

%%
{num}	{int p=atoi(yytext);yylval=makeLfNode(p);return NUM;}
{op}	{return opDec(*yytext);}
[\n]	{return '\n';}
.		{yyerror("Unknown Character");}
%%

opDec(char c){
	switch(c){
		case '+':return PLUS;
		case '-':return MIN;
		case '*':return MUL;
		case '/':return DIV;
		case '%':return MOD;
		case '(':return BOP;
		case ')':return BCL;
	}
}
yywrap(){
	return 1;
}
