%{
//Parser to print postfix of an infix expression made of operators and single letters
//eg:a+b
#include<stdio.h>
#include<stdlib.h>
#define YYSTYPE char
%}

%token ID
%left '+''-'
%left '*''/''%'
%left '('')'

%%
prg:	expr'\n'	{printf("\nBYE\n");}
	;
expr:	expr'+'expr	{printf("+");}
	|expr'-'expr	{printf("-");}
	|expr'*'expr	{printf("*");}
	|expr'/'expr	{printf("/");}
	|expr'%'expr	{printf("%%");}
	|'('expr')'
	|ID		{printf("%c",$1);}
	;
%%

yyerror(){
	printf("ERROR ");
}
int main(){
	yyparse();
	return 1;
}

