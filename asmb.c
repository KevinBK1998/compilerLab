//Code for converting an expression tree to assembly code
#include<stdio.h>
#include<string.h>
#include "asmb.h"
#include "exptree.h"
#define FOUT "x.xobj"
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
int getRVal(tnode *varNode){
  int rega,regb;
  tnode *expR=varNode->l;
  tnode *expC=varNode->r;
  snode *id=varNode->sym;
  rega=getReg();
  fprintf(out,"MOV R%d,%d\n",rega,id->bind);
  if(expR){
    regb=expCodeGen(expR);
    if(expC){
      int regt=getReg();
      fprintf(out,"MOV R%d,%d\n",regt,id->rowsize);
      fprintf(out,"MUL R%d,R%d\n",regb,regt);      
      fprintf(out,"ADD R%d,R%d\n",rega,regb);
      freeReg();
      freeReg();
      regb=expCodeGen(expC);
      fprintf(out,"ADD R%d,R%d\n",rega,regb);
      freeReg();
    }
    else{
      fprintf(out,"ADD R%d,R%d\n",rega,regb);
      freeReg();
    }
  }
  fprintf(out,"MOV R%d,[R%d]\n",rega,rega);
  return rega;
}
int getLVal(tnode *varNode){
  int rega,regb;
  tnode *expR=varNode->l;
  tnode *expC=varNode->r;
  snode *id=varNode->sym;
  rega=getReg();
  fprintf(out,"MOV R%d,%d\n",rega,id->bind);
  if(expR){
    regb=expCodeGen(expR);    
    if(expC){
      int regt=getReg();
      fprintf(out,"MOV R%d,%d\n",regt,id->rowsize);
      fprintf(out,"MUL R%d,R%d\n",regb,regt);      
      fprintf(out,"ADD R%d,R%d\n",rega,regb);
      freeReg();
      freeReg();
      regb=expCodeGen(expC);
      fprintf(out,"ADD R%d,R%d\n",rega,regb);
      freeReg();
    }
    else{
      fprintf(out,"ADD R%d,R%d\n",rega,regb);
      freeReg();
    }
  }
  return rega;
}
int codeInit(char *fnme){
    out=fopen(fnme,"w");
    fprintf(out,"%d\n%d\n%d\n%d\n",0,2056,0,0);
    fprintf(out,"%d\n%d\n%d\n%d\n",0,0,0,0);
    fprintf(out,"MOV SP,%d\n",GetMem());
    return 1;
}
int codeGen(tnode *root,int lc,int lb,int pos){
  switch(root->ntype){
    case OPERATOR:
      return expCodeGen(root);
    case FUNCTION:
      if(root->val)
        return codeRead(root->l);
      else
        return codeWrite(root->l);
    case CONNECTION:
      if(root->l)
        codeGen(root->l,lc,lb,pos);
      if(root->r)
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
int codeRead(tnode *t){
  int reg=getLVal(t),temp=getReg();
  fprintf(out,"MOV R%d,7\t;Read Begins\nPUSH R%d\n",temp,temp);
  fprintf(out,"MOV R%d,R%d\t;Value stored here\nPUSH R%d\n",temp,reg,temp);
  fprintf(out,"CALL 0\n");
  fprintf(out,"POP R%d\nPOP R%d\t;Read Ends\n",temp,temp);
  freeReg();
  freeReg();
  return 0;
}
int codeWrite(tnode *t){
  int reg=expCodeGen(t),temp=getReg();
  fprintf(out,"MOV R%d,5\t;Write Begins\nPUSH R%d\n",temp,temp);
  fprintf(out,"MOV R%d,R%d\t;Data taken from here\nPUSH R%d\n",temp,reg,temp);
  fprintf(out,"CALL 0\n");
  fprintf(out,"POP R%d\nPOP R%d\t;Write Ends\n",temp,temp);
  freeReg();
  freeReg();
  return 0;
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
    return 1;
}
int expCodeGen(tnode *exp){
  int rega,regb,var;
  if(exp->ntype){
    if(strlen(exp->var)==1){
      switch(exp->var[0]){
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
          rega=getLVal(exp->l);
          regb=expCodeGen(exp->r);
          fprintf(out,"MOV [R%d],R%d\n",rega,regb);
          freeReg();
          freeReg();
          return rega;
        case '!':
          rega=expCodeGen(exp->l);
          regb=getReg();
          fprintf(out,"MOV R%d,%d\n",regb,0);
          fprintf(out,"EQ R%d,R%d\n",rega,regb);
          freeReg();
          return rega;
      }
    }
    else{
      switch(exp->var[1]){
        case '<':
          rega=expCodeGen(exp->l);
          regb=expCodeGen(exp->r);
          fprintf(out,"LE R%d,R%d\n",rega,regb);
          freeReg();
          return rega;
        case '>':
          rega=expCodeGen(exp->l);
          regb=expCodeGen(exp->r);
          fprintf(out,"GE R%d,R%d\n",rega,regb);
          freeReg();
          return rega;
        case '%':
          rega=expCodeGen(exp->l);
          regb=expCodeGen(exp->r);
          fprintf(out,"MOD R%d,R%d\n",rega,regb);
          freeReg();
          return rega;
        case '=':
          rega=expCodeGen(exp->l);
          regb=expCodeGen(exp->r);
          fprintf(out,"EQ R%d,R%d\n",rega,regb);
          freeReg();
          return rega;
        case '!':
          rega=expCodeGen(exp->l);
          regb=expCodeGen(exp->r);
          fprintf(out,"NE R%d,R%d\n",rega,regb);
          freeReg();
          return rega;
        case '|':
          rega=expCodeGen(exp->l);
          regb=expCodeGen(exp->r);
          fprintf(out,"ADD R%d,R%d\n",rega,regb);
          freeReg();
          return rega;
        case '&':
          rega=expCodeGen(exp->l);
          regb=expCodeGen(exp->r);
          fprintf(out,"MUL R%d,R%d\n",rega,regb);
          freeReg();
          return rega;
      }
    }
  }
  switch(exp->dtype){
    case INTEGER:
      rega=getReg();
      fprintf(out,"MOV R%d,%d\n",rega,exp->val);
      return rega;
    case STRING:
      rega=getReg();
      fprintf(out,"MOV R%d,%s\n",rega,exp->var);
      return rega;
  /*case IDENTIFIER:
      return getRVal(exp);
      */
  }
  if(exp->ntype==IDENTIFIER)
    return getRVal(exp);
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
        case DO_LOOP:
          l1=getLabel();
          l2=getLabel();
          fprintf(out,"L%d:",l1);
          codeGen(exp->l,l1,l2,IN_LOOP);
          reg=expCodeGen(exp->r);
          fprintf(out,"JNZ R%d,L%d\nL%d:",reg,l1,l2);
          freeReg();
          return 1;
        case REPEAT_LOOP:
          l1=getLabel();
          l2=getLabel();
          fprintf(out,"L%d:",l1);
          codeGen(exp->l,l1,l2,IN_LOOP);
          reg=expCodeGen(exp->r);
          fprintf(out,"JZ R%d,L%d\nL%d:",reg,l1,l2);
          freeReg();
          return 1;
    }
}