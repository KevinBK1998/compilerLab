%{
//Lexical Analyser to identify numbers,identifiers,operators,keywords,comments
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
#include "exptree.h"
%}

comment1 "//"[\40-\176\t]*
comment2 "/*"[\40-\176\t\n]*"*/"
num [0-9]+
id [a-zA-Z][a-zA-Z0-9]*
op [-*+/%)=;<>!{},&\[\]]
string ["][\40-\176]*["]
and "and"
or "or"
not "not"
beg "begin"
read "read"
if "if"
then "then"
else "else"
endif "endif"
while   "while"
do      "do"
endwhile    "endwhile"
repeat "repeat"
until "until"
break "break"
continue "continue"
write "write"
decl "decl"
int_type "int"
str_type "str"
enddecl "enddecl"
end "end"

%%
{comment2}  {}
{comment1}  {}
{num}   {int i=atoi(yytext);yylval.node=makeNumNode(i);return NUM;}
{op}    {return *yytext;}
"("     {return *yytext;}
"<="    {return LSEQ;}
">="    {return GTEQ;}   
"=="    {return EQTO;}
"!="    {return NTEQ;}
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
{decl} {return DECL;}
{int_type} {return INT_TYPE;}
{str_type} {return STR_TYPE;}
{enddecl} {return ENDDECL;}
{and} {return AND;}
{or} {return OR;}
{not} {return NOT;}
{end}   {return END;}
{id}    {yylval.node=makeIdNode(yytext);return ID;}
{string}    {yylval.node=makeStrNode(yytext);return STR;}
[\n]    {}
. {}
%%

yywrap(){
    return 1;
}