%{
/*Lexical analyser to print a word in uppercase if word 
1.starts with 'A',and
2.has 3 letters
*/
#include<stdio.h>
#include<ctype.h>
%}

line [\n]
letter [a-zA-Z]

%%
[A]{letter}{letter} {printf("%c%c%c\n",toupper(*yytext),toupper(*(yytext+1)),toupper(*(yytext+2)));}
. {;}
%%

int yywrap(){
	return 1;
}

int main(){
	yylex();
	return 1;
}
