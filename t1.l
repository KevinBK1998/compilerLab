%{
	/*choosing input
	1.stdin
	2.stdin
	*/
	#include <stdlib.h>
	#include <stdio.h>
	#include<string.h>
	char *infile;
%}
	
number [0-9]+
 
%%
 
{number} {printf("Num=%d ",atoi(yytext));}
 
%%
 
int yywrap(){
	if(strcmp(infile,"con2")!=0){
		infile="con2";
		yyin = stdin;
		printf("Input=stdin2\n");
		return 0;
	}
	else 
		return 1;
	
}

int main()
{	infile="con";
	printf("Input=stdin1\n");
	yylex();
	return 1;
}
