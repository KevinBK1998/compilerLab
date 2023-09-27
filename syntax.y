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

%type <node> exp inp opt asg whilestm ifstm ctrl stm cont brk uncnd stms type vlist cond id dcl mdcl Declare code
%token <node> NUM ID STR
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE BEG READ WRITE END
%token REPEAT UNTIL INCRMNT 
%token DECL INT_TYPE STR_TYPE ENDDECL DECRMNT
%left ','
%right '='
%left OR
%left AND
%left EQTO NTEQ
%left '>' GTEQ
%left '<' LSEQ
%left '+' '-'
%left '*' '/' '%'
%right NOT
%left '['']'
%left '(' ')'
%left '{''}'

%%
prg:code              {return 0;}
    ;
code:Declare
    |main
    |Declare main
    ;
main:BEG stms END ';' {codeAsmble($2);}
    |BEG brk END ';'  {codeAsmble($2);}
    |BEG cont END ';' {codeAsmble($2);}
    |BEG END ';'     
    ;
stms:stms stm {$$=makeConNode($1,$2);}
    |stm        {$$=$1;}
    ;
uncnd:brk   {$$=$1;}
    |cont   {$$=$1;}
    ;
brk:stms BREAK ';'  stms {$$=makeUNode($1,$4,BREAK_LOOP);}
    |BREAK ';' stms {$$=makeUNode(NULL,$3,BREAK_LOOP);}
    |stms BREAK ';'  {$$=makeUNode($1,NULL,BREAK_LOOP);}
    |BREAK ';'  {$$=makeUNode(NULL,NULL,BREAK_LOOP);}
    ;
cont:stms CONTINUE';'  stms {$$=makeUNode($1,$4,CONT_LOOP);}
    |CONTINUE ';' stms {$$=makeUNode(NULL,$3,CONT_LOOP);}
    |stms CONTINUE ';'  {$$=makeUNode($1,NULL,CONT_LOOP);}
    |CONTINUE ';'  {$$=makeUNode(NULL,NULL,CONT_LOOP);}
    ;
stm:ctrl        {$$=$1;}
    |inp        {$$=$1;}
    |opt        {$$=$1;}
    |asg        {$$=$1;}
    ;
Declare:DECL mdcl ENDDECL {$$=$2;}
    ;
mdcl:mdcl dcl  {$$=$2;}
    |dcl {$$=$1;}
    ;
type:INT_TYPE   {$$=makeDtype(INTEGER);}
    |STR_TYPE   {$$=makeDtype(STRING);}
    ;
dcl:type vlist ';'{$$=$1;Declare($1,$2);}
    ;
vlist:vlist ',' ID '['NUM']''['NUM']'   {$$=makeArrNode($1,$3,$5,$8);}
    |vlist ',' ID '['NUM']'             {$$=makeArrNode($1,$3,$5,NULL);}
    |vlist ',' ID                       {$$=makeArrNode($1,$3,NULL,NULL);}
    |ID '['NUM']' '['NUM']'             {$$=makeArrNode(NULL,$1,$3,$6);}
    |ID '['NUM']'                       {$$=makeArrNode(NULL,$1,$3,NULL);}
    |ID                                 {$$=makeArrNode(NULL,$1,NULL,NULL);}
    ;
ctrl:ifstm      {$$=$1;}
    |whilestm   {$$=$1;}
    ;
ifstm:IF cond THEN stms ELSE stms  ENDIF ';'             {$$=makeCtrlNode($2,$4,$6,IF_ELSE);}
    |IF cond THEN stms  ENDIF ';'                        {$$=makeCtrlNode($2,$4,NULL,SIMPLE_IF);}
    |IF cond THEN uncnd ENDIF ';'                        {$$=makeCtrlNode($2,$4,NULL,SIMPLE_IF);}    
    |IF cond THEN stms ELSE uncnd ENDIF ';'              {$$=makeCtrlNode($2,$4,$6,IF_ELSE);}     
    |IF cond THEN uncnd ELSE stms  ENDIF ';'             {$$=makeCtrlNode($2,$4,$6,IF_ELSE);}     
    |IF cond THEN uncnd ELSE uncnd ENDIF ';'             {$$=makeCtrlNode($2,$4,$6,IF_ELSE);}
    ;
