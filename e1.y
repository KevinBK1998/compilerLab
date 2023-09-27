%{
/*Parser to identify syntax 
eg:begin
    read(a);
    read(b);
    d=a+2*b;
    write(a+d);
   end;
*/
#include<stdio.h> 
#include "exptree.c"
#define YYSTYPE tnode*
%}

%token NUM ID PLUS MUL EQU BEG READ WRITE END LINE BOP BCL SCLN
%left EQU
%left PLUS
%left MUL
%left BOP BCL

%%
prg:code LINE          {printf("Tree Created\n");}
;
code:begin block END SCLN {$$=$2;}
    |begin END SCLN       {printf("Empty\n");}
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

yyerror(char *err){
   	printf("ERROR:%s\n",err);
}
int main(){
    yyparse();
   	return 1;
}

