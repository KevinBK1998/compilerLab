%{
/*Parser to identify syntax and create AST
  Stage 7:
  1.Built-in fns include read(),write(),alloc(),initialize(),free()
  2.Global Declarations,Functions,Local Declarations added
  3.All user defined function definitions, if any, should be given before main()
  4.Two fundamental datatypes-int & str
  5.All user defined type definitions, if any, should be given before global declarations
  6.Adding class defnitions
  7.Member Fn declaration,definition,type checking finished
  8.Fixed Bug:type name,class name can be defined as variable name
  9.Denied use of member variables in non member functions
  10.Member fns have access to member variables also
  To-Do
  1.Error:Passing variables to a multi argument member fncall gives segmentation fault
  2.Error:Omitting return statements

*/
#include<stdio.h>
#include<stdlib.h>
#include "exptree.c"
//#include "assembler.c"
#define YYSTYPE node*
extern FILE* yyin;
%}

%token NUM ID IF THEN ELSE ENDIF WHILE DO FREE ENDWHILE REPEAT UNTIL BREAK STR TYPE INIT NULL_VAL SELF NEW_KEY
%token CONTINUE BEG READ WRITE END ALLOC DECL INT_TYPE STR_TYPE ENDDECL MAIN RETF ENDTYPE ENDCLASS CLASS DEL
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
%left '.'
%left '['']'
%left '(' ')'
%left '{''}'

%%
start:tree  {return $1;}
    ;
tree:typeDef classDef Gdecl Mdef main   {$$=makeFnDefLinkNode($4,$5);}
    |typeDef classDef Gdecl main        {$$=$4;}
    |classDef Gdecl Mdef main           {$$=makeFnDefLinkNode($3,$4);}
    |typeDef Gdecl Mdef main            {$$=makeFnDefLinkNode($3,$4);}
    |classDef Gdecl main                {$$=$3;}
    |typeDef Gdecl main                 {$$=$3;}
    |Gdecl Mdef main                    {$$=makeFnDefLinkNode($2,$3);}
    |typeDef main                       {$$=$2;}
    |Gdecl main                         {$$=$2;}    
    |main                               {$$=$1;}
    ;
main:INT_TYPE MAIN '('')''{' Ldecl code '}' {$$=makeFnDefNode(makeDType($1),$2,NULL,$6,$7);}
    |INT_TYPE MAIN '('')''{' code '}'       {$$=makeFnDefNode(makeDType($1),$2,NULL,NULL,$6);}
    ;
Mdef:Mdef def   {$$=makeFnDefLinkNode($1,$2);}
    |def        {$$=$1;}
    ;
Mmfdef:Mmfdef mfdef     {$$=makeFnDefLinkNode($1,$2);}
    |mfdef              {$$=$1;}
    ;
def:type ID '(' plist ')''{' Ldecl code '}' {$$=makeFnDefNode($1,$2,$4,$7,$8);}
    |type ID '(' plist ')''{' code '}'      {$$=makeFnDefNode($1,$2,$4,NULL,$7);}
    |type ID '('')''{' code '}'             {$$=makeFnDefNode($1,$2,NULL,NULL,$6);}
    |type ID '('')''{' Ldecl code '}'       {$$=makeFnDefNode($1,$2,NULL,$6,$7);}
    ;
mfdef:type ID '(' plist ')''{' Ldecl code '}'   {$$=makeMemFnNode($1,$2,$4,$7,$8);}
    |type ID '(' plist ')''{' code '}'          {$$=makeMemFnNode($1,$2,$4,NULL,$7);}
    |type ID '('')''{' code '}'                 {$$=makeMemFnNode($1,$2,NULL,NULL,$6);}
    |type ID '('')''{' Ldecl code '}'           {$$=makeMemFnNode($1,$2,NULL,$6,$7);}
    ;
code:BEG stms END  {$$=$2;}
    |BEG brk END   {$$=$2;}
    |BEG cont END  {$$=$2;}
    |BEG END      
    ;
stms:stms stm {$$=makeConNode($1,$2);}
    |stm      {$$=$1;}
    ;
uncnd:brk   {$$=$1;}
    |cont   {$$=$1;}
    ;
brk:stms BREAK ';'  stms    {$$=makeUNode($1,$4,BREAK_LOOP);}
    |BREAK ';' stms         {$$=makeUNode(NULL,$3,BREAK_LOOP);}
    |stms BREAK ';'         {$$=makeUNode($1,NULL,BREAK_LOOP);}
    |BREAK ';'              {$$=makeUNode(NULL,NULL,BREAK_LOOP);}
    ;