whilestm:WHILE cond DO stms ENDWHILE ';'       {$$=makeCtrlNode($2,$4,NULL,WHILE_LOOP);}
    |WHILE cond DO uncnd ENDWHILE ';'          {$$=makeCtrlNode($2,$4,NULL,WHILE_LOOP);}
    |DO stms ENDWHILE cond';'                  {$$=makeCtrlNode($2,$4,NULL,DO_LOOP);}
    |DO uncnd ENDWHILE cond';'                 {$$=makeCtrlNode($2,$4,NULL,DO_LOOP);}
    |REPEAT stms UNTIL cond';'                 {$$=makeCtrlNode($2,$4,NULL,REPEAT_LOOP);}
    |REPEAT uncnd UNTIL cond';'                {$$=makeCtrlNode($2,$4,NULL,REPEAT_LOOP);}
    ;
inp:READ '(' id ')' ';'     {$$=makeFnNode(FN_READ,$3);}
    ;
opt:WRITE '(' exp ')' ';'   {$$=makeFnNode(FN_WRITE,$3);}
    ;
asg:id '=' exp ';' {$$=makeOpNode("=",$1,$3,$1->dtype);}
    ;
exp:exp '+' exp     {$$=makeOpNode("+",$1,$3,INTEGER);}
    |exp '-' exp    {$$=makeOpNode("-",$1,$3,INTEGER);}
    |exp '*' exp    {$$=makeOpNode("*",$1,$3,INTEGER);}
    |exp '/' exp    {$$=makeOpNode("/",$1,$3,INTEGER);}
    |exp '%' exp    {$$=makeOpNode("%%",$1,$3,INTEGER);}
    |'(' exp ')'    {$$=$2;}
    |id         {$$=$1;}
    |NUM            {$$=$1;}
    |STR            {$$=$1;}
    ;
id:ID           {snode *t=getSymbol($1->var);if(t){$1->sym=t;$$=$1;}else yyerror("Undeclared Identifier");}
    |ID'['exp']'    {snode *t=getSymbol($1->var);if(t){$1->l=$3;$1->sym=t;$$=$1;}else yyerror("Undeclared Identifier");}
    |ID'['exp']''['exp ']'    {snode *t=getSymbol($1->var);if(t){$1->l=$3;$1->r=$6;$1->sym=t;$$=$1;}else yyerror("Undeclared Identifier");}
    ;
cond:exp '<' exp    {$$=makeOpNode("<",$1,$3,BOOLEAN);}
    |exp '>' exp    {$$=makeOpNode(">",$1,$3,BOOLEAN);}
    |exp LSEQ exp    {$$=makeOpNode("=<",$1,$3,BOOLEAN);}
    |exp GTEQ exp    {$$=makeOpNode("=>",$1,$3,BOOLEAN);}
    |exp EQTO exp    {$$=makeOpNode("==",$1,$3,BOOLEAN);}
    |exp NTEQ exp    {$$=makeOpNode("=!",$1,$3,BOOLEAN);}
    |'(' cond ')'    {$$=$2;}
    |cond OR cond   {$$=makeOpNode("||",$1,$3,BOOLEAN);}
    |cond AND cond  {$$=makeOpNode("&&",$1,$3,BOOLEAN);}
    |NOT cond       {$$=makeOpNode("!",$2,NULL,BOOLEAN);}
    ;
%%

yyerror(char *err){
   	printf("Parse Error:%s\n",err);
    exit(1);
}
int main(int argc,int *argv[]){
    yyin=fopen((char *)argv[1],"r");
   	return yyparse();
}
