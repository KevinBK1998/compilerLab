%{
//Lexical Analyser to identify numbers,identifiers,operators,keywords
#include<stdio.h>
#include "y.tab.h"
%}

num [0-9]+
op [-*+/%()=;<>!]
id [a-z]
beg [b][e][g][i][n]
read [r][e][a][d]
if [i][f]
then [t][h][e][n]
else [e][l][s][e]
endif [e][n][d][i][f]
while   [w][h][i][l][e]
do  [d][o]
endwhile    [e][n][d][w][h][i][l][e]
write [w][r][i][t][e]
end [e][n][d]

%%
{num}   {int i=atoi(yytext);yylval=makeNumNode(i);return NUM;}
{op}    {return *yytext;}
{id}    {char c=*yytext;yylval=makeIdNode(c);return ID;}
{beg}   {return BEG;}
{if}    {return IF;}
{else}  {return ELSE;}
{then}  {return THEN;}
{endif} {return ENDIF;}
{while} {return WHILE;}
{do}    {return DO;}
{endwhile} {return ENDWHILE;}
{read}  {return READ;}
{write} {return WRITE;}
{end}   {return END;}
[\n]    {return LINE;}
. {}
%%

yywrap(){
    return 1;
}