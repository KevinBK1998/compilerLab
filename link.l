%{
//Lexical Analyser for label translation
#include<stdio.h>
#include "linklist.c"
int pass2,ip;
char lblnme[4];
node *lbl;
FILE *f;
%}
digit [0-9]
alphanum [0-9a-zA-Z]
letter [a-zA-Z]

%%
{letter}{alphanum}*[:]  {if(!pass2){strncpy(lblnme,yytext,strlen(yytext)-1);insert(&lbl,lblnme,ip);}}
[L]{digit}+             {if(pass2)fprintf(f,"%d",sub(lbl,yytext));}
.       {if(pass2)fprintf(f,"%s",yytext);}
[\n]    {ip+=2;if(pass2)fprintf(f,"\n");}

%%

int yywrap(){
    if(pass2)
        return 1;
    pass2++;
    ip=2040;
    yyin=fopen("x.xobj","r");
    return 0;
	
}
int main(){
    ip=2040;
    pass2=0;
    lbl=NULL;
    yyin=fopen("x.xobj","r");
    f=fopen("out.xexe","w");
    yylex();    
    return 0;
}