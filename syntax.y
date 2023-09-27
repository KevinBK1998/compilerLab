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
#include<stdlib.h>
#include "exptree.h"
#include "exptree.c"
#include "asmb.c"
extern FILE* yyin;
%}

%union{
    struct tnode *node;
}

%type <node> exp inp opt asg whilestm ifstm ctrl stm cont brk uncnd stms code
%token <node> NUM ID
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE BEG READ WRITE END LINE
%right '='
%left '+' '-'
%left '*' '/' '%'
%left '>'
%left '<'
%left '(' ')'
%left '{''}'

%%
prg:code LINE          {return codeAsmble($1);}
    |code              {return codeAsmble($1);}
    ;
code:begin stms END ';' {$$=$2;}
    |begin brk END ';' {$$=$2;}
    |begin cont END ';' {$$=$2;}
    |begin END ';'       
    ;
begin:BEG LINE
    |BEG
    ;
stms:stms stm {$$=makeConNode($1,$2);}
    |stm        {$$=$1;}
    ;
uncnd:brk   {$$=$1;}
    |cont   {$$=$1;}
    ;
brk:stms BREAK ';' LINE stms {$$=makeUNode($1,$5,BREAK_LOOP);}
    |BREAK ';'LINE stms {$$=makeUNode(NULL,$4,BREAK_LOOP);}
    |stms BREAK ';' LINE {$$=makeUNode($1,NULL,BREAK_LOOP);}
    |BREAK ';' LINE {$$=makeUNode(NULL,NULL,BREAK_LOOP);}
    ;
cont:stms CONTINUE';' LINE stms {$$=makeUNode($1,$5,CONT_LOOP);}
    |CONTINUE ';'LINE stms {$$=makeUNode(NULL,$4,CONT_LOOP);}
    |stms CONTINUE ';' LINE {$$=makeUNode($1,NULL,CONT_LOOP);}
    |CONTINUE ';' LINE {$$=makeUNode(NULL,NULL,CONT_LOOP);}
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
ifstm:IF '('exp')' THEN stms ELSE stms  ENDIF ';'             {$$=makeCtrlNode($3,$6,$8,IF_ELSE);}
    |IF '('exp')' THEN LINE stms ELSE stms  ENDIF ';'         {$$=makeCtrlNode($3,$7,$9,IF_ELSE);}
    |IF '('exp')' THEN LINE stms ELSE LINE stms  ENDIF ';'    {$$=makeCtrlNode($3,$7,$10,IF_ELSE);}
    |IF '('exp')' THEN stms  ENDIF ';'                         {$$=makeCtrlNode($3,$6,NULL,SIMPLE_IF);}
    |IF '('exp')' THEN LINE stms ENDIF ';'                     {$$=makeCtrlNode($3,$7,NULL,SIMPLE_IF);}
    |IF '('exp')' THEN uncnd ENDIF ';'                         {$$=makeCtrlNode($3,$6,NULL,SIMPLE_IF);}   
    |IF '('exp')' THEN LINE uncnd ENDIF ';'                     {$$=makeCtrlNode($3,$7,NULL,SIMPLE_IF);}    
    |IF '('exp')' THEN stms ELSE uncnd ENDIF ';'             {$$=makeCtrlNode($3,$6,$8,IF_ELSE);}
    |IF '('exp')' THEN LINE stms ELSE uncnd ENDIF ';'         {$$=makeCtrlNode($3,$7,$9,IF_ELSE);}
    |IF '('exp')' THEN LINE stms ELSE LINE uncnd ENDIF ';'    {$$=makeCtrlNode($3,$7,$10,IF_ELSE);}        
    |IF '('exp')' THEN uncnd ELSE stms  ENDIF ';'             {$$=makeCtrlNode($3,$6,$8,IF_ELSE);}
    |IF '('exp')' THEN LINE uncnd ELSE stms  ENDIF ';'         {$$=makeCtrlNode($3,$7,$9,IF_ELSE);}
    |IF '('exp')' THEN LINE uncnd ELSE LINE stms  ENDIF ';'    {$$=makeCtrlNode($3,$7,$10,IF_ELSE);}        
    |IF '('exp')' THEN uncnd ELSE uncnd ENDIF ';'             {$$=makeCtrlNode($3,$6,$8,IF_ELSE);}
    |IF '('exp')' THEN LINE uncnd ELSE uncnd ENDIF ';'         {$$=makeCtrlNode($3,$7,$9,IF_ELSE);}
    |IF '('exp')' THEN LINE uncnd ELSE LINE uncnd ENDIF ';'    {$$=makeCtrlNode($3,$7,$10,IF_ELSE);}
    ;
whilestm:WHILE '('exp')' DO stms ENDWHILE ';'   {$$=makeCtrlNode($3,$6,NULL,WHILE_LOOP);}
    |WHILE '('exp')' DO LINE stms  ENDWHILE ';'  {$$=makeCtrlNode($3,$7,NULL,WHILE_LOOP);}
    |WHILE '('exp')' DO uncnd ENDWHILE ';'   {$$=makeCtrlNode($3,$6,NULL,WHILE_LOOP);}
    |WHILE '('exp')' DO LINE uncnd  ENDWHILE ';'  {$$=makeCtrlNode($3,$7,NULL,WHILE_LOOP);}
    ;
inp:READ '(' ID ')' ';'     {$$=makeFnNode(FN_READ,$3);}
    ;
opt:WRITE '(' exp ')' ';'   {$$=makeFnNode(FN_WRITE,$3);}
    ;
asg:ID '=' exp ';' {$$=makeOpNode('=',$1,$3,INTEGER);}
    ;
exp:exp '+' exp     {$$=makeOpNode('+',$1,$3,INTEGER);}
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

int main(int argc,int *argv[]){
    yyin=fopen((char *)argv[1],"r");
    return yyparse();
}

