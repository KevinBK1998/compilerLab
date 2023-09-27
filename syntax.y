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
//#include "evaluate.c"
#include "asmb.c"
#define YYSTYPE tnode*
%}

%token NUM ID IF THEN ELSE ENDIF WHILE DO ENDWHILE BEG READ WRITE END LINE
%left '=''{''}'
%left '>'
%left '<'
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
prg:code LINE          {printf("Compiled Successfully\n");return $1;}
    ;
code:begin stms END ';' {$$=$2;}
    |begin END ';'       
    ;
begin:BEG LINE
    |BEG
    ;
stms:stms stm {$$=makeConNode($1,$2);}
    |stm        {$$=$1;}
    ;
block:'{' LINE stms'}'LINE{$$=$3;}
    |'{' LINE stms'}'{$$=$3;}
    |'{'stms'}'{$$=$2;}
    |stm   {$$=$1;}
    ;
stm:stm LINE    {$$=$1;}
    |ctrl       {$$=$1;}
    |inp        {$$=$1;}
    |opt        {$$=$1;}
    |asg        {$$=$1;}
    ;
ctrl:ifstm      {$$=$1;}
    |whilestm   {$$=$1;}
    ;
ifstm:IF '('exp')' THEN block ELSE block  ENDIF ';'             {$$=makeCtrlNode($3,$6,$8,IF_ELSE);}
    |IF '('exp')' THEN LINE block ELSE block  ENDIF ';'         {$$=makeCtrlNode($3,$7,$9,IF_ELSE);}
    |IF '('exp')' THEN LINE block ELSE LINE block  ENDIF ';'    {$$=makeCtrlNode($3,$7,$10,IF_ELSE);}
    |IF '('exp')' THEN block  ENDIF ';'                         {$$=makeCtrlNode($3,$6,NULL,SIMPLE_IF);}
    |IF '('exp')' THEN LINE block ENDIF ';'                     {$$=makeCtrlNode($3,$7,NULL,SIMPLE_IF);}
    ;
whilestm:WHILE '('exp')' DO block  ENDWHILE ';'   {$$=makeCtrlNode($3,$6,NULL,WHILE_LOOP);}
    |WHILE '('exp')' DO LINE block  ENDWHILE ';'  {$$=makeCtrlNode($3,$7,NULL,WHILE_LOOP);}
    ;
inp:READ '(' ID ')' ';'     {$$=makeFnNode(FN_READ,$3);}
    ;
opt:WRITE '(' exp ')' ';'   {$$=makeFnNode(FN_WRITE,$3);}
    ;
asg:ID '=' exp ';' {$$=makeOpNode('=',$1,$3,INTEGER);}
    ;
exp:exp '+' exp    {$$=makeOpNode('+',$1,$3,INTEGER);}
    |exp '-' exp    {$$=makeOpNode('-',$1,$3,INTEGER);}
    |exp '*' exp    {$$=makeOpNode('*',$1,$3,INTEGER);}
    |exp '/' exp    {$$=makeOpNode('/',$1,$3,INTEGER);}
    |exp '%' exp    {$$=makeOpNode('%',$1,$3,INTEGER);}
    |exp '<' exp    {$$=makeOpNode('<',$1,$3,BOOLEAN);}
    |exp '>' exp    {$$=makeOpNode('>',$1,$3,BOOLEAN);}
    |'(' exp ')'    {$$=$2;}
    |ID             {$$=$1;}
    |NUM            {$$=$1;}
    ;
%%

yyerror(char *err){
   	printf("ERROR:%s\n",err);
    exit(1);
}
int main(){
    printf("Start Coding:\n");
    codeAsmble(yyparse());
   	return 1;
}

