//Code for creation and evaluation of an expression tree
#include<stdio.h>
#include "exptree.h"
tnode *makeOpNode(char ope,tnode *left,tnode *right){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->op=ope;
  p->val=0;
  p->l=left;
  p->r=right;
  return p;
}
tnode *makeLfNode(int n){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->op='0';
  p->val=n;
  p->l=NULL;
  p->r=NULL;
  printf("p.val=%d",p->val);
  return p;
}
int eval(tnode *t){
    switch(t->op){
      case '+':return eval(t->l)+eval(t->r);
      case '-':return eval(t->l)-eval(t->r);
      case '*':return eval(t->l)*eval(t->r);
      case '/':return eval(t->l)/eval(t->r);
      case '%':return eval(t->l)%eval(t->r);
      default:return t->val;
    }
}
