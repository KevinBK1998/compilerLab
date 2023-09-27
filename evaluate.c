//Code for evaluating an expression tree with static memory allocation
#include<stdio.h>
#include "evaluate.h"
// #include "exptree.c"  //comment before use
static int MEMORY[26];
int evalCode(tnode *t){
    switch(t->ntype){
      case OPERATOR:
        return calculate(t);
      case FUNCTION:
        if(t->val)
            return read(t->l);
        else
            return write(t->l);
      case CONNECTION:
        evalCode(t->l);
        evalCode(t->r);
        return 0;
    }
}
int read(tnode *t){
    printf("In:");
    scanf("%d",&MEMORY[getVar(t,LVAL)]);
    return 0;
}
int calculate(tnode *exp){
    if(exp->ntype){
        switch(exp->var){
            case '+':return calculate(exp->l)+calculate(exp->r);
            case '*':return calculate(exp->l)*calculate(exp->r);
            case '=':
            MEMORY[getVar(exp->l,LVAL)]=calculate(exp->r);return getVar(exp->l,RVAL);
        }
    }
    switch(exp->dtype){
        
        case NUMERIC:return exp->val;
        case IDENTIFIER:return getVar(exp,RVAL);
    }
}
int write(tnode *t){
    int data=calculate(t);
    printf("Out:%d\n",data);
    return 0;
}
int getVar(tnode *varNode,int val){
    int i;
    if(val)
        i=MEMORY[varNode->var-'a'];
    else
        i=varNode->var-'a';
    return i;
}