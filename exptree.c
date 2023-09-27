//Code for creation of an expression tree and global symbol table
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "exptree.h"
int varcount=4095;
snode *top=NULL;
void Allocate(char *id,int type,int size,int N){
  snode *temp=(snode*)malloc(sizeof(snode));
  snode *check=getSymbol(id);
  if(check){
    printf("Redeclaration of identifier '%s'\n",id);
    exit(1);
  }
  temp->dtype=type;
  temp->name=(char*)malloc(strlen(id)*sizeof(char));
  strcpy(temp->name,id);
  temp->size=size;
  temp->csize=N;
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
  if(type==BOOLEAN){
    if(op[0]=='L')
      if((left->ntype==OPERATOR&&left->dtype!=type)||(right->ntype==OPERATOR&&right->dtype!=type)){
        printf("Type Mismatch:Expected Boolean\n");
        exit(1);
      }
    if(op[0]=='!')
      if(left->ntype==OPERATOR&&left->dtype!=type){
        printf("Type Mismatch:Expected Boolean\n");
        exit(1);
      }
      else{
        tnode *p=(tnode*)malloc(sizeof(tnode));
        p->var=(char*)malloc(strlen(op)*sizeof(char));
        strcpy(p->var,op);
        p->ntype=OPERATOR;
        p->dtype=type;
        p->l=left;
        p->r=NULL;
        p->e=NULL;
        return p;
      }
    if((left->ntype!=OPERATOR&&right->ntype!=OPERATOR)&&left->dtype!=right->dtype){
        printf("Type Mismatch:Expected Boolean\n");
        exit(1);
    }
  }
  else{
    if(right->dtype!=type){
      printf("Type Mismatch:Expected ");
      if(type==STRING)
        printf("String\n");
      else
        printf("Integer\n");
      exit(1);
    }
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
  p->var=(char*)malloc(strlen(id)*sizeof(char));
  strcpy(p->var,id);
  p->l=NULL;
  p->r=NULL;
  p->e=NULL;
  return p;
}
tnode *makeArrNode(tnode *prev,tnode *id,tnode *rows,tnode *colns,int type){
  id->l=prev;
  id->r=rows;
  id->e=colns;
  id->dtype=type;
  return id;
}
tnode *makePtrNode(char *op,tnode *id){
  tnode *p=(tnode*)malloc(sizeof(tnode));
  p->var=(char*)malloc(strlen(op)*sizeof(char));
  if(strcmp(op,"**")==0)
    if(id->sym->csize!=PTR){
      printf("Type Mismatch:Expected Pointer\n");
      exit(1); 
    }
  strcpy(p->var,op);
  p->ntype=OPERATOR;
  p->dtype=INTEGER;
  p->l=id;
  p->r=NULL;
  p->e=NULL;
  return p;
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
  int type=Dnode->dtype,s,c,p;
  while(temp){
    s=1;
    c=1;
    if(temp->r)
      s*=temp->r->val;
    if(temp->e){      
      c=temp->e->val;
      s*=c;
    }
    if(temp->dtype)
      Allocate(temp->var,type,s,PTR);
    else
      Allocate(temp->var,type,s,c);
    temp=temp->l;
  }
}
int GetMem(){
  return varcount;
}
tnode* linkIdNode(tnode *id,tnode *rows,tnode *colns){
  snode *t=getSymbol(id->var);
  if(t){
    int rmax=t->size/t->csize;
    id->dtype=t->dtype;
    id->l=NULL;
    id->r=NULL;
    id->val=VARIABLE;
    if(rmax>1){
      id->val=ARRAY1D;
      if(t->csize>1)
        id->val=ARRAY2D;
    }    
    id->sym=t;
    if(id->val==ARRAY1D||id->val==ARRAY2D)
      if(rows){
        if(rows->dtype!=INTEGER){
          printf("Expected Integer\n");
          exit(1);
        }    
        if(rows->ntype==CONSTANT&&rows->val>=rmax){
          printf("Out of Bounds\n");
          exit(1);
        }
        id->l=rows;
      }
      else{
        printf("Index(ices) Expected\n");
        exit(1);
      }
    if(id->val==ARRAY2D){
      if(colns){
        if(colns->dtype!=INTEGER){
          printf("Expected Integer\n");
          exit(1);
        }
        if(colns->ntype==CONSTANT&&colns->val>=t->csize){
          printf("Out of Bounds\n");
          exit(1);
        }
        id->r=colns;
      }
      else{
        printf("Index Expected\n");
        exit(1);
      }
    }
    if(id->val==ARRAY1D&&(colns)){
        printf("Unexpected Index\n");
        exit(1);
    }
  }
  else{
    printf("Undeclared Identifier '%s'\n",id->var);
    exit(1);
  }
  return id;
}