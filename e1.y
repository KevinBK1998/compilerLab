%{
//Parser to identify if statement and show nesting levels
#include<stdio.h>
#include<stdlib.h>
int pos=0;
%}

%token DIGIT
%left '<'
%left '('')'

%%
PRG:STAT'\n'{exit(1);}
	;
STAT:IF '(' COND ')' STAT{printf("NEST %d ",++pos);}
	|EXP';'
;
IF:'i''f';
COND:EXP '<'EXP
;
EXP:|EXP '<'EXP
	|DIGIT;
%%

int yylex()
{
	int c;
	c = getchar();
	if(isdigit(c))
		return DIGIT;
	else
		return c;
}
int yyerror(){
	printf("-error-");
	return 1;
}
int main(){
	yyparse();
	return 1;
}

