%{
//Lexical Analyser to identify numbers,identifiers,operators,keywords
#include<stdio.h>
#include "y.tab.h"
int opDec(char);
%}

num [0-9]+
op [*+()=;]
id [a-z]
beg [b][e][g][i][n]
read [r][e][a][d]
write [w][r][i][t][e]
end [e][n][d]

%%
{num}   {int i=atoi(yytext);yylval=makeNumNode(i);return NUM;}
{op}    {return opDec(*yytext);}
{id}    {char c=*yytext;yylval=makeIdNode(c);return ID;}
{beg}   {return BEG;}
{read}  {return READ;}
{write} {return WRITE;}
{end}   {return END;}
[\n]    {return LINE;}
. {}
%%

int opDec(char c){
	switch(c){
		case '+':return PLUS;
        case '*':return MUL;
        case '=':return EQU;
        case '(':return BOP;
        case ')':return BCL;
        case ';':return SCLN;
	}
}
yywrap(){
    return 1;
}