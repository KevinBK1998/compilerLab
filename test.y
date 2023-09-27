%{
//Parser to print result of an infix expression made of numbers and operators(attribute)
#include<stdio.h>
#include<stdlib.h>
%}
%token NUM

%left '+''-'
%left '*''/''%'
%left '('')'

%%
prog:	expr '\n' 	{printf("Result=%d\nBYE\n",$1);exit(1);}
	;
expr:	expr '+' expr 	{$$=$1+$3;}//{printf("+ ");}
	|expr '-' expr 	{$$=$1-$3;}//{printf("- ");}
	|expr '*' expr 	{$$=$1*$3;}//{printf("* ");}
	|expr '/' expr 	{$$=$1/$3;}//{printf("/ ");}
	|expr '%' expr 	{$$=$1%$3;}//{printf("% ");}
	|'('expr')'	{$$=$2;}
	|NUM		{$$=$1;}//{printf("%d ",$1);}
	;
%%

/*int yylex(){
	char c=getchar();
	if(isdigit(c))return NUM;
	else return c;
}*/
int yyerror(){
	printf("ERROR");
	return 1;
}

int main(){	
	yyparse();
	return 1;
}
