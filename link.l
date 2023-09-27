%{
/*Lexical Analyser for label translation
    1.Labels start with 'L' followed by a unique id
*/
#include<stdio.h>
#include "linklist.c"
#define FIN "x.xobj"
#define FOUT "out.xexe"
int pass2,ip;
char *lblnme;
node *lbl;
FILE *f;
%}
digit [0-9]
alphanum [0-9a-zA-Z]

%%
[L]{alphanum}*[:]  {if(!pass2){lblnme=(char*)malloc((strlen(yytext)-1)*sizeof(char));strncpy(lblnme,yytext,strlen(yytext)-1);insert(&lbl,lblnme,ip);}}
[L]{digit}+             {if(pass2)fprintf(f,"%d",sub(lbl,yytext));}
.       {if(pass2)fprintf(f,"%s",yytext);}
[\n]    {ip+=2;if(pass2)fprintf(f,"\n");}

%%

int yywrap(){
    if(pass2)
        return 1;
    pass2++;
    ip=2040;
    yyin=fopen(FIN,"r");
    return 0;
	
}
int main(int argc,char *argv[]){
    ip=2040;
    pass2=0;
    lbl=NULL;
    yyin=fopen(FIN,"r");
    if(argc>1)
        f=fopen(argv[1],"w");
    else
        f=fopen(FOUT,"w");
    yylex();
    return 0;
}