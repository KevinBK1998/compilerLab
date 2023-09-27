%{
//Lexical Analyser to identify numbers,identifiers,operators,keywords
#include<stdio.h>
#include "y.tab.h"
#include "exptree.h"
%}

singleComment 		[/][/][-*+/%()=;<>!{}a-zA-Z0-9 ]*
num [0-9]+
op [-*+/%()=;<>!{}]
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
break [b][r][e][a][k]
continue [c][o][n][t][i][n][u][e]

%%
{singleComment} {}
{num}   {int i=atoi(yytext);yylval.node=makeNumNode(i);return NUM;}
{op}    {return *yytext;}
{id}    {char c=*yytext;yylval.node=makeIdNode(c);return ID;}
{beg}   {return BEG;}
{if}    {return IF;}
{else}  {return ELSE;}
{then}  {return THEN;}
{endif} {return ENDIF;}
{while} {return WHILE;}
{do}    {return DO;}
{break} {return BREAK;}
{continue} {return CONTINUE;}
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