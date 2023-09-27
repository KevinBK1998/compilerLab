%{
/*Parser to identify syntax 
eg:begin
    read(a);
    read(b);
    d=a+2*b;
    write(a+d);
   end;
  1.Included if statement
  2.Included while...do,do...while,repeat...until loops
  3.Included break,continue statement
  4.Included string datatype 
  5.Included declarations(no more predefined variables)
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

%type <node> exp inp opt asg whilestm ifstm ctrl stm cont brk uncnd stms type vlist id dcl mdcl Declare code
%token <node> NUM ID STR
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE BEG READ WRITE END
%token REPEAT UNTIL
%token DECL INT_TYPE STR_TYPE ENDDECL
%left ','
%right '='
%left OR
%left AND
%left EQTO NTEQ
%left '>' GTEQ
%left '<' LSEQ
%left '+' '-'
%left '*' '/' '%'
%right '&'
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
Declare:DECL mdcl ENDDECL
    ;
mdcl:mdcl dcl
    |dcl
    ;
type:INT_TYPE   {$$=makeDtype(INTEGER);}
    |STR_TYPE   {$$=makeDtype(STRING);}
    ;
dcl:type vlist ';'{Declare($1,$2);}
    ;
vlist:vlist ',' ID '['NUM']''['NUM']'   {$$=makeArrNode($1,$3,$5,$8,0);}
    |vlist ',' ID '['NUM']'             {$$=makeArrNode($1,$3,$5,NULL,0);}
    |vlist ',' ID                       {$$=makeArrNode($1,$3,NULL,NULL,0);}
    |ID '['NUM']' '['NUM']'             {$$=makeArrNode(NULL,$1,$3,$6,0);}
    |ID '['NUM']'                       {$$=makeArrNode(NULL,$1,$3,NULL,0);}
    |ID                                 {$$=makeArrNode(NULL,$1,NULL,NULL,0);}
    |vlist ',' '*' ID                   {$$=makeArrNode($1,$4,NULL,NULL,PTR);}
    |'*' ID                             {$$=makeArrNode(NULL,$2,NULL,NULL,PTR);}
    ;
ctrl:ifstm      {$$=$1;}
    |whilestm   {$$=$1;}
    ;
ifstm:IF exp THEN stms ELSE stms  ENDIF ';'             {$$=makeCtrlNode($2,$4,$6,IF_ELSE);}
    |IF exp THEN stms  ENDIF ';'                        {$$=makeCtrlNode($2,$4,NULL,SIMPLE_IF);}
    |IF exp THEN uncnd ENDIF ';'                        {$$=makeCtrlNode($2,$4,NULL,SIMPLE_IF);}    
    |IF exp THEN stms ELSE uncnd ENDIF ';'              {$$=makeCtrlNode($2,$4,$6,IF_ELSE);}     
    |IF exp THEN uncnd ELSE stms  ENDIF ';'             {$$=makeCtrlNode($2,$4,$6,IF_ELSE);}     
    |IF exp THEN uncnd ELSE uncnd ENDIF ';'             {$$=makeCtrlNode($2,$4,$6,IF_ELSE);}
    ;
whilestm:WHILE exp DO stms ENDWHILE ';'       {$$=makeCtrlNode($2,$4,NULL,WHILE_LOOP);}
    |WHILE exp DO uncnd ENDWHILE ';'          {$$=makeCtrlNode($2,$4,NULL,WHILE_LOOP);}
    |DO stms ENDWHILE exp';'                  {$$=makeCtrlNode($2,$4,NULL,DO_LOOP);}
    |DO uncnd ENDWHILE exp';'                 {$$=makeCtrlNode($2,$4,NULL,DO_LOOP);}
    |REPEAT stms UNTIL exp';'                 {$$=makeCtrlNode($2,$4,NULL,REPEAT_LOOP);}
    |REPEAT uncnd UNTIL exp';'                {$$=makeCtrlNode($2,$4,NULL,REPEAT_LOOP);}
    ;
inp:READ '(' id ')' ';'     {$$=makeFnNode(FN_READ,$3);}
    ;
opt:WRITE '(' exp ')' ';'   {$$=makeFnNode(FN_WRITE,$3);}
    ;
asg:id '=' exp ';' {$$=makeOpNode("=",$1,$3,$1->dtype);}
    ;
exp:exp '+' exp     {$$=makeOpNode("+",$1,$3,$1->dtype);}
    |exp '-' exp    {$$=makeOpNode("-",$1,$3,$1->dtype);}
    |exp '*' exp    {$$=makeOpNode("*",$1,$3,$1->dtype);}
    |exp '/' exp    {$$=makeOpNode("/",$1,$3,$1->dtype);}
    |exp '%' exp    {$$=makeOpNode("%%",$1,$3,$1->dtype);}
    |exp '<' exp    {$$=makeOpNode("<",$1,$3,BOOLEAN);}
    |exp '>' exp    {$$=makeOpNode(">",$1,$3,BOOLEAN);}
    |exp LSEQ exp    {$$=makeOpNode("=<",$1,$3,BOOLEAN);}
    |exp GTEQ exp    {$$=makeOpNode("=>",$1,$3,BOOLEAN);}
    |exp EQTO exp    {$$=makeOpNode("==",$1,$3,BOOLEAN);}
    |exp NTEQ exp    {$$=makeOpNode("=!",$1,$3,BOOLEAN);}
    |exp OR exp   {$$=makeOpNode("L|",$1,$3,BOOLEAN);}
    |exp AND exp  {$$=makeOpNode("L&",$1,$3,BOOLEAN);}
    |NOT exp       {$$=makeOpNode("!",$2,NULL,BOOLEAN);}
    |'(' exp ')'    {$$=$2;}
    |id             {$$=$1;}
    |NUM            {$$=$1;}
    |STR            {$$=$1;}
    ;
id:ID           {$$=linkIdNode($1,NULL,NULL);}
    |ID'['exp']'    {$$=linkIdNode($1,$3,NULL);}
    |ID'['exp']''['exp ']'    {$$=linkIdNode($1,$3,$6);}
    |'&'id          {$$=makePtrNode("&",$2);}
    |'*'id          {$$=makePtrNode("**",$2);}
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
