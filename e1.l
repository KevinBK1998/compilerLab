%{
//Lexical Analyser to count lines,words,characters
#include<stdio.h>
int l,w,c;
%}

line [\n]
letter [a-zA-Z]

%%
{line} {l++;}
{letter}+ {w++;c+=yyleng;}
. {c+=yyleng;}

%%

int yywrap(){
	return 1;
}

int main(){
	l=c=w=0;
	yylex();
	printf("Lines:%d\nWords:%d\nCharacters:%d\n",l,w,c);
	return 1;
}
