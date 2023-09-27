%{
//Lexical Analyser to identify comments
#include<stdio.h>
%}

single 		[/][/][a-zA-Z0-9 ]*
compound	[/][*][a-zA-Z0-9 \n]*[*][/]

%%
{single}	{printf("Single:%s\n",yytext);}
{compound} 	{printf("Compound:%s\n",yytext);}
.		{}
%%

int yywrap(){
	return 1;
}

int main(){
	yyin=fopen("test","r");
	yylex();
	return 1;
}