cont:stms CONTINUE';'  stms {$$=makeUNode($1,$4,CONT_LOOP);}
    |CONTINUE ';' stms      {$$=makeUNode(NULL,$3,CONT_LOOP);}
    |stms CONTINUE ';'      {$$=makeUNode($1,NULL,CONT_LOOP);}
    |CONTINUE ';'           {$$=makeUNode(NULL,NULL,CONT_LOOP);}
    ;
stm:ctrl        {$$=$1;}
    |inp        {$$=$1;}
    |opt        {$$=$1;}
    |asg        {$$=$1;}
    |ret        {$$=$1;}
    |delmem ';' {$$=$1;}
    |freemem ';'{$$=$1;}
    |INIT '('')'';' {$$=makeNode4DMA(DMA_INIT);}
    ;
Gdecl:DECL Gmdcl ENDDECL    {$$=NULL;}
    |DECL ENDDECL           {$$=NULL;}
    ;
Ldecl:DECL Lmdcl ENDDECL    {$$=$2;}
    |DECL ENDDECL           {$$=NULL;}
    ;
Cdecl:DECL Cmdcl ENDDECL    {$$=$2;}
    |DECL ENDDECL           {$$=NULL;}
    ;
Gmdcl:Gmdcl Gdcl
    |Gdcl
    ;
Lmdcl:Lmdcl Ldcl    {$$=linkLDecLines($1,$2);}
    |Ldcl           {$$=$1;}
    ;
Cmdcl:Cmdcl Cdcl    {$$=linkLDecLines($1,$2);}
    |Cdcl           {$$=$1;}
    ;
type:INT_TYPE   {$$=makeDType($1);}
    |STR_TYPE   {$$=makeDType($1);}
    |ID         {$$=makeDType($1);}
    ;
typeDef:TYPE udtype ENDTYPE
    ;
classDef:CLASS mclass ENDCLASS
    ;
udtype:udtype ID '{'Lmdcl'}'    {createNewDType($2,$4);}
    |ID '{'Lmdcl'}'             {createNewDType($1,$3);}
    ;
mclass:mclass ID '{'Cdecl Mmfdef'}' {createNewClass($2,$4,$5);}
    |mclass ID '{'Cdecl'}'          {createNewClass($2,$4,NULL);}
    |ID '{'Cdecl Mmfdef'}'          {createNewClass($1,$3,$4);}
    |ID '{'Cdecl'}'                 {createNewClass($1,$3,NULL);}
    ;
Gdcl:type Gvlist ';'{GDeclare($1,$2);}
    ;
Ldcl:type Lvlist ';'{$$=makeALocDecLine($1,$2);}
    ;
Cdcl:type Cvlist ';'{$$=makeALocDecLine($1,$2);}
    ;
Gvlist:Gvlist ',' ID '(' plist ')'  {$$=makeFnLinkNode($1,$3,$5);}
    |Gvlist ',' ID '('')'           {$$=makeFnLinkNode($1,$3,NULL);}
    |Gvlist ',' ID '['NUM']'        {$$=makeGDeclLineNode($1,$3,$5);}
    |Gvlist ',' ID                  {$$=makeGDeclLineNode($1,$3,NULL);}    
    |ID '(' plist ')'               {$$=makeFnLinkNode(NULL,$1,$3);}
    |ID '('')'                      {$$=makeFnLinkNode(NULL,$1,NULL);}
    |ID '['NUM']'                   {$$=makeGDeclLineNode(NULL,$1,$3);}
    |ID                             {$$=makeGDeclLineNode(NULL,$1,NULL);}
    ;
Lvlist:Lvlist ',' ID  {$$=makeLDeclLineNode($1,$3);}
    |ID               {$$=makeLDeclLineNode(NULL,$1);}
    ;   
Cvlist:Cvlist ',' ID '(' plist ')'  {$$=makeFnLinkNode($1,$3,$5);}
    |Cvlist ',' ID '('')'           {$$=makeFnLinkNode($1,$3,NULL);}
    |Cvlist ',' ID                  {$$=makeLDeclLineNode($1,$3);}
    |ID '(' plist ')'               {$$=makeFnLinkNode(NULL,$1,$3);}
    |ID '('')'                      {$$=makeFnLinkNode(NULL,$1,NULL);}
    |ID                             {$$=makeLDeclLineNode(NULL,$1);}
    ;
plist:plist ','type ID  {$$=makeParamLinkNode($1,$3,$4);}
    |type ID            {$$=makeParamLinkNode(NULL,$1,$2);}
    ;
ctrl:ifstm      {$$=$1;}
    |whilestm   {$$=$1;}
    ;
inp:READ '(' fld ')' ';'    {$$=makeIONode(IO_READ,$3);}
    |READ '(' id ')' ';'    {$$=makeIONode(IO_READ,$3);}
    ;
opt:WRITE '(' exp ')' ';'   {$$=makeIONode(IO_WRITE,$3);}
    ;
asg:lvaL '=' exp ';'      {$$=makeOpNode("=",$1,$3);}
    |lvaL '=' dmaf ';'    {$$=makeOpNode("=",$1,$3);}
    ;
dmaf:INIT '('')'    {$$=makeNode4DMA(DMA_INIT);}
    |ALLOC'('')'    {$$=makeNode4DMA(DMA_ALLOC);}
    |NEW_KEY'('id')'{$$=makeNewNode($3);}
    |delmem         {$$=$1;}
    |freemem        {$$=$1;}
    ;
ret:RETF exp ';'    {$$=makeRetNode($2);}
    ;
delmem:DEL '('fld')'   {$$=makeNode4DMAFree($3);}
    |DEL '('id')'      {$$=makeNode4DMAFree($3);}
    ;
freemem:FREE '('fld')'   {$$=makeNode4DMAFree($3);}
    |FREE '('id')'       {$$=makeNode4DMAFree($3);}
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
exp:exp '+' exp     {$$=makeOpNode("+",$1,$3);}
    |exp '-' exp    {$$=makeOpNode("-",$1,$3);}
    |exp '*' exp    {$$=makeOpNode("*",$1,$3);}
    |exp '/' exp    {$$=makeOpNode("/",$1,$3);}
    |exp '%' exp    {$$=makeOpNode("%%",$1,$3);}
    |exp '<' exp    {$$=makeOpNode("<",$1,$3);}
    |exp '>' exp    {$$=makeOpNode(">",$1,$3);}
    |exp LSEQ exp   {$$=makeOpNode("=<",$1,$3);}
    |exp GTEQ exp   {$$=makeOpNode("=>",$1,$3);}
    |exp EQTO exp   {$$=makeOpNode("==",$1,$3);}
    |exp NTEQ exp   {$$=makeOpNode("=!",$1,$3);}
    |exp OR exp     {$$=makeOpNode("L|",$1,$3);}
    |exp AND exp    {$$=makeOpNode("L&",$1,$3);}
    |NOT exp        {$$=makeOpNode("!",$2,NULL);}
    |'(' exp ')'    {$$=$2;}
    |ID '('args')'  {$$=makeFnCallNode($1,$3);}
    |fld            {$$=$1;}
    |mf             {$$=$1;}
    |id             {$$=$1;}
    |NULL_VAL       {$$=makeNullNode();}
    |NUM            {$$=$1;}
    |STR            {$$=$1;}
    ;
lvaL:fld    {$$=$1;}
    |id     {$$=$1;}
    ;
fld:fld '.' ID  {$$=linkFldNode($1,$3);}
    |ID '.' ID  {$$=linkFldNode($1,$3);}
    |SELF '.'ID {$$=linkFldNode($1,$3);}
    ;
mf:fld '.' ID'('args')'     {$$=linkFldNode($1,makeMemFnCallNode($3,$5));}
    |ID '.' ID '('args')'   {$$=linkFldNode($1,makeMemFnCallNode($3,$5));}
    |SELF '.'ID '('args')'  {$$=linkFldNode($1,makeMemFnCallNode($3,$5));}
    ;
id:ID'['exp']'  {$$=linkIdNode($1,$3);}
    |ID         {$$=linkIdNode($1,NULL);}
    ;
args:args ','exp    {$$=makeArgLinkNode($1,$3);}
    |exp            {$$=makeArgLinkNode(NULL,$1);}
    |               {$$=NULL;}
    ;
%%

yyerror(char *err){
   	printf("Parse Error:%s\n",err);
    remove("x.xobj");
    exit(1);
}
int main(int argc,char *argv[]){
    yyin=fopen(argv[1],"r");
    yyparse();
    //codeAsmble(yyparse());
   	return 1;
}