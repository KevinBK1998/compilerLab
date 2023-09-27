%{
//Parser to print prefix of an infix expression made of strings and operators
//eg:hello+world
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define YYSTYPE char*
%}

%token ID
%left '+''-'
%left '*''/''%'
%left '('')'

%%
prg:expr'\n'	{printf("%s\nBYE\n",$1);free($$);}
	;
expr:expr'+'expr	{char *p=(char*)malloc((strlen($1)+strlen($3)+4)*sizeof(char));strcat(p,"+ ");strcat(p,$1);strcat(p," ");strcat(p,$3);strcat(p," ");$$=strdup(p);free(p);}
	|expr'-'expr	{char *p=(char*)malloc((strlen($1)+strlen($3)+4)*sizeof(char));strcat(p,"- ");strcat(p,$1);strcat(p," ");strcat(p,$3);strcat(p," ");$$=strdup(p);free(p);}
	|expr'*'expr	{char *p=(char*)malloc((strlen($1)+strlen($3)+4)*sizeof(char));strcat(p,"* ");strcat(p,$1);strcat(p," ");strcat(p,$3);strcat(p," ");$$=strdup(p);free(p);}
	|expr'/'expr	{char *p=(char*)malloc((strlen($1)+strlen($3)+4)*sizeof(char));strcat(p,"/ ");strcat(p,$1);strcat(p," ");strcat(p,$3);strcat(p," ");$$=strdup(p);free(p);}
	|expr'%'expr	{char *p=(char*)malloc((strlen($1)+strlen($3)+4)*sizeof(char));strcat(p,"%% ");strcat(p,$1);strcat(p," ");strcat(p,$3);strcat(p," ");$$=strdup(p);free(p);}
	|'('expr')'		{strcpy($$,$2);}
	|ID						{strcpy($$,$1);}
	;
%%

yyerror(){
	printf("ERROR ");
}
int main(){
	yyparse();
	return 1;
}
