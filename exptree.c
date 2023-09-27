//Code for creation and evaluation of an expression tree
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "exptree.h"
int varcount=4095;
snode *top=NULL;
void Allocate(char *id,int type,int size,int N){
  snode *temp=(snode*)malloc(sizeof(snode));
  temp->dtype=type;
  temp->name=(char*)malloc(strlen(id)*sizeof(char));
  strcpy(temp->name,id);
  temp->size=size;
  temp->rowsize=N;
  temp->bind=++varcount;
  varcount+=size-1;
  temp->n=NULL;
  snode *end=top;
  if(top==NULL){
    top=temp;
    return;
  }
  while(end->n!=NULL)
    end=end->n;
  end->n=temp;
    return;
}
snode *getSymbol(char *s){
    snode *temp=top;
    while(temp){
        if(strcmp(temp->name,s)==0)
            return temp;
        temp=temp->n;
    }
    return NULL;
}
void printSymbols(){
    snode *temp=top;
    while(temp){
        printf("%s,%d->",temp->name,temp->dtype);
        temp=temp->n;
    }    
    printf("NULL\n");
}
tnode *makeOpNode(char *op,tnode *left,tnode *right,int type){
  if(type==STRING&&((left->ntype==OPERATOR&&left->dtype!=type)||(right->ntype==OPERATOR&&right->dtype!=type))){
    printf("Type Mismatch:Expected String %d %d %d\n",left->dtype,type,right->dtype);
    exit(1);
  }
  if(type==INTEGER&&((left->ntype==OPERATOR&&left->dtype!=type)||(right->ntype==OPERATOR&&right->dtype!=type))){
    printf("Type Mismatch:Expected Integer %d %d %d\n",left->dtype,type,right->dtype);
    exit(1);
    
  }
  if(type==BOOLEAN&&((left->ntype==OPERATOR&&left->dtype!=type)||(right->ntype==OPERATOR&&right->dtype!=type))){
    printf("Type Mismatch:Expected Boolean%d %d %d\n",left->dtype,type,right->dtype);
    exit(1);
  }
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->var=(char*)malloc(strlen(op)*sizeof(char));
  strcpy(p->var,op);
  p->ntype=OPERATOR;
  p->dtype=type;
  p->l=left;
  p->r=right;
  p->e=NULL;
  return p;
}
tnode *makeNumNode(int n){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->dtype=INTEGER;
  p->ntype=CONSTANT;
  p->val=n;
  p->l=NULL;
  p->r=NULL;
  p->e=NULL;
  return p;
}
tnode *makeStrNode(char *s){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->dtype=STRING;
  p->ntype=CONSTANT;
  p->var=(char*)malloc(strlen(s)*sizeof(char));
  strcpy(p->var,s);
  p->l=NULL;
  p->r=NULL;
  p->e=NULL;
  return p;
}
tnode *makeUNode(tnode *left,tnode *right,int type){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->ntype=JMP;
  p->dtype=type;
  p->l=left;
  p->r=right;
  p->e=NULL;
  return p;
}
tnode *makeIdNode(char *id){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->ntype=IDENTIFIER;
  p->dtype=IDENTIFIER;
  p->var=(char*)malloc(strlen(id)*sizeof(char));
  strcpy(p->var,id);
  p->l=NULL;
  p->r=NULL;
  p->e=NULL;
  return p;
}
tnode *makeArrNode(tnode *prev,tnode *id,tnode *rows,tnode *colns){
  id->l=prev;
  id->r=rows;
  id->e=colns;
  return id;
}
tnode *makeFnNode(int fcode,tnode *arg){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->val=fcode;
  p->ntype=FUNCTION;
  p->l=arg;
  p->r=NULL;
  p->e=NULL;
  return p;
}
tnode *makeConNode(tnode *left,tnode *right){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->ntype=CONNECTION;
  p->l=left;
  p->r=right;
  p->e=NULL;
  return p;
}
tnode *makeCtrlNode(tnode *left,tnode *right,tnode *Else,int type){
  if(((type==SIMPLE_IF||type==WHILE_LOOP)&&left->dtype!=BOOLEAN)||((type==REPEAT_LOOP||type==DO_LOOP)&&right->dtype!=BOOLEAN))
  {
    printf("Type Mismatch:Expected Boolean\n");
    exit(1); 
  }
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->ntype=CONTROL;
  p->dtype=type;
  p->l=left;
  p->r=right;
  p->e=Else;
  return p;
}
tnode *makeDtype(int type){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->ntype=DATATYPE;
  p->dtype=type;
  p->l=NULL;
  p->r=NULL;
  p->e=NULL;
  return p;
}
void Declare(tnode *Dnode,tnode *Lnode){
  tnode *temp=Lnode;
  int type=Dnode->dtype,s,c;
  while(temp){
    s=1;
    c=1;
    if(temp->r)
      s*=temp->r->val;
    if(temp->e){      
      c=temp->e->val;
      s*=c;
    }
    Allocate(temp->var,type,s,c);
    temp=temp->l;
  }
}
int GetMem(){
  return varcount;
}