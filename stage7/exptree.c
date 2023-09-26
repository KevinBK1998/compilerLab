//Code for creation of an expression tree and global symbol table
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "exptree.h"
int varcount=4095,fnid=-1;
gsnode *Gtop=NULL;
tnode *TypeTop=NULL;
cnode *ClassTop=NULL;
//Exit if Error
void Exit(){
  remove("x.xobj");
  exit(1);
}
//Symbol Table functions
int GetMem(){
  return varcount;
}
void addMain(){
  gsnode *temp=(gsnode*)malloc(sizeof(gsnode));
  temp->dtype=getTSymbol("int");
  temp->name=(char*)malloc(strlen("main")*sizeof(char));
  strcpy(temp->name,"main");    
  temp->flabel=++fnid;
  temp->p=NULL;
  temp->n=NULL;
  Gtop=temp;
}
void addFDTypes(){
  tnode *temp=(tnode*)malloc(sizeof(tnode));
  temp->name=(char*)malloc(strlen("int")*sizeof(char));
  strcpy(temp->name,"int");
  temp->size=1;
  temp->decl=NULL;
  temp->n=NULL;
  TypeTop=temp;
  temp=(tnode*)malloc(sizeof(tnode));
  temp->name=(char*)malloc(strlen("str")*sizeof(char));
  strcpy(temp->name,"str");
  temp->size=1;
  temp->decl=NULL;
  temp->n=NULL;
  TypeTop->n=temp;
}
void GAllocate(node *id,node *type,int size){
  tnode *chk=getTSymbol(id->var);
  if(chk){
    printf("Declaration Error:Identifier '%s' has already been declared as Type name\n",id->var);
    Exit();
  }
  cnode *chek=getCSymbol(id->var);
  if(chek){
    printf("Declaration Error:Identifier '%s' has already been declared as Class name\n",chek->name);
    Exit();
  }
  gsnode *check=getGSymbol(id->var);
  if(check){
    printf("Declaration Error:Identifier '%s' has already been declared\n",id->var);
    Exit();
  }  
  gsnode *temp=(gsnode*)malloc(sizeof(gsnode));
  if(id->ntype==FUNCTION){    
    temp->dtype=getTSymbol(type->var);
    temp->name=(char*)malloc(strlen(id->var)*sizeof(char));
    strcpy(temp->name,id->var);    
    temp->flabel=++fnid;
    temp->p=PDeclare(id->r);
    temp->n=NULL;
  }
  else{
    temp->dtype=getTSymbol(type->var); 
    temp->ctype=getCSymbol(type->var);
    temp->flabel=id->dtype;
    temp->name=(char*)malloc(strlen(id->var)*sizeof(char));
    strcpy(temp->name,id->var);
    temp->size=size;  
    temp->bind=++varcount;
    varcount+=size-1;
    temp->n=NULL;
  }
  gsnode *end=Gtop;
  if(Gtop==NULL){
    Gtop=temp;
    return;
  }
  while(end->n)
    end=end->n;
  end->n=temp;
}
void GDeclare(node *Dnode,node *Lnode){
  if(!Gtop)
    addMain();  
  node *temp=Lnode;
  int s;
  while(temp){
    s=1;
    if(temp->r)
      if(temp->ntype==IDENTIFIER)
        s*=temp->r->val;
      else
        s=0;
    GAllocate(temp,Dnode,s);
    temp=temp->l;
  }
}
void LAllocate(lsnode **Ltop,char *id,node *type){  
  lsnode *temp=(lsnode*)malloc(sizeof(lsnode));
  tnode *chk=getTSymbol(id);
  if(chk){
    printf("Declaration Error:Identifier '%s' has already been declared as Type name\n",id);
    Exit();
  }
  cnode *chek=getCSymbol(id);
  if(chek){
    printf("Declaration Error:Identifier '%s' has already been declared as Class name\n",chek->name);
    Exit();
  }
  lsnode *check=getLSymbol(*Ltop,id);
  if(check){
    printf("Declaration Error:Identifier '%s' has already been declared\n",id);
    Exit();
  }
  chk=getTSymbol(type->var);
  if(!chk){
    printf("Declaration Error:'%s' not a Type name\n",type->var);
    Exit();
  }
  temp->dtype=chk;
  temp->name=(char*)malloc(strlen(id)*sizeof(char));
  strcpy(temp->name,id);
  temp->n=NULL;
  lsnode *end=*Ltop;
  if(end==NULL){
    *Ltop=temp;
    return;
  }
  while(end->n)
    end=end->n;
  end->n=temp;
}
void LDeclare(lsnode **Ltop,node *Dnode,node *Lnode){
  node *temp=Lnode;
  while(temp){
    LAllocate(Ltop,temp->var,Dnode);
    temp=temp->l;
  }
}
void addLocVar(lsnode **Ltop,node *line){  
  if(!line)
    return;  
  node *temp=line;
  while(temp){
    LDeclare(Ltop,temp->r,temp->e);
    temp=temp->l;
  }  
}
lsnode *PDeclare(node *decl){
  node *id=decl;
  lsnode *end,*Ltop=NULL;
  while(id){
    lsnode *temp=(lsnode*)malloc(sizeof(lsnode));
    lsnode *check=getLSymbol(Ltop,id->var);
    if(check){
      printf("Declaration Error:Identifier '%s' has already been declared\n",id->var);
      Exit();
    }
    tnode *chk=getTSymbol(id->var);
    if(chk){
      printf("Declaration Error:Identifier '%s' has already been declared as Type name\n",id->var);
      Exit();
    }
    cnode *chek=getCSymbol(id->var);
    if(chek){
      printf("Declaration Error:Identifier '%s' has already been declared as Class name\n",chek->name);
      Exit();
    }
    temp->name=(char*)malloc(strlen(id->var)*sizeof(char));
    strcpy(temp->name,id->var);
    chk=getTSymbol(id->r->var);
    if(chk)
      temp->dtype=chk;
    else{
      printf("Declaration Error:'%s' has not been defined as Type name\n",id->r->var);
      Exit();
    }
    temp->n=NULL;        
    if(Ltop==NULL){
      Ltop=temp;
      id=id->l;
      continue;
    }
    end=Ltop;  
    while(end->n)
      end=end->n;
    end->n=temp;
    id=id->l;
  }
  return Ltop;  
}
gsnode *getGSymbol(char *s){
    gsnode *temp=Gtop;
    while(temp){
        if(strcmp(temp->name,s)==0)
            return temp;
        temp=temp->n;
    }
    return NULL;
}
tnode *getTSymbol(char *s){
    tnode *temp=TypeTop;
    while(temp){
        if(strcmp(temp->name,s)==0)
            return temp;
        temp=temp->n;
    }
    return NULL;
}
lsnode *getLSymbol(lsnode *Ltop,char *s){
    lsnode *temp=Ltop;
    while(temp){
        if(strcmp(temp->name,s)==0)
          return temp;
        temp=temp->n;
    }
    return NULL;
}
char *getDtype(int type){
  char *s=(char*)malloc(3*sizeof(char));
  if(type==INTEGER)
    strcpy(s,"int");    
  else if(type==STRING)
    strcpy(s,"str");
  else
    strcpy(s,"N/A");
  return s;
}
void printGSymbols(){
    gsnode *temp=Gtop;
    printf("Global:");
    while(temp){
      if(temp->dtype)
        printf("%s ",temp->dtype->name);
      if(temp->ctype)
        printf("%s ",temp->ctype->name);
      printf("%s->",temp->name);
      temp=temp->n;
    }    
    printf("NULL\n");
}
void printTSymbols(){
  tnode *temp=TypeTop;
  printf("Type:\n");
  while(temp){
    printFSymbols(temp->name,temp->decl);
    temp=temp->n;
  }
  printf("EndType\n");
}
void printFSymbols(char *s,fnode *Ftop){
    fnode *temp=Ftop;
    printf("%s:",s);
    while(temp){
        printf("%s %s->",temp->dtype->name,temp->name);
        temp=temp->n;
    }    
    printf("NULL\n");
}
void printLSymbols(char *s,lsnode *Ltop){
    lsnode *temp=Ltop;
    printf("Local of %s():",s);
    while(temp){
        printf("%s %s->",temp->dtype->name,temp->name);
        temp=temp->n;
    }    
    printf("NULL\n");
}
void printPSymbols(char *s,lsnode *Ltop){
    lsnode *temp=Ltop;
    printf("Param of %s():",s);
    while(temp){
        printf("%s %s->",temp->dtype->name,temp->name);
        temp=temp->n;
    }    
    printf("NULL\n");
}
void bindFld(lsnode *Ltop,node *son){
  node *dad;
  tnode *dtype;
  cnode *ctype;
  fnode *field=NULL;cfnode *cfield=NULL;
  while(son->l){
    dad=son->l;
    printf("DAD:%s SON:%s",dad->var,son->var);    
    bindId(Ltop,&dad);   
    dtype=dad->dtype;ctype=dad->ctype;
    if(dtype){
      field=getFSymbol(dtype->decl,son->var);
      if(!field){
        printf("Type Error:'%s' does not have field named '%s'\n",dad->var,son->var);
        Exit();
      }
      son->ctype=NULL;
      son->dtype=field->dtype;
      son=son->l;
    }
    else if(ctype){           
        cfield=getcFSymbol(ctype->decl,son->var);
        if(!cfield){
          printf("Type Error:'%s' does not have field named '%s'\n",dad->var,son->var);
          Exit();
        }
        if(cfield->fnid==-1){
          printf("Type Error:Access denied to '%s.%s'\n",dad->var,son->var);
          Exit();
        }
        if(cfield->dtype)
          printf("Type:%s\n",cfield->dtype->name);
        if(cfield->ctype)
          printf("Class:%s\n",cfield->ctype->name);
        if(son->ntype==FUNCTION){
          printf("FNCALL:%s ",son->var);
          son->ctype=cfield->ctype;
          son->dtype=cfield->dtype;
          gsnode *P=(gsnode*)malloc(sizeof(gsnode));
          P->name=NULL;
          P->dtype=NULL;
          P->p=NULL;
          P->n=NULL;
          P->flabel=-1;
          P->size=-1;
          P->bind=MEMFN_PAR;
          P->ctype=(cnode*)malloc(sizeof(cnode));
          P->ctype->name=NULL;
          P->ctype->fdef=NULL;
          P->ctype->n=NULL;
          P->ctype->size=LOCALREF;
          P->ctype->decl=cfield->p; 
          son->sym=P;
        }
        son=son->l;
    }
    else
      return;
  }
}
void bindId(lsnode *Ltop,node **Id){
  node *id=*Id;
  if(id->val==FLD_CHILD){
    printf("child:%s\n",id->var);
    bindFld(Ltop,id);
    return;
  }
  lsnode *T=getLSymbol(Ltop,id->var);
  if(T){
    printf("local:%s\n",id->var);
    id->dtype=T->dtype;
    id->l=NULL;
    id->r=NULL;
    id->val=VARIABLE;
    id->sym=(gsnode*)malloc(sizeof(gsnode));
    id->sym->size=LOCALREF;
    id->sym->p=T;
  }
  else{
    gsnode *t=getGSymbol(id->var);
    if(t){
      printf("global:%s ",t->name);
      int rmax=t->size;
      if(t->dtype)
      printf("Type:%s->\n",t->dtype->name);
      if(t->ctype)
      printf("Class:%s->\n",t->ctype->name);      
      id->dtype=t->dtype;
      id->ctype=t->ctype;
      node *size=id->l;
      id->r=NULL;
      id->val=VARIABLE;
      if(rmax>1){
        id->val=ARRAY;
      }
      if(t->flabel==PTR)
        id->val=POINTER;
      id->sym=t;
      if(id->val==ARRAY){
        if(size){
          finalize(Ltop,size);
          if(compareDType(size->dtype,getTSymbol("int"))){
            printf("Index Error:Expected Integer Value\n");
            Exit();
          }    
          if(size->ntype==CONSTANT&&size->val>=rmax){
            printf("Index Error:Index value is more than size of array\n");
            Exit();
          }
        }
        else{
          printf("Index Error:Index of array '%s' has not been specified\n",id->var);
          Exit();
        }
      }
      else
        if(size){
          printf("Index Error:Identifier '%s' is not an array\n",id->var);
          Exit();
        }
    }
    else{
      printf("Declaration Error:Identifier '%s' has not been declared in this scope\n",id->var);
      Exit();
    }
  }
}
void bindVar(lsnode *Ltop,node *body){
  if(body->ntype==DMA_NEW){
      printf("new(%s)\n",body->l->var);
      return;
  }
  if(body->ntype==IDENTIFIER){
    printf("ID:%s ",body->var);
    bindId(Ltop,&body);
  }
  else if(body->ntype==FUNCTION){
    printf("Fn:%s ",body->var);
    if(body->val==FLD_CHILD){
      bindId(Ltop,&body);
      cfnode *temp1=NULL;
      if(body->sym)
        temp1=body->sym->ctype->decl;
      node *temp2=body->r;
      while(temp1){
        bindVar(Ltop,temp2);
        checkTypeError(temp2);
        if(compareDType(temp1->dtype,temp2->dtype)){
          printf("Type Mismatch Error:Argument %s has been defined as %s but declared as %s\n",temp1->name,temp1->dtype->name,temp2->dtype->name);
          Exit();
        }
        temp1=temp1->n;
        temp2=temp2->e;
      }      
      prntArg(body->r);
      return;
    }
    lsnode *temp1=body->sym->p;    
    node *temp2=body->l;
    while(temp1){
      bindVar(Ltop,temp2);
      checkTypeError(temp2);
      if(compareDType(temp1->dtype,temp2->dtype)){
        printf("Type Mismatch Error:Argument %s has been defined as %s but declared as %s\n",temp1->name,temp1->dtype->name,temp2->dtype->name);
        Exit();
      }
      temp1=temp1->n;
      temp2=temp2->e;
    }
    //prntArg(body->l);
    return;
  }
  else
  {
    if(body->l)bindVar(Ltop,body->l);
    if(body->r)bindVar(Ltop,body->r);
    if(body->e)bindVar(Ltop,body->e);
  }  
}

