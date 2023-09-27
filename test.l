%{
//Lexical Analyser to identify operators,newline and numbers as tokens
#include<stdio.h>
#include "y.tab.h"
%}

digit [0-9]
oper [-+()*/%]|[\n]

%%
{digit}+	{yylval=atoi(yytext);return NUM;}
{oper}		{return *yytext;}
%%

int yywrap(){
	return 1;
}
/*int main(){
yylex();
return 1;
}*/
