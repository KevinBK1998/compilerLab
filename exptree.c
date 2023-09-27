//Code for creation and evaluation of an expression tree
#include<stdio.h>
#include<string.h>
#include "exptree.h"
tnode *makeOpNode(char op,tnode *left,tnode *right,int type){
  if(type==INTEGER){
    if((left->dtype!=type)||(right->dtype!=type)){
      printf("Type Mismatch");
      exit(1);
    }
  }
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->var=op;
  p->ntype=OPERATOR;
  p->dtype=type;
  p->l=left;
  p->r=right;
  return p;
}
tnode *makeNumNode(int n){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->dtype=NUMERIC;
  p->ntype=LEAF;
  p->val=n;
  p->l=NULL;
  p->r=NULL;
  return p;
}
tnode *makeIdNode(char c){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->dtype=IDENTIFIER;
  p->ntype=LEAF;
  p->var=c;
  p->l=NULL;
  p->r=NULL;
  return p;
}
tnode *makeFnNode(int fcode,tnode *arg){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->val=fcode;
  p->ntype=FUNCTION;
  p->l=arg;
  p->r=NULL;
  return p;
}
tnode *makeConNode(tnode *left,tnode *right){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->ntype=CONNECTION;
  p->l=left;
  p->r=right;
  return p;
}
tnode *makeCtrlNode(tnode *left,tnode *right,int type){
  if(type!=SIMPLE_IF||type!=WHILE_LOOP||left->dtype==BOOLEAN){
    tnode *p=(tnode*)malloc(sizeof(tnode));
    p->ntype=CONTROL;
    p->dtype=type;
    p->l=left;
    p->r=right;
    return p;
  }
  printf("Type Mismatch\n");
  exit(1);
}