%{
//Parser to output postfix with no attributes
#include<stdio.h>
#include<stdlib.h>
int pos=0;
%}

%token DIGIT
%left '-'
%left '+'
%left '*'
%left '/'

%%
start:expr '\n' {printf("Complete\n");exit(1);}
	;
expr:expr '+' expr {printf("+ ");}
	|expr '-' expr {printf("- ");}
	|expr '*' expr {printf("* ");}
	|expr '/' expr {printf("/ ");}
	|expr DIGIT
	|DIGIT {printf("NUM%d ",pos);}
	;
%%

int yyerror(){
	printf("-error-");
}
int yylex(){
	char c;
	c=getchar();
	if(isdigit(c)){
        	pos++;
        	return DIGIT;
    	}
    	else if(c == ' '){
        	yylex();         /*This is to ignore whitespaces in the input*/
    	}
    	else {
        	return c;
    	}
}
int main(){
	yyparse();
	return 1;
}
