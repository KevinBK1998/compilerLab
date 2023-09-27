//Code for converting an expression tree to assembly code
#include<stdio.h>
#include<string.h>
#include "asmb.h"
#include "exptree.h"
#define FOUT "x"
int regcount=-1,lblct=-1;
FILE *out;
int getReg(){
    if(regcount<RMAX-1)
      return ++regcount;
    printf("Error:Out of Free Registers\n");
    exit(0);
}
void freeReg(){
  if(regcount>-1)
    regcount--;
}
int getLabel(){
  return ++lblct;
}
int codeInit(char *fnme){
    char *target=(char*)malloc((5+strlen(fnme))*sizeof(char));
    strcpy(target,fnme);
    strcat(target,".xobj");
    out=fopen(target,"w");
    fprintf(out,"%d\n%d\n%d\n%d\n",0,2056,0,0);
    fprintf(out,"%d\n%d\n%d\n%d\n",0,0,0,0);
    fprintf(out,"MOV SP,%d\n",SP);
    return 1;
}
int codeGen(tnode *root,int lc,int lb,int pos){
  switch(root->ntype){
    case OPERATOR:
      return expCodeGen(root);
    case FUNCTION:
      if(root->val)
        return fnRead(root->l);
      else
        return fnWrite(root->l);
    case CONNECTION:
      codeGen(root->l,lc,lb,pos);
      codeGen(root->r,lc,lb,pos);
      return 0;
    case CONTROL:
      ctrlCodeGen(root,lc,lb,pos);
      return 0;
    case JMP:
      return brkFlowGen(root,lc,lb,pos);
  }
}
int brkFlowGen(tnode *root,int lc,int lb,int pos){
  int l1,reg;
  if(pos==OUT_LOOP){
    if(root->l!=NULL)
      codeGen(root->l,lc,lb,pos);
    if(root->r!=NULL)
      codeGen(root->r,lc,lb,pos);
    return 0;
  }
  if(root->dtype==BREAK_LOOP){
    if(root->l!=NULL)
      codeGen(root->l,lc,lb,pos);
    fprintf(out,"JMP L%d\n",lb);
    if(root->r!=NULL)
      codeGen(root->r,lc,lb,pos);
  }
  else{
    if(root->l!=NULL)
      codeGen(root->l,lc,lb,pos);
      fprintf(out,"JMP L%d\n",lc);
      if(root->r!=NULL)
        codeGen(root->r,lc,lb,pos);
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
    codeInit(FOUT);
    if(code)
      codeGen(code,-1,-1,OUT_LOOP);
    codeExit();
    fclose(out);
    printf("Build Successful\n");
    return 0;
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
      case '-':
        rega=expCodeGen(exp->l);
        regb=expCodeGen(exp->r);
        fprintf(out,"SUB R%d,R%d\n",rega,regb);
        freeReg();
        return rega;
      case '/':
        rega=expCodeGen(exp->l);
        regb=expCodeGen(exp->r);
        fprintf(out,"DIV R%d,R%d\n",rega,regb);
        freeReg();
        return rega;
      case '%':
        rega=expCodeGen(exp->l);
        regb=expCodeGen(exp->r);
        fprintf(out,"MOD R%d,R%d\n",rega,regb);
        freeReg();
        return rega;
      case '<':
        rega=expCodeGen(exp->l);
        regb=expCodeGen(exp->r);
        fprintf(out,"LT R%d,R%d\n",rega,regb);
        freeReg();
        return rega;
      case '>':
        rega=expCodeGen(exp->l);
        regb=expCodeGen(exp->r);
        fprintf(out,"GT R%d,R%d\n",rega,regb);
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
}
int ctrlCodeGen(tnode *exp,int lc,int lb,int pos){
  int l1,l2,reg;
  switch(exp->dtype){
        case SIMPLE_IF:
          l1=getLabel();
          reg=expCodeGen(exp->l);
          fprintf(out,"JZ R%d,L%d\n",reg,l1);
          codeGen(exp->r,lc,lb,pos);
          fprintf(out,"L%d:",l1);
          freeReg();
          return 1;
        case IF_ELSE:
          l1=getLabel();
          l2=getLabel();
          reg=expCodeGen(exp->l);
          fprintf(out,"JZ R%d,L%d\n",reg,l1);
          codeGen(exp->r,lc,lb,pos);
          fprintf(out,"JMP L%d\nL%d:",l2,l1);
          codeGen(exp->e,lc,lb,pos);
          fprintf(out,"L%d:",l2);  
          freeReg();       
          return 1;
        case WHILE_LOOP:
          l1=getLabel();
          l2=getLabel();
          fprintf(out,"L%d:",l1);
          reg=expCodeGen(exp->l);
          fprintf(out,"JZ R%d,L%d\n",reg,l2);
          codeGen(exp->r,l1,l2,IN_LOOP);
          fprintf(out,"JMP L%d\nL%d:",l1,l2);
          freeReg();
          return 1;
    }
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