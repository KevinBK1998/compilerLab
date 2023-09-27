%{
//Lexical Analyser to count integers,floating point numbers
#include<stdio.h>
int i,f;
%}

digit [0-9]

%%
{digit}+ {i++;}
[.] {}
{digit}*[.]{digit}* {f++;}

%%

int yywrap(){
	return 1;
}

int main(){
	i=f=0;
	yylex();
	printf("Integers:%d\nFloating Point:%d\n",i,f);
	return 1;
}
