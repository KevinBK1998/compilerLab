#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linklist.h"
node *create(char *name,int val){
    node *top=(node*)malloc(sizeof(node));
    top->label=(char*)malloc(strlen(name)*sizeof(char));
    strcpy(top->label,name);
    top->target=val;
    top->next=NULL;
    return top;
}
void insertN(node **top,node *e){
    node *end=*top;
    if(*top==NULL){
        *top=e;
        return;
    }
    while(end->next!=NULL)
        end=end->next;
    end->next=e;
    return;
}
void insert(node **top,char *name,int val){
    node *temp=(node*)malloc(sizeof(node));
    temp->label=(char*)malloc(strlen(name)*sizeof(char));
    strcpy(temp->label,name);
    temp->target=val;
    temp->next=NULL;

    node *end=*top;
    if(*top==NULL){
        *top=temp;
        return;
    }
    while(end->next!=NULL)
        end=end->next;
    end->next=temp;
    return;
}
int sub(node *top,char *s){
    node *temp=top;
    while(temp){
        if(strcmp(temp->label,s)==0)
            return temp->target;
        temp=temp->next;
    }
    printf("Error:Unknown Label %s\n",s);
    exit(1);
}
void printlist(node *top){
    node *temp=top;
    while(temp){
        printf("%s,%d->",temp->label,temp->target);
        temp=temp->next;
    }    
}
