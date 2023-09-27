%{
//Parser to check if a word is a valid variable
#include<stdio.h>
#include<stdlib.h>
%}

%token DIGIT
%token LETTER

%%
strt:var'\n' {printf("\nSuccess\n");exit(1);}
	;
var:LETTER expr {printf("Is a valid Variable.\n");}
	|LETTER {printf("Is a valid Variable.\n");}
	;
expr: DIGIT	
	|LETTER
 	|expr DIGIT 
	|expr LETTER
	;
%%

int yylex()
{
	int c;
	c = getchar();
	if(isdigit(c))
	{
		return DIGIT;

	}
	else if(isalpha(c))
	{
		return LETTER;
	}
	return c;
}
int yyerror(){
	printf("Not a valid Variable.\n");
	return 1;
}
int main(){
	yyparse();
	return 1;
}

