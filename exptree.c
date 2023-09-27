//Code for creation and evaluation of an expression tree
#include<stdio.h>
#include<string.h>
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
char *pst(tnode *t){
  char *str;
  int l;
  if(!t->val)
    l=strlen(pst(t->l))+strlen(pst(t->r))+4;
  else
    l=countDigit(t->val);
  str=(char*)malloc(l*sizeof(char));
  switch(t->op){
    case '+':
      strcpy(str,pst(t->l));
      strcat(str," ");
      strcat(str,pst(t->r));
      strcat(str,"+ ");
      break;
    case '-':
      strcpy(str,pst(t->l));
      strcat(str," ");
      strcat(str,pst(t->r));
      strcat(str,"- ");
      break;
    case '*':
      strcpy(str,pst(t->l));
      strcat(str," ");
      strcat(str,pst(t->r));
      strcat(str,"* ");
      break;
    case '/':
      strcpy(str,pst(t->l));
      strcat(str," ");
      strcat(str,pst(t->r));
      strcat(str,"/ ");
      break;
    case '%':
      strcpy(str,pst(t->l));
      strcat(str," ");
      strcat(str,pst(t->r));
      strcat(str,"%% ");
      break;
    default:
      sprintf(str,"%d",t->val);
  }
  return str;
}
int pre(tnode *t){
  char *str;
  int l;
  if(!t->val)
    l=strlen(pst(t->l))+strlen(pst(t->r))+4;
  else
    l=countDigit(t->val);
  str=(char*)malloc(l*sizeof(char));
  switch(t->op){
    case '+':
      strcpy(str,"+ ");
      strcat(str,pre(t->l));
      strcat(str," ");
      strcat(str,pre(t->r));      
      break;
    case '-':
      strcpy(str,"- ");
      strcat(str,pre(t->l));
      strcat(str," ");
      strcat(str,pre(t->r));      
      break;
    case '*':
      strcpy(str,"* ");
      strcat(str,pre(t->l));
      strcat(str," ");
      strcat(str,pre(t->r));      
      break;
    case '/':
      strcpy(str,"/ ");
      strcat(str,pre(t->l));
      strcat(str," ");
      strcat(str,pre(t->r));      
      break;
    case '%':
      strcpy(str,"%% ");
      strcat(str,pre(t->l));
      strcat(str," ");
      strcat(str,pre(t->r));      
      break;
    default:
      sprintf(str,"%d",t->val);
  }
  return str;
}
int countDigit(long long n) 
{ 
    int count = 0; 
    while (n != 0) { 
        n = n / 10; 
        ++count; 
    } 
    return count; 
} 