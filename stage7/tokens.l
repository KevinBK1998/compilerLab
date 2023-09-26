%{
//Lexical Analyser to identify numbers,identifiers,operators,keywords,comments,user defined types
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
%}

comment1 "//"(.)*
comment2 "/*"(.|\n)*"*/"
num [0-9]+
id [a-zA-Z_][a-zA-Z0-9_]*
op [-*+/%)=;<.>!{},&\[\]]
string ["][^"]*["]
and "and"
or "or"
not "not"
beg "begin"
read "read"
if "if"
then "then"
else "else"
endif "endif"
main "main"
while   "while"
do      "do"
endwhile "endwhile"
repeat "repeat"
until "until"
break "break"
continue "continue"
write "write"
init "initialize"
alloc "alloc"
free "free"
decl "decl"
null "null"
self "self"
int_type "int"
str_type "str"
type "type"
endtype "endtype"
class "class"
endclass "endclass"
enddecl "enddecl"
end "end"
ret "return"
new "new"
del "delete"

%%
{comment2}  {}
{comment1}  {}

{num}   {int i=atoi(yytext);yylval=makeNumNode(i);return NUM;}
{op}    {return *yytext;}
"("     {return *yytext;}
"<="    {return LSEQ;}
">="    {return GTEQ;}   
"=="    {return EQTO;}
"!="    {return NTEQ;}
{ret}   {return RETF;}
{beg}   {return BEG;}
{if}    {return IF;}
{else}  {return ELSE;}
{then}  {return THEN;}
{endif} {return ENDIF;}
{while} {return WHILE;}
{do}    {return DO;}
{repeat}    {return REPEAT;}
{until}     {return UNTIL;}
{endwhile} {return ENDWHILE;}
{break} {return BREAK;}
{continue} {return CONTINUE;}
{read}  {return READ;}
{write} {return WRITE;}
{alloc} {return ALLOC;}
{free}  {return FREE;}
{new}   {return NEW_KEY;}
{del}   {return DEL;}
{null}  {return NULL_VAL;}
{init}  {return INIT;}
{decl} {return DECL;}
{int_type} {yylval=makeIdNode(yytext);return INT_TYPE;}
{str_type} {yylval=makeIdNode(yytext);return STR_TYPE;}
{type}  {return TYPE;}
{endtype}  {return ENDTYPE;}
{class}  {return CLASS;}
{endclass}  {return ENDCLASS;}
{enddecl} {return ENDDECL;}
{and} {return AND;}
{or} {return OR;}
{not} {return NOT;}
{end}   {return END;}
{self}  {yylval=makeIdNode(yytext);return SELF;}
{main}  {yylval=makeIdNode(yytext);return MAIN;}
{id}    {yylval=makeIdNode(yytext);return ID;}
{string}    {yylval=makeStrNode(yytext);return STR;}
[ \n\t] {}
. {printf("Read Error:Unexpected character '%c'\n",*yytext);exit(1);}
%%

yywrap(){
    return 1;
}