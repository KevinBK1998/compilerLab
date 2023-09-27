//Code for converting an expression tree to assembly code
#include<stdio.h>
#include<string.h>
#include "asmb.h"
//#include "exptree.c"  //comment before use
int count=-1;
FILE *out;
int getReg(){
    if(count<RMAX-1)
      return ++count;
    printf("Error:Out of Free Registers\n");
    exit(0);
}
void freeReg(){
    if(count>-1)
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
  switch(root->ntype){
    case OPERATOR:
      return expCodeGen(root);
    case FUNCTION:
      if(root->val)
        return fnRead(root->l);
      else
        return fnWrite(root->l);
    case CONNECTION:
      codeGen(root->l);
      codeGen(root->r);
      return 0;
  }
}
int codeRead(int r){
    int temp=getReg();
    fprintf(out,"MOV R%d,7\t;Read Begins\nPUSH R%d\n",temp,temp);
    fprintf(out,"MOV R%d,%d\t;Value stored here\nPUSH R%d\n",temp,r,temp);
    fprintf(out,"CALL 0\n");
    fprintf(out,"POP R%d\nPOP R%d\t;Read Ends\n",temp,temp);
    freeReg();
    freeReg();
    return 1;
}
int codeWrite(int r){
    int temp=getReg();
    fprintf(out,"MOV R%d,5\t;Write Begins\nPUSH R%d\n",temp,temp);
    fprintf(out,"MOV R%d,R%d\t;Data taken from here\nPUSH R%d\n",temp,r,temp);
    fprintf(out,"CALL 0\n");
    fprintf(out,"POP R%d\nPOP R%d\t;Write Ends\n",temp,temp);
    freeReg();
    freeReg();
    return 1;
}
int codeExit(){
    int temp=getReg();
    fprintf(out,"MOV R%d,10\t;Exit Begins\n",temp);
    fprintf(out,"PUSH R%d\nPUSH R%d\n",temp,temp);
    fprintf(out,"CALL 0\n");
    fprintf(out,"POP R%d\nPOP R%d\t;Exit Ends",temp,temp);
    freeReg();
    return 1;
}
int codeAsmble(tnode *code){
    codeInit("out");
    if(code)
      codeGen(code);
    codeExit();
    fclose(out);
    printf("Build Successful\n");
    return 1;
}
int expCodeGen(tnode *exp){
  int rega,regb,var;
  if(exp->ntype){
    switch(exp->var){
      case '+':
        rega=expCodeGen(exp->l);
        regb=expCodeGen(exp->r);
        fprintf(out,"ADD R%d,R%d\n",rega,regb);
        freeReg();
        return rega;
      case '*':
        rega=expCodeGen(exp->l);
        regb=expCodeGen(exp->r);
        fprintf(out,"MUL R%d,R%d\n",rega,regb);
        freeReg();
        return rega;
      case '=':
        var=getVar(exp->l);
        rega=expCodeGen(exp->r);
        fprintf(out,"MOV [%d],R%d\n",var,rega);
        freeReg();
        return rega;
    }
  }
  switch(exp->dtype){
    case NUMERIC:
      rega=getReg();
      fprintf(out,"MOV R%d,%d\n",rega,exp->val);
      return rega;
    case IDENTIFIER:
      rega=getReg();
      fprintf(out,"MOV R%d,[%d]\n",rega,getVar(exp));
      return rega;
  }
  /*switch(root->op){
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
  */
}
int fnRead(tnode *t){
    int var=getVar(t);
    codeRead(var);
    return 0;
}
int fnWrite(tnode *t){
    int reg=expCodeGen(t);
    codeWrite(reg);
    return 0;
}
int getVar(tnode *varNode){
    return 4096+(varNode->var-'a');
}