%{
/*Parser to identify syntax 
eg:begin
    read(a);
    read(b);
    d=a+2*b;
    write(a+d);
   end;
   (uses predefiined variables)
*/
#include<stdio.h> 
#include "exptree.c"
#include "asmb.c"
#define YYSTYPE tnode*

%}

%token NUM ID PLUS MUL EQU BEG READ WRITE END LINE BOP BCL SCLN
%left EQU
%left PLUS
%left MUL
%left BOP BCL

%%
prg:code LINE          {printf("Compiled Successfully\n");return $1;}
    |code          {printf("Compiled Successfully\n");return $1;}
;
code:begin block END SCLN {$$=$2;}
    |begin END SCLN       
    ;
begin:BEG LINE
    |BEG
    ;
block:block stm {$$=makeConNode($1,$2);}
    |stm        {$$=$1;}
    ;
stm:stm LINE    {$$=$1;}
    |inp        {$$=$1;}
    |opt        {$$=$1;}
    |asg        {$$=$1;}
    ;
inp:READ BOP ID BCL SCLN     {$$=makeFnNode(1,$3);}
    ;
opt:WRITE BOP exp BCL SCLN   {$$=makeFnNode(0,$3);}
    ;
asg:ID EQU exp SCLN {$$=makeOpNode('=',$1,$3);}
    ;
exp:exp PLUS exp    {$$=makeOpNode('+',$1,$3);}
    |exp MUL exp    {$$=makeOpNode('*',$1,$3);}
    |BOP exp BCL      {$$=$2;}
    |ID             {$$=$1;}
    |NUM            {$$=$1;}
    ;
%%
extern FILE * yyin;
yyerror(char *err){
   	printf("ERROR:%s\n",err);
    exit(1);
}
int main(int argc,char*argv[]){
    yyin=fopen(argv[1],"r");
    codeAsmble(yyparse());
   	return 1;
}

