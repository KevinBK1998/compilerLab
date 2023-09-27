%{
//Parser to identify syntax and evaluate,convert into postfix and prefix
#include<stdio.h>
#include<stdlib.h>
#include "exptree.c"
#define YYSTYPE tnode*
%}

%token NUM PLUS MIN MUL DIV MOD BOP BCL
%left PLUS MIN
%left MUL DIV MOD
%left BOP BCL

%%
prg:expr'\n'        {printf("Result:%d\nPostfix:%s\nPrefix:%s\n",eval($1),pst($1),pre($1));exit(1);}
    ;
expr:expr PLUS expr {$$=makeOpNode('+',$1,$3);}
    |expr MIN expr	{$$=makeOpNode('-',$1,$3);}
    |expr MUL expr	{$$=makeOpNode('*',$1,$3);}
    |expr DIV expr	{$$=makeOpNode('/',$1,$3);}
    |expr MOD expr	{$$=makeOpNode('%',$1,$3);}
    |BOP expr BCL		{$$=$2;}
    |NUM			{$$=$1;}
    ;
%%

yyerror(char *err){
   	printf("ERROR:%s\n",err);
}
int main(){
    yyparse();
   	return 1;
}