void showVar(node *body){
  if(body->ntype==IDENTIFIER){
    if(body->sym->p)
      printf("%s %s, ",body->dtype->name,body->sym->p->name);
    else if(body->sym)
      printf("%s %s, ",body->dtype->name,body->sym->name);
  }
  else
  {
    if(body->l)showVar(body->l);
    if(body->r)showVar(body->r);
    if(body->e)showVar(body->e);
    printf("\n");
  }  
}
void checkUDtype(node *root){
  if(root->dtype){
    if(compareDType(root->dtype,getTSymbol("int"))&&compareDType(root->dtype,getTSymbol("str")))
      return;
  }
  if(root->ctype)
    return;    
  printf("Type Error:'%s' is not a user defined type variable\n",root->var);
  Exit();
}
//Node creation and linking functions
cnode *checkCTypeError(node *root){
  //printf("NType:%d",root->ntype);
  switch(root->ntype){
    case IDENTIFIER:
      if(!root->dtype)
        return root->ctype;
      else
        return NULL;
    case DMA_NEW:
        return getCSymbol(root->l->var);
    default:
      return NULL;
  }
}
void CheckCTErr(cnode *c1,cnode *c2){
  if(c1!=c2){
    printf("Type Error:Expected %s not %s\n",c1->name,c2->name);
    Exit();
  }
  return;
}
tnode* checkTypeError(node *root){
  int ntype1,ntype2;
  tnode *type1,*type2,*type;
  cnode *ct1,*ct2;   
  switch (root->ntype)
  { case CONSTANT:
      return root->dtype;
    case OPERATOR:      
      type1=checkTypeError(root->l);
      ct1=checkCTypeError(root->l);
      type=assgnType(root);
      ntype1=root->l->ntype;
      if(type1==NULL){
        printf("Ctype1 %s\n",root->l->var);
        if(strcmp(root->var,"!")){
          ntype2=root->r->ntype;          
          if(strcmp(root->var,"=")){
            if(ntype2==DMANULL){
              checkUDtype(root->l);
              ct2=ct1;
            }
            else{
              type2=checkTypeError(root->r);
              ct2=checkCTypeError(root->r);
              if(type2){
                printf("Type Error:Expected class object\n");
                Exit();
              }
              printf("Ctype2 ");
              if(ntype2!=40)
                  printf("%s\n",root->r->var);
                else
                  printf("new()\n");    
              CheckCTErr(ct1,ct2);
              return NULL;
            }            
          }     
          else
            switch(ntype2){
              case DMANULL:
                checkUDtype(root->l);
                ct2=ct1;
                break;
              case DMA_NEW:
                ct2=checkCTypeError(root->r);
                printf("Ctype2 ");
                if(ntype2!=40)
                  printf("%s\n",root->r->var);
                else
                  printf("new()\n");    
                CheckCTErr(ct1,ct2);
                return NULL;
              default:
                type2=checkTypeError(root->r);
                ct2=checkCTypeError(root->r);
                if(type2){
                  printf("Type Error:Expected class object\n");
                  Exit();
                }
                printf("Ctype2 ");
                if(ntype2!=40)
                  printf("%s\n",root->r->var);
                else
                  printf("new()\n");                
                CheckCTErr(ct1,ct2);
                return NULL;
            }
        }
      }
      if(strcmp(root->var,"!")){
        ntype2=root->r->ntype;        
        if(strcmp(root->var,"=")){
          if(ntype2==DMANULL){
            checkUDtype(root->l);
            type2=type1;
          }
          else{
            type2=checkTypeError(root->r);
            ct2=checkCTypeError(root->r);
            if(type2==NULL){
              printf("Type Error:Expected non-class object\n");
              Exit();
            }
          }
        }       
        else
          switch(ntype2){
            case DMANULL:
              checkUDtype(root->l);
              type2=type1;
              break;
            case DMAFNS:
              type2=checkTypeError(root->r);
              if(!type2){
                type2=root->r->dtype=type1;
              }
              break;
            case DMA_NEW:
            default:
              type2=checkTypeError(root->r);
              ct2=checkCTypeError(root->r);
              if(!type2){
                printf("Typee Error:Expected non-class object %d\n",ntype2);
                Exit();
              }
          }          
      }    
      else{
        if(ntype1==OPERATOR&&compareDType(type1,type)){
          printf("Type Mismatch Error:Expected Boolean3\n");
          Exit();
        }
        root->dtype=boolType();
        return root->dtype;
      }            
      if(root->var[0]=='L'){
        type=boolType();
      }
      if(!compareDType(type,boolType())){
        if(root->var[0]=='L')
          if((ntype1==OPERATOR&&compareDType(type1,type))||(ntype2==OPERATOR&&compareDType(type2,type))){
            printf("Type Mismatch Error:Expected Boolean\n");
            Exit();
          }
          if((ntype1!=OPERATOR&&ntype2!=OPERATOR)&&compareDType(type1,type2)){
            printf("Type Mismatch Error:Expected Boolean\n");
            Exit();
          }
        root->dtype=boolType();
      }
      else{
        if(compareDType(type2,type1)){
          printf("Type Mismatch Error:Expected %s after %s\n",type1->name,root->var);
          Exit();
        }
        root->dtype=type1;
      }
      return root->dtype;
    case CONTROL:
      if(root->val==SIMPLE_IF||root->val==WHILE_LOOP){
        checkTypeError(root->l);
        if(!(root->l->dtype)){
          printf("Type Mismatch Error:Expected Boolean\n");
          Exit();
        }
        if(compareDType(root->l->dtype,boolType())){
          printf("Type Mismatch Error:Expected Boolean\n");
          Exit();
        }
      }
      if(root->val==REPEAT_LOOP||root->val==DO_LOOP){
        checkTypeError(root->r);
        if(!(root->r->dtype)){
          printf("Type Mismatch Error:Expected Boolean\n");
          Exit();
        }
        if(compareDType(root->r->dtype,boolType())){
          printf("Type Mismatch Error:Expected Boolean\n");
          Exit(); 
        }
      } 
    case IDENTIFIER:
      if(root->dtype)
        return root->dtype;
      else
        return NULL;
    case FUNCTION:
      return root->dtype;
    case DMAFNS:
      switch(root->val){
        case DMA_ALLOC:
          return NULL;
        case DMA_NEW:
          return NULL;
        case DMA_INIT:
          return getTSymbol("int");
        case DMA_FREE:
          checkUDtype(root->l);
          return getTSymbol("int");
      }
    default:
      if(root->l)checkTypeError(root->l);
      if(root->r)checkTypeError(root->r);
      if(root->e)checkTypeError(root->e);
      return 0;
  }  
 return NULL;
}
tnode *assgnType(node *root){
  if(root->ntype==CONSTANT||root->ntype==IDENTIFIER||root->ntype==FUNCTION)
    return root->dtype;
  else
    if(root->ntype==OPERATOR)
      if(root->var[1]=='\0')
        switch(root->var[0]){
          case '+':
          case '-':
          case '*':
          case '/':
          case '=':
            return assgnType(root->l);
          default:
            return boolType();
        }
      else 
        if(root->var[0]=='%')
          return assgnType(root->l);
        else
          return boolType();
    else
      return NULL;
}
int checkRetType(tnode *r,node *c){
  int i=0;
  if(c->ntype==JMP){
    if(c->val==RETURN_FN){
      node *ret=c->l;
      if(compareDType(ret->dtype,r)){
        printf("Type Mismatch Error:%s cannot be returned to %s\n",c->l->dtype->name,r->name);
        Exit();
      }
      i=1;
    }
    else{
        
        if(c->l)i=checkRetType(r,c->l);
        if(c->r)i+=checkRetType(r,c->r);
        if(c->e)i+=checkRetType(r,c->e);
    }
  }
  else
  {   
      if(c->l)i=checkRetType(r,c->l);
      if(c->r)i+=checkRetType(r,c->r);
      if(c->e)i+=checkRetType(r,c->e);
  }
  return i;
}
lsnode *parAllocate(lsnode *p){
  lsnode *id=p,*end,*Ltop=NULL;
  while(id){
    lsnode *temp=(lsnode*)malloc(sizeof(lsnode));
    temp->name=(char*)malloc(strlen(id->name)*sizeof(char));
    strcpy(temp->name,id->name);
    temp->dtype=id->dtype;
    temp->n=NULL;        
    if(Ltop==NULL){
      Ltop=temp;
      id=id->n;
      continue;
    }
    end=Ltop;  
    while(end->n)
      end=end->n;
    end->n=temp;
    id=id->n;
  }
  return Ltop;
}
int compareDType(tnode *t1,tnode *t2){
  if(strcmp(t1->name,t2->name))
    return 1;
  else
    return 0;
}
node *makeFnDefNode(node *rtype,node *fname,node *pTop,node *lDecl,node *code){
  gsnode *fdecl=getGSymbol(fname->var);
  lsnode *Ltop=NULL;
  tnode *type=getTSymbol(rtype->var);  
  if(!fdecl){
    if(strcmp(fname->var,"main")){
      printf("Declaration Error:%s() has not been declared\n",fname->var);
      Exit();
    }
    addMain();
    fdecl=getGSymbol(fname->var);
  }
  if(compareDType(fdecl->dtype,type)){
    printf("Declaration Error:%s() has conflicting return types DECL:%s and DEF:%s\n",fname->var,fdecl->dtype->name,rtype->var);
    Exit();
  }
  if(pTop||fdecl->p){
    if(!pTop){
      printf("Definition Error:%s() expects some argument(s)\n",fname->var);
      Exit();
    }
    if(!fdecl->p){
      printf("Definition Error:Declaration of %s() contains no arguments\n",fname->var);
      Exit();
    }    
    checkNameEquivalence(fdecl->p,PDeclare(pTop));
    Ltop=parAllocate(fdecl->p);    
    fname->sym=fdecl;         
  }
  addLocVar(&Ltop,lDecl);   
  fname->ntype=FUNCTION;  
  if(strcmp(fname->var,"main"))
    fname->val=FN_USER;  
  else
    fname->val=FN_DRVR;  
  finalize(Ltop,code);
  if(!checkRetType(type,code)){
    printf("Need to include return\n");
    Exit();
  }
  fname->r=code;
  {
    node *L=(node*)malloc(sizeof(node));
    L->l=NULL;
    L->r=NULL;
    L->e=NULL;
    L->ntype=LST;
    L->sym=(gsnode*)malloc(sizeof(gsnode));
    L->sym->size=LOCALREF;
    L->sym->p=Ltop;
    fname->e=L;  
  }
  printf("FN %s done\n",fname->var);
  return fname; 
}
void finalize(lsnode *Ltop,node *code){
  bindVar(Ltop,code);
  checkTypeError(code);
}
node *makeRetNode(node *retvalue){
  node *p=(node*)malloc(sizeof(node));
  p->val=RETURN_FN;
  p->ntype=JMP;
  p->l=retvalue;
  p->r=NULL;
  p->e=NULL;
  return p;
}
void checkNameEquivalence(lsnode *formal,lsnode *actual){
  lsnode *temp1=formal,*temp2=actual;
  while(temp1){
    if(!temp2){
      printf("Definition Error:Expecting more arguments in definition of function\n");
      Exit();
    }
    if(strcmp(temp1->name,temp2->name)){
      printf("Definition Error:Arguments in definition and declaration don't match\n");
      Exit();
    }
    if(compareDType(temp1->dtype,temp2->dtype)){
      printf("Definition Error:Argument %s has conflicting types in definition and declaration\n",temp1->name);
      Exit();
    }
    temp1=temp1->n;
    temp2=temp2->n;
  }
  if(temp2){
    printf("Definition Error:Unexpected arguments in definition of function\n");
    Exit();
  }
}
node *makeOpNode(char *op,node *left,node *right){
  node *p=(node*)malloc(sizeof(node));
  p->var=(char*)malloc(strlen(op)*sizeof(char));
  strcpy(p->var,op);
  p->ntype=OPERATOR;
  p->dtype=NULL;
  p->l=left;
  p->r=right;
  p->e=NULL;
  return p;
}
node *makeNumNode(int n){
  node *p=(node*)malloc(sizeof(node));
  p->dtype=getTSymbol("int");
  p->ntype=CONSTANT;
  p->val=n;
  p->l=NULL;
  p->r=NULL;
  p->e=NULL;
  return p;
}
node *makeStrNode(char *s){
  node *p=(node*)malloc(sizeof(node));
  p->dtype=getTSymbol("str");
  p->ntype=CONSTANT;
  p->var=(char*)malloc(strlen(s)*sizeof(char));
  strcpy(p->var,s);
  p->l=NULL;
  p->r=NULL;
  p->e=NULL;
  return p;
}
node *makeALocDecLine(node *type,node *list){
  node *p=(node*)malloc(sizeof(node));
  p->ntype=LDECLARE;
  p->r=type;
  p->e=list;
  p->l=NULL;
  return p;
}
node *makeUNode(node *left,node *right,int type){
  node *p=(node*)malloc(sizeof(node));
  p->ntype=JMP;
  p->dtype=type;
  p->l=left;
  p->r=right;
  p->e=NULL;
  return p;
}
node *makeIdNode(char *id){
  node *p=(node*)malloc(sizeof(node));
  p->ntype=IDENTIFIER;
  p->var=(char*)malloc(strlen(id)*sizeof(char));
  strcpy(p->var,id);
  p->l=NULL;
  p->r=NULL;
  p->e=NULL;
  return p;
}
node *makeGDeclLineNode(node *prev,node *id,node *rows){
  id->l=NULL;
  id->r=rows;
  id->e=NULL;
  id->dtype=NULL;
  node *end=prev;
  if(end==NULL){
    return id;
  }
  while(end->l){
    end=end->l;
  }
  end->l=id;
  return prev;
}
node *makeParamLinkNode(node *prev,node *type,node *id){
  id->r=type;
  id->l=NULL;
  id->e=NULL;
  node *end=prev;
  if(end==NULL){
    return id;
  }  
  while(end->l){
    end=end->l;
  }
  end->l=id;
  return prev;
}
node *makeFnDefLinkNode(node *prev,node *def){
  node *end=prev;
  if(end==NULL){
    return def;
  }  
  while(end->l){
    end=end->l;
  }
  end->l=def;
  return prev;
}
node *linkFnWithArg(lsnode *par,node *arg){
  lsnode *temp1=par,*Ltop;
  node *temp2=arg;
  while(temp1){
    if(!temp2){
      printf("Function Call Error:Expecting more arguments in function call\n");
      Exit();
    }
    temp1=temp1->n;
    temp2=temp2->e;
  }
  if(temp2){
    printf("Function Call Error:Unexpected arguments in function call\n");
    Exit();
  }
  return arg;
}
node *makeFnCallNode(node *fn,node *arg){
  gsnode *check=getGSymbol(fn->var);
  if(!check){
    printf("Declaration Error:Function %s() has not been declared\n",fn->var);
    Exit();
  }
  fn->ntype=FUNCTION;
  fn->dtype=check->dtype;
  fn->val=FN_CALL;
  fn->l=NULL;
  fn->r=NULL;
  fn->e=NULL;
  fn->sym=check;
  lsnode *par=check->p;
  fn->l=linkFnWithArg(par,arg);   
  return fn;
}
node *makeMemFnCallNode(node *fn,node *arg){
  fn->ntype=FUNCTION;
  fn->dtype=NULL;
  fn->ctype=NULL;
  fn->val=FN_CALL;
  fn->l=NULL;
  fn->e=NULL;
  fn->sym=NULL;
  fn->r=arg;   
  return fn;
}
void prntArg(node *start){
  node *end=start;
  while(end){
    if(end->ntype==IDENTIFIER)
      printf("%s %s,",end->dtype->name,end->var);
    if(end->ntype==CONSTANT)
      if(end->dtype==STRING)
        printf("%s %s,",end->dtype->name,end->var);
      else
        printf("%s %d,",end->dtype->name,end->val);
    end=end->e;
  }
  printf("\b \n");
}
node *makeArgLinkNode(node *prev,node *arg){
  node *end=prev;
  if(end==NULL)
    return arg;
  while(end->e)
    end=end->e;
  end->e=arg;
  return prev;
}
node *linkLDecLines(node *prev,node *line){
  node *end=prev;
  if(end==NULL){
    return line;
  }
  while(end->l){
    end=end->l;
  }
  end->l=line;
  return prev;
}
node *makeLDeclLineNode(node *prev,node *id){
  id->l=NULL;
  id->r=NULL;
  id->e=NULL;
  node *end=prev;
  if(end==NULL){
    return id;
  }
  while(end->l){
    end=end->l;
  }
  end->l=id;
  return prev;
}
node *makeFnLinkNode(node *prev,node *id,node *param){
  id->l=NULL;
  id->r=param;
  id->ntype=FUNCTION;
  id->e=NULL;
  node *end=prev;
  if(end==NULL){
    return id;
  }
  while(end->l){
    end=end->l;
  }
  end->l=id;
  return prev;
}
node *makeIONode(int fcode,node *arg){
  node *p=(node*)malloc(sizeof(node));
  p->val=fcode;
  p->ntype=IO;
  p->l=arg;
  p->r=NULL;
  p->e=NULL;
  return p;
}
node *makeConNode(node *left,node *right){
  node *p=(node*)malloc(sizeof(node));
  p->ntype=CONNECTION;
  p->l=left;
  p->r=right;
  p->e=NULL;
  return p;
}
node *makeCtrlNode(node *left,node *right,node *Else,int type){
  node *p=(node*)malloc(sizeof(node));
  p->ntype=CONTROL;
  p->val=type;
  p->l=left;
  p->r=right;
  p->e=Else;
  return p;
}
node *makeDType(node *type){
  if(!TypeTop)
    addFDTypes();
  node *p=(node*)malloc(sizeof(node));
  p->ntype=DATATYPE;
  p->l=NULL;
  p->r=NULL;
  p->e=NULL;
  p->var=(char*)malloc(strlen(type->var)*sizeof(char));
  strcpy(p->var,type->var);
  return p;
}
node* linkIdNode(node *id,node *size){
  id->dtype=NULL;
  id->l=size;
  id->r=NULL;
  id->val=VARIABLE;
  id->sym=NULL;
  return id;
}
void createNewDType(node *type,node *def){ 
  if(!TypeTop)
    addFDTypes(); 
  tnode *check=getTSymbol(type->var);
  if(check){
    printf("Declaration Error:Type '%s' has already been declared\n",type->var);
    Exit();
  }
  if(!def)
    return;
  tnode *temp=(tnode*)malloc(sizeof(tnode)),*chk;
  node *line=def;
  fnode *Ftop=NULL;
  int s=0;
  while(line){
    chk=getTSymbol(line->r->var);
    if(!chk&&strcmp(line->r->var,type->var)){
      printf("Declaration Error:Type '%s' has not been declared\n",line->r->var);
      Exit();
    }
    s+=FDeclare(&Ftop,line->r,line->e);    
    line=line->l;
  }  
  temp->name=(char*)malloc(strlen(type->var)*sizeof(char));
  strcpy(temp->name,type->var);
  temp->decl=Ftop;
  if(s>HB_SIZE){
    printf("TypeError:Size of '%s' has exceeded HB_SIZE\n",temp->name);
    Exit();
  }
  temp->size=s;
  temp->n=NULL;
  tnode *end=TypeTop;
  if(TypeTop==NULL){
    TypeTop=temp;
    fnode *e=Ftop;
    while(e){
      if(strcmp(e->name,type->var)==0){
        printf("Declaration Error:Identifier '%s' has already been declared as Type name\n",e->name);
        Exit();
      }
      if(e->dtype==NULL){
        chk=getTSymbol(type->var);
        e->dtype=chk;
      }
      e=e->n;
    }
    return;
  }
  while(end->n)
    end=end->n;
  end->n=temp;
  fnode *e=Ftop;
  while(e){
    if(strcmp(e->name,type->var)==0){
      printf("Declaration Error:Identifier '%s' has already been declared as Type name\n",e->name);
      Exit();
    }
    if(e->dtype==NULL){
      chk=getTSymbol(type->var);
      e->dtype=chk;
    }
    e=e->n;
  }
}
node *makeNullNode(){
  node *p=(node*)malloc(sizeof(node));
  p->ntype=DMANULL;
  p->dtype=NULL;
  p->l=NULL;
  p->r=NULL;
  p->e=NULL;
  return p;
}
fnode *getFSymbol(fnode *Ftop,char *s){
    fnode *temp=Ftop;
    while(temp){
        if(strcmp(temp->name,s)==0)
          return temp;
        temp=temp->n;
    }
    return NULL;
}
void FAllocate(fnode **Ftop,char *id,node *type){  
  tnode *chk=getTSymbol(id);
  if(chk){
    printf("Declaration Error:Identifier '%s' has already been declared as Type name\n",chk->name);
    Exit();
  }
  fnode *check=getFSymbol(*Ftop,id);
  if(check){
    printf("Declaration Error:Identifier '%s' has already been declared\n",check->name);
    Exit();
  }  
  fnode *temp=(fnode*)malloc(sizeof(fnode));
  chk=getTSymbol(type->var);
  temp->dtype=NULL;
  if(chk){
    temp->dtype=chk;
  }
  temp->name=(char*)malloc(strlen(id)*sizeof(char));
  strcpy(temp->name,id);
  int i=0;
  temp->n=NULL;
  fnode *end=*Ftop;
  if(end==NULL){
    *Ftop=temp;
    return;
  }
  while(end->n)
    end=end->n;
  end->n=temp;
  end=*Ftop;
  while(end){
    end->ind=i++;
    end=end->n;
  }
}
int FDeclare(fnode **Ftop,node *Dnode,node *Lnode){
  node *temp=Lnode;
  int s=0;
  while(temp){
    FAllocate(Ftop,temp->var,Dnode);
    temp=temp->l;
    s++;
  }
  return s;
}
tnode *boolType(){
  tnode *temp=(tnode*)malloc(sizeof(tnode));
  temp->name=(char*)malloc(strlen("_boolean")*sizeof(char)); 
  strcpy(temp->name,"_boolean");
  temp->decl=NULL;
  temp->size=1;
  temp->n=NULL;
  return temp;
}
node *linkFldNode(node *parent,node *child){  
  if(!parent->l)
    parent->val=FLD_PARENT;
  child->l=parent;
  child->val=FLD_CHILD;
  return child;
}
node *makeNode4DMA(int dtype){
  node *p=(node*)malloc(sizeof(node));
  p->ntype=DMAFNS;
  p->dtype=NULL;
  p->val=dtype;
  p->l=NULL;
  p->r=NULL;
  p->e=NULL;
  return p;
}
node *makeNode4DMAFree(node *fld){
  node *p=(node*)malloc(sizeof(node));
  p->ntype=DMAFNS;
  p->dtype=NULL;
  p->val=DMA_FREE;
  p->l=fld;
  p->r=NULL;
  p->e=NULL;
  return p;
}
node *makeMemFnNode(node *rtype,node *fname,node *pTop,node *lDecl,node *code){
  node *MF=(node*)malloc(sizeof(node));
  MF->ntype=FNDEFNS;
  node *Mfr=(node*)malloc(sizeof(node));
  Mfr->ntype=FNDEFNSr;
  node *Mfe=(node*)malloc(sizeof(node));
  Mfe->ntype=FNDEFNSe;
  Mfr->l=NULL;
  Mfr->r=rtype;
  Mfr->e=pTop;
  Mfe->l=fname;
  Mfe->r=lDecl;
  Mfe->e=code;
  MF->l=NULL;
  MF->r=Mfr;
  MF->e=Mfe;
  return MF; 
}
void createNewClass(node *type,node *decl,node *FDefns){ 
  tnode *check=getTSymbol(type->var);
  if(check){
    printf("Declaration Error:Type '%s' has already been declared\n",type->var);
    Exit();
  }
  cnode *chek=getCSymbol(type->var);
  if(check){
    printf("Declaration Error:Class '%s' has already been declared\n",type->var);
    Exit();
  }
  if(!decl)
    return;
  cnode *temp=(cnode*)malloc(sizeof(cnode));
  node *line=decl;cfnode *Ftop=NULL;int s=0;
  while(line){
    check=getTSymbol(line->r->var);
    if(!check){
      chek=getCSymbol(line->r->var);
      if(!chek&&strcmp(line->r->var,type->var)){
        printf("Declaration Error:Type '%s' has not been declared\n",line->r->var);
        Exit();
      }
    }
    s+=CFDeclare(&Ftop,line->r,line->e,type->var);
    line=line->l;
  }
  node *FDtop=DefineMemFns(Ftop,FDefns,type->var);
  temp->name=(char*)malloc(strlen(type->var)*sizeof(char));
  strcpy(temp->name,type->var);
  temp->decl=Ftop;
  if(s>HB_SIZE){
    printf("TypeError:Size of '%s' has exceeded HB_SIZE\n",temp->name);
    Exit();
  }
  temp->size=s;
  temp->n=NULL;
  cnode *end=ClassTop;
  if(ClassTop==NULL){
    ClassTop=temp;    
    cfnode *e=Ftop;
    while(e){
      if(strcmp(e->name,type->var)==0){
        printf("Declaration Error:Identifier '%s' has already been declared as Class name\n",e->name);
        Exit();
      }
      if(e->dtype==NULL&&e->ctype==NULL){
        chek=getCSymbol(type->var);
        e->ctype=chek;
      }
      e=e->n;
    }
    node *fend=FDtop;
    while(fend){
      finalizeMF(ClassTop,fend);
      fend=fend->l;
    }
    printcFSymbols(type->var,Ftop);
    return;
  }
  while(end->n)
    end=end->n;
  end->n=temp;
  cfnode *e=Ftop;
  while(e){
    if(strcmp(e->name,type->var)==0){
      printf("Declaration Error:Identifier '%s' has already been declared as Class name\n",e->name);
      Exit();
    }
    if(e->dtype==NULL&&e->ctype==NULL){
      chek=getCSymbol(type->var);
      e->ctype=chek;
    }
    e=e->n;    
  }
  node *fend=FDtop;
    while(fend){
      finalizeMF(getCSymbol(type->var),fend);
      fend=fend->l;
    }
  printcFSymbols(type->var,Ftop);
}
void CFAllocate(cfnode **Ftop,node *id,node *type,char *cname){
  tnode *chk=getTSymbol(id->var);
  if(chk){
    printf("Declaration Error:Identifier '%s' has already been declared as Type name\n",chk->name);
    Exit();
  }
  cnode *chek=getCSymbol(id->var);
  if(chek){
    printf("Declaration Error:Identifier '%s' has already been declared as Class name\n",chek->name);
    Exit();
  }
  cfnode *check=getcFSymbol(*Ftop,id->var);  
  if(check){
    printf("Declaration Error:Identifier '%s' has already been declared\n",check->name);
    Exit();
  }
  cfnode *temp=(cfnode*)malloc(sizeof(cfnode));int i=0;
  if(id->ntype==FUNCTION){
    tnode *chk=getTSymbol(type->var);
    if(!chk){
      printf("Declaration Error:Class '%s' cannot be return type\n",type->var);
      Exit();
    }
    temp->dtype=chk;
    temp->ctype=NULL;
    temp->name=(char*)malloc(strlen(id->var)*sizeof(char));
    strcpy(temp->name,id->var);    
    temp->p=cPDeclare(id->r,cname);
    printcPSymbols(temp->name,temp->p);
    temp->n=NULL;
    temp->ind=-1;
    cfnode *end=*Ftop;
    if(*Ftop==NULL){
      temp->fnid=0;
      *Ftop=temp;
      return;
    }
    if(end->ind==-1)
        i++;
    while(end->n){
      end=end->n;
      if(end->ind==-1)
        i++;
    }
    temp->fnid=i++;
    end->n=temp;
    if(i>MF_LIMIT){
      printf("TypeError:Maximum number of functions exceeded in class\n");
      Exit();
    } 
    return;
  }  
  chk=getTSymbol(type->var);   
  temp->dtype=NULL;temp->ctype=NULL;
  if(chk)
    temp->dtype=chk;
  else{
    cnode *chek=getCSymbol(type->var); 
    if(chek)
      temp->ctype=chek;
  }
  if(temp->dtype==NULL&&temp->ctype==NULL)
    printf("SelfCType:%s\n",type->var);
  temp->name=(char*)malloc(strlen(id->var)*sizeof(char));
  strcpy(temp->name,id->var);    
  temp->n=NULL;
  temp->p=NULL;
  temp->fnid=-1;
  cfnode *end=*Ftop;
  if(end==NULL){
    temp->ind=0;
    *Ftop=temp;
    return;
  }
  if(end->fnid==-1)
        i++;
  while(end->n){
    end=end->n;
    if(end->fnid==-1)
      i++;
  }
  temp->ind=i;
  end->n=temp;
}
void CLfAllocate(cfnode **Ltop,char *id,node *type,char *cname){  
  cfnode *temp=(cfnode*)malloc(sizeof(cfnode));
  tnode *chk=getTSymbol(id);
  if(chk){
    printf("Declaration Error:Identifier '%s' has already been declared as Type name\n",chk->name);
    Exit();
  }
  cnode *chek=getCSymbol(id);
  if(chek||strcmp(id,cname)==0){
    printf("Declaration Error:Identifier '%s' has already been declared as Class name\n",id);
    Exit();
  }
  cfnode *check=getcFSymbol(*Ltop,id);
  if(check){
    printf("Declaration Error:Identifier '%s' has already been declared\n",id);
    Exit();
  }
  chk=getTSymbol(type->var);
  if(!chk){
    chek=getCSymbol(type->var);
    if(chek||strcmp(type->var,cname)==0){
      printf("Declaration Error:Class(%s) variable cannot be declared locally\n",type->var);
      Exit();
    }
    printf("Declaration Error:Undefined Type '%s'\n",type->var);
    Exit();
  }
  temp->dtype=chk;
  temp->name=(char*)malloc(strlen(id)*sizeof(char));
  strcpy(temp->name,id);
  temp->ctype=NULL;
  temp->fnid=-1;
  temp->p=NULL;
  temp->n=NULL;
  cfnode *end=*Ltop;
  if(end==NULL){
    *Ltop=temp;
    return;
  }
  while(end->n)
    end=end->n;
  end->n=temp;
}
int CFDeclare(fnode **Ftop,node *Dnode,node *Lnode,char *cname){
  node *temp=Lnode;
  int s=0;
  while(temp){
    CFAllocate(Ftop,temp,Dnode,cname);
    if(temp->ntype!=FUNCTION)
      s++;
    temp=temp->l;    
  }
  return s;
}
void CLfDeclare(cfnode **Ltop,node *Dnode,node *Lnode,char *cname){
  node *temp=Lnode;
  while(temp){
    CLfAllocate(Ltop,temp->var,Dnode,cname);
    temp=temp->l;
  }
}
cfnode *getcFSymbol(cfnode *Ftop,char *s){
    cfnode *temp=Ftop;
    while(temp){
        if(strcmp(temp->name,s)==0)
          return temp;
        temp=temp->n;
    }
    return NULL;
}
cnode *getCSymbol(char *s){
    cnode *temp=ClassTop;
    while(temp){
        if(strcmp(temp->name,s)==0)
            return temp;
        temp=temp->n;
    }
    return NULL;
}
cfnode *cPDeclare(node *decl,char *cname){
  node *id=decl;
  cfnode *end,*Ltop=NULL;
  while(id){
    cfnode *temp=(cfnode*)malloc(sizeof(cfnode));
    tnode *chk=getTSymbol(id->var);
    if(chk){
      printf("Declaration Error:Identifier '%s' has already been declared as Type name\n",chk->name);
      Exit();
    }
    cnode *chek=getCSymbol(id->var);
    if(chek||strcmp(id->var,cname)==0){
      printf("Declaration Error:Identifier '%s' has already been declared as Class name\n",id->var);
      Exit();
    }
    cfnode *check=getcFSymbol(Ltop,id->var);
    if(check){
      printf("Declaration Error:Identifier '%s' has already been declared\n",id->var);
      Exit();
    }
    temp->name=(char*)malloc(strlen(id->var)*sizeof(char));
    strcpy(temp->name,id->var);
    chk=getTSymbol(id->r->var);
    if(chk)
      temp->dtype=chk;
    else{
      printf("Declaration Error:'%s' has not been defined as Type name\n",id->r->var);
      Exit();
    }
    temp->ctype=NULL;
    temp->n=NULL;
    temp->p=NULL;
    temp->fnid=-1;
    if(Ltop==NULL){
      Ltop=temp;
      id=id->l;
      continue;
    }
    end=Ltop;  
    while(end->n)
      end=end->n;
    end->n=temp;
    id=id->l;
  }
  return Ltop;  
}
void printcFSymbols(char *s,cfnode *Ftop){
    cfnode *temp=Ftop;
    printf("%s:",s);
    while(temp){    
      if(temp->dtype)  
        printf("%s ",temp->dtype->name);
      else if(temp->ctype)
        printf("%s ",temp->ctype->name);
      printf("i:%d f:%d %s->",temp->ind,temp->fnid,temp->name);
      temp=temp->n;
    } 
    printf("NULL\n");
}
void printcPSymbols(char *s,cfnode *Ltop){
    cfnode *temp=Ltop;
    printf("Param of %s():",s);
    while(temp){
        printf("%s i:%d f:%d %s->",temp->dtype->name,temp->ind,temp->fnid,temp->name);
        temp=temp->n;
    }
    printf("NULL\n");
}
void checkMEMNameEquivalence(cfnode *f,cfnode *a){
  cfnode *temp1=f,*temp2=a;
  while(temp1){
    if(!temp2){
      printf("Definition Error:Expecting more arguments in definition of function\n");
      Exit();
    }
    if(strcmp(temp1->name,temp2->name)){
      printf("Definition Error:Arguments in definition and declaration don't match\n");
      Exit();
    }
    if(compareDType(temp1->dtype,temp2->dtype)){
      printf("Definition Error:Argument %s has conflicting types in definition and declaration\n",temp1->name);
      Exit();
    }
    temp1=temp1->n;
    temp2=temp2->n;
  }
  if(temp2){
    printf("Definition Error:Unexpected arguments in definition of function\n");
    Exit();
  }
}
cfnode *cParAllocate(cfnode *p){
  cfnode *id=p,*end,*Ltop=NULL;
  while(id){
    cfnode *temp=(cfnode*)malloc(sizeof(cfnode));
    temp->name=(char*)malloc(strlen(id->name)*sizeof(char));
    strcpy(temp->name,id->name);
    temp->dtype=id->dtype;
    temp->ctype=NULL;
    temp->fnid=-1;
    temp->p=NULL;
    temp->n=NULL;        
    if(Ltop==NULL){
      Ltop=temp;
      id=id->n;
      continue;
    }
    end=Ltop;  
    while(end->n)
      end=end->n;
    end->n=temp;
    id=id->n;
  }
  return Ltop;
}
void addMEMLocVar(cfnode **Ltop,node *line,char *cname){  
  if(!line)
    return;  
  node *temp=line;
  while(temp){
    CLfDeclare(Ltop,temp->r,temp->e,cname);
    temp=temp->l;
  }  
}
void bindMemFld(cfnode *Ltop,node *son){
  node *dad;
  tnode *dtype;
  cnode *ctype;
  fnode *field=NULL;
  cfnode *cfield=NULL;
  if(son->l){
    dad=son->l;      
    bindMemFnId(Ltop,&dad);
    printf("=>Child:%s\n",son->var);
    dtype=dad->dtype;ctype=dad->ctype;
    if(dtype){
      if(son->ntype==FUNCTION){
        cfield=getcFSymbol(dtype->decl,son->var);
        if(!cfield){
          printf("Type Error:'%s' does not have field named '%s'\n",dad->var,son->var);
          Exit();
        }
        printf("Type:%s\n",cfield->dtype->name); 
        son->dtype=cfield->dtype;
        if(cfield->ind==-1){
          son->ctype=(cnode*)malloc(sizeof(cnode));
          son->ctype->size=LOCALREF;
          son->ctype->decl=cfield->p;
        }
        else{
          printf("Type Error:'%s' does not have function named '%s'\n",dad->var,son->var);
          Exit();
        }
        son=son->l;
      }
      else{
        field=getFSymbol(dtype->decl,son->var);
        if(!field){
          printf("Type Error:'%s' does not have field named '%s'\n",dad->var,son->var);
          Exit();
        }
        printf("Type:%s\n",field->dtype->name);
        son->dtype=field->dtype;
        if(field->ind==-1){
          printf("Type Error:'%s' does not have data member named '%s'\n",dad->var,son->var);
          Exit();
        }
        son=son->l;
      }
    }
    else if(ctype)
    if(ctype->size!=SELFREF){           
      cfield=getcFSymbol(ctype->decl,son->var);
      if(!cfield){
        printf("Type Error:'%s' does not have field named '%s'\n",dad->var,son->var);
        Exit();
      }
      printf("Type:%s\n",field->dtype->name); 
      if(cfield->dtype){
        printf("Type:%s\n",cfield->dtype->name); 
        son->dtype=cfield->dtype;
        if(son->ntype==FUNCTION&&cfield->ind==-1){
          son->ctype=(cnode*)malloc(sizeof(cnode));
          son->ctype->size=LOCALREF;
          son->ctype->decl=cfield->p;
        }
        else if(son->ntype==FUNCTION&&cfield->ind!=-1){
          printf("Type Error:'%s' does not have function named '%s'\n",dad->var,son->var);
          Exit();
        }
        else if(son->ntype!=FUNCTION&&cfield->ind==-1){
          printf("Type Error:'%s' does not have data member named '%s'\n",dad->var,son->var);
          Exit();
        }
      }
      else{
        son->ctype=cfield->ctype;
        printf("Type:%s\n",cfield->ctype->name);
      }
      son=son->l;
    }
    else
      return;
  }
}
void bindMemFnId(cfnode *Ltop,node **Id){
  node *id=*Id;
  if(id->val==FLD_CHILD){
    bindMemFld(Ltop,id);
    return;
  }
  cfnode *T=getcFSymbol(Ltop,id->var);
  if(T){
    printf("Id:%s\nType:%s\n",id->var,T->dtype->name);
    id->dtype=T->dtype;
    id->ctype=(cnode*)malloc(sizeof(cnode));
    id->ctype->size=LOCALREF;
    id->l=NULL;
    id->r=NULL;
    id->val=VARIABLE;
    id->sym=NULL;
    id->ctype->decl=T;    
  }
  else if(strcmp(id->var,"self")==0){
    printf("Id:%s,Type:thisClass\n",id->var);
    id->dtype=NULL;
    id->ctype=(cnode*)malloc(sizeof(cnode));
    id->ctype->size=SELFREF;
    id->l=NULL;
    id->r=NULL;
    id->val=VARIABLE;
    id->sym=NULL;
  }
  else{
      printf("Declaration Error:Identifier '%s' has not been declared in this scope\n",id->var);
      Exit();
  }
}
void bindMFVar(cfnode *Ltop,node *body){
  if(body->ntype==DMA_NEW){
      printf("new(%s)\n",body->l->var);
      return;
  }
  if(body->ntype==IDENTIFIER){
    bindMemFnId(Ltop,&body);
  }
  else if(body->ntype==FUNCTION){
    bindMemFnId(Ltop,&body);
    node *temp1=body->r;
    node *temp2=temp1;int i=0;
    while(temp1){
      if(!temp2){
        printf("Definition Error:Expecting more arguments in definition of function\n");
        Exit();
      }
      bindMFVar(Ltop,temp2);
      checkTypeError(temp2);
      temp1=temp1->e;
      temp2=temp2->e;i++;
    }
    if(temp2){
      printf("Definition Error:Unexpected arguments in definition of function\n");
      Exit();
    }
    //prntArg(body->l);
    return;
  }
  else
  {
    if(body->l)bindMFVar(Ltop,body->l);
    if(body->r)bindMFVar(Ltop,body->r);
    if(body->e)bindMFVar(Ltop,body->e);
  }  
}
void bindSelfMemFld(cnode *self,node *son){
  node *dad;
  tnode *dtype;
  cnode *ctype;
  fnode *field=NULL;
  cfnode *cfield=NULL;
  if(son->l){
    dad=son->l;      
    bindSelf2MemFnId(self,&dad);
    printf("=>Child:%s\n",son->var);
    dtype=dad->dtype;ctype=dad->ctype;
    if(dtype){
      if(son->ntype==FUNCTION){
        cfield=getcFSymbol(dtype->decl,son->var);
        if(!cfield){
          printf("Type Error:'%s' does not have field named '%s'\n",dad->var,son->var);
          Exit();
        }
        printf("Type:%s\n",cfield->dtype->name); 
        son->dtype=cfield->dtype;
        if(cfield->ind==-1){
          son->ctype=(cnode*)malloc(sizeof(cnode));
          son->ctype->size=LOCALREF;
          son->ctype->decl=cfield->p;
        }
        else{
          printf("Type Error:'%s' does not have function named '%s'\n",dad->var,son->var);
          Exit();
        }
        son=son->l;
      }
      else{
        field=getFSymbol(dtype->decl,son->var);
        if(!field){
          printf("Type Error:'%s' does not have field named '%s'\n",dad->var,son->var);
          Exit();
        }
        printf("Type:%s\n",field->dtype->name);
        son->dtype=field->dtype;
        if(field->ind==-1){
          printf("Type Error:'%s' does not have data member named '%s'\n",dad->var,son->var);
          Exit();
        }
        son=son->l;
      }
    }
    else if(ctype){
      if(ctype->size==LOCALREF){
        printf("Local ");
        return;
      }
      cfield=getcFSymbol(ctype->decl,son->var);
      if(!cfield){
        printf("Type Error:'%s' does not have field named '%s'\n",dad->var,son->var);
        Exit();
      }
      if(cfield->dtype){
        printf("Type:%s\n",cfield->dtype->name); 
        son->dtype=cfield->dtype;
        if(son->ntype==FUNCTION&&cfield->ind==-1){
          son->ctype=(cnode*)malloc(sizeof(cnode));
          son->ctype->size=LOCALREF;
          son->ctype->decl=cfield->p;
        }
        else if(son->ntype==FUNCTION&&cfield->ind!=-1){
          printf("Type Error:'%s' does not have function named '%s'\n",dad->var,son->var);
          Exit();
        }
        else if(son->ntype!=FUNCTION&&cfield->ind==-1){
          printf("Type Error:'%s' does not have data member named '%s'\n",dad->var,son->var);
          Exit();
        }
      }
      else{
        son->ctype=cfield->ctype;
        printf("Type:%s\n",cfield->ctype->name);
      }
      son=son->l;
    }    
    else{
        printf("Type Error:Unkown Type '%s'\n",dad->var);
        Exit();
      }
  }
}
void bindSelf2MemFnId(cnode *self,node **Id){
  node *id=*Id;
  if(id->val==FLD_CHILD){    
    bindSelfMemFld(self,id);
    return;
  }
  else if(strcmp(id->var,"self")==0){
    printf("Id:%s,Type:%s\n",id->var,self->name);
    id->dtype=NULL;
    id->ctype=self;
    id->l=NULL;
    id->r=NULL;
    id->val=VARIABLE;
    id->sym=NULL;
  }
}
void bindSelfVar(cnode *self,node *body){
  if(body->ntype==DMA_NEW){
      printf("new(%s)\n",body->l->var);
      return;
  }
  if(body->ntype==IDENTIFIER){
    bindSelf2MemFnId(self,&body);
    //printf("Id:%s T:%d", body->var,body->dtype);
  }
  else if(body->ntype==FUNCTION){
    bindSelf2MemFnId(self,&body);
    cfnode *temp1=body->ctype->decl;  
    node *temp2=body->r;int i=0;
    while(temp1){
      if(!temp2){
        printf("Definition Error:Expecting more arguments in definition of function\n");
        Exit();
      }
      bindSelfVar(self,temp2);
      checkTypeError(temp2);
      if(compareDType(temp1->dtype,temp2->dtype)){
        printf("Type Mismatch Error:Argument %s has been defined as %s but received %s\n",temp1->name,temp1->dtype->name,temp2->dtype->name);
        Exit();
      }
      temp1=temp1->n;
      temp2=temp2->e;i++;
    }
    if(temp2){
      printf("Definition Error:Unexpected arguments in definition of function\n");
      Exit();
    }
    //prntArg(body->l);
    return;
  }
  else
  {
    if(body->l)bindSelfVar(self,body->l);
    if(body->r)bindSelfVar(self,body->r);
    if(body->e)bindSelfVar(self,body->e);
  }  
}
void finalizeMF(cnode *self,node *FDtop){
  node *rtype=FDtop->e->l,*code=FDtop->r;
  bindSelfVar(self,code);
  checkTypeError(code);
  if(!checkRetType(getTSymbol(rtype->var),code)){
    printf("Fn Error:Need to include return\n");
    Exit();
  }
}
node *makeMemFnDefNode(cfnode *Ftop,node *typeN,node *defN,char *cname){
  node *rtype=typeN->r,*fname=defN->l,*pTop=typeN->e,*lDecl=defN->r,*code=defN->e;
  cfnode *fdecl=getcFSymbol(Ftop,fname->var),*Ltop=NULL;
  tnode *type=getTSymbol(rtype->var);
  if(!fdecl){
    printf("Declaration Error:%s() has not been declared\n",fname->var);
    Exit();
  }
  if(compareDType(fdecl->dtype,type)){
    printf("Declaration Error:%s() has conflicting return types DECL:%s and DEF:%s\n",fname->var,fdecl->dtype->name,rtype->var);
    Exit();
  }
  if(pTop||fdecl->p){
    if(!pTop){
      printf("Definition Error:%s() expects some argument(s)\n",fname->var);
      Exit();
    }
    if(!fdecl->p){
      printf("Definition Error:Declaration of %s() contains no arguments\n",fname->var);
      Exit();
    }
    checkMEMNameEquivalence(fdecl->p,cPDeclare(pTop,cname));
    Ltop=cParAllocate(fdecl->p);
    gsnode *P=(gsnode*)malloc(sizeof(gsnode));
    P->name=NULL;
    P->dtype=NULL;
    P->p=NULL;
    P->n=NULL;
    P->flabel=-1;
    P->size=-1;
    P->bind=MEMFN_PAR;
    P->ctype=(cnode*)malloc(sizeof(cnode));
    P->ctype->name=NULL;
    P->ctype->fdef=NULL;
    P->ctype->n=NULL;
    P->ctype->size=LOCALREF;
    P->ctype->decl=fdecl; 
    fname->sym=P;
  }
  addMEMLocVar(&Ltop,lDecl,cname);
  printcFSymbols(fname->var,Ltop);   
  fname->ntype=FUNCTION;
  fname->val=FN_MEMBR;
  bindMFVar(Ltop,code);
  fname->r=code;
  node *L=(node*)malloc(sizeof(node));
  L->dtype=NULL;
  L->var=NULL;
  L->sym=NULL;
  L->l=rtype;
  L->r=NULL;
  L->e=NULL;
  L->ntype=MEMFN_LST;
  L->ctype=(cnode*)malloc(sizeof(cnode));
  L->ctype->name=NULL;
  L->ctype->fdef=NULL;
  L->ctype->n=NULL;
  L->ctype->size=LOCALREF;
  L->ctype->decl=Ltop;
  fname->e=L;
  return fname;
}
node *DefineMemFns(cfnode *Ftop,node *mpfdef,char *cname){
  node *end=mpfdef,*temp,*FDtop=NULL,*Fend;
  while(end){
    temp=makeMemFnDefNode(Ftop,end->r,end->e,cname);
    if(FDtop==NULL){
      FDtop=temp;
      Fend=FDtop;
    }
    else
    {
      temp->l=NULL;
      Fend->l=temp;
      Fend=Fend->l;
    }
    end=end->l;
  }
  return FDtop;
}
node *makeNewNode(node *ctype){
  node *L=(node*)malloc(sizeof(node));
  L->dtype=NULL;
  L->var=NULL;
  L->sym=NULL;  
  L->r=NULL;
  L->e=NULL;
  L->ntype=DMA_NEW;
  cnode *check=getCSymbol(ctype->var);
  if(!check){
    printf("Alloc Error:Expected class name as argument for new()\n");
    Exit();
  }
  L->l=ctype;
  return L;
}