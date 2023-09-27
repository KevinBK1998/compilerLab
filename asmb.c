//Code for converting an expression tree to assembly code
#include<stdio.h>
#include<string.h>
#include "asmb.h"
//#include "exptree.h"  //comment before use
#define RMAX 20
#define SP 4095
int count=-1;
FILE *out;
int getReg(){
    if(count<RMAX-1)
      return ++count;
    printf("Error:Out of Free Registers\n");
    exit(0);
}
void freeReg(){
    if(count)
        count--;
}
int codeInit(char *fnme){
    char *target=(char*)malloc((5+strlen(fnme))*sizeof(char));
    strcpy(target,fnme);
    strcat(target,".xexe");
    out=fopen(target,"w");
    fprintf(out,"%d\n%d\n%d\n%d\n",0,2056,0,0);
    fprintf(out,"%d\n%d\n%d\n%d\n",0,0,0,0);
    fprintf(out,"BRKP\nMOV SP,%d\n",SP);
    return 1;
}
int codeGen(tnode *root){
    int rega,regb;
    switch(root->op){
      case '+':
        rega=codeGen(root->l);
        regb=codeGen(root->r);
        fprintf(out,"ADD R%d,R%d\n",rega,regb);
        freeReg();
        return rega;
      case '-':
        rega=codeGen(root->l);
        regb=codeGen(root->r);
        fprintf(out,"SUB R%d,R%d\n",rega,regb);
        freeReg();
        return rega;
      case '*':
        rega=codeGen(root->l);
        regb=codeGen(root->r);
        fprintf(out,"MUL R%d,R%d\n",rega,regb);
        freeReg();
        return rega;
      case '/':
        rega=codeGen(root->l);
        regb=codeGen(root->r);
        fprintf(out,"DIV R%d,R%d\n",rega,regb);
        freeReg();
        return rega;
      case '%':
        rega=codeGen(root->l);
        regb=codeGen(root->r);
        fprintf(out,"MOD R%d,R%d\n",rega,regb);
        freeReg();
        return rega;
      default:
        rega=getReg();
        fprintf(out,"MOV R%d,%d\n",rega,root->val);
        return rega;
    }
}
int codeRead(int r){
    int temp=getReg();
    fprintf(out,"MOV R%d,7\nPUSH R%d\n",temp,temp);
    fprintf(out,"MOV R%d,%d\nPUSH R%d\n",temp,r,temp);
    fprintf(out,"CALL 0\n");
    fprintf(out,"POP R%d\nPOP R%d\n",temp,temp);
    freeReg();
    return 1;
}
int codeWrite(int r){
    int temp=getReg();
    fprintf(out,"MOV R%d,5\nPUSH R%d\n",temp,temp);
    fprintf(out,"MOV R%d,R%d\nPUSH R%d\n",temp,r,temp);
    fprintf(out,"CALL 0\n");
    fprintf(out,"POP R%d\nPOP R%d\n",temp,temp);
    freeReg();
    return 1;
}
int codeExit(){
    int temp=getReg();
    fprintf(out,"MOV R%d,10\n",temp);
    fprintf(out,"PUSH R%d\nPUSH R%d\n",temp,temp);
    fprintf(out,"CALL 0\n");
    fprintf(out,"POP R%d\nPOP R%d",temp,temp);
    freeReg();
    return 1;
}
int codeAsmble(tnode *code){
    codeInit("out");
    int result=codeGen(code);
    fprintf(out,"MOV [4096],R%d\n",result);
    codeExit();
    fclose(out);
    return 1;
}