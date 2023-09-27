%{
//Parser to identify syntax and convert into '.xexe' format
#include<stdio.h>
#include<stdlib.h>
#include "exptree.c"
#include "asmb.c"
#define YYSTYPE tnode*
%}

%token NUM PLUS MIN MUL DIV MOD BOP BCL
%left PLUS MIN
%left MUL DIV MOD
%left BOP BCL

%%
prg:expr'\n'        {printf("Compiled Successfully\n");return $$;}
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
    codeAsmble(yyparse());
    printf("Created executable\n");
    exit(1);
}
