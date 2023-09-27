%{
//Parser to identify prefix form syntax and convert to '.xexe' format
#include<stdio.h>
#include<stdlib.h>
#include "exptree.c"
#include "asmb.c"
#define YYSTYPE tnode*
%}

%token NUM PLUS MIN MUL DIV MOD
%left PLUS MIN MUL DIV MOD

%%
prg:expr'\n'        {printf("Compiled Successfully\n");return $$;}
    ;
expr:PLUS expr expr {$$=makeOpNode('+',$2,$3);}
    |MIN expr expr	{$$=makeOpNode('-',$2,$3);}
    |MUL expr expr	{$$=makeOpNode('*',$2,$3);}
    |DIV expr expr	{$$=makeOpNode('/',$2,$3);}
    |MOD expr  expr	{$$=makeOpNode('%',$2,$3);}
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
