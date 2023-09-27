//Code for creation and evaluation of an expression tree
#include<stdio.h>
#include<string.h>
#include "exptree.h"
tnode *makeOpNode(char op,tnode *left,tnode *right){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->var=op;
  p->ntype=OPERATOR;
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