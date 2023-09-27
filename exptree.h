#ifndef EXPR_TREE_H
#define EXPR_TREE_H
//Control Type
#define SIMPLE_IF 0
#define IF_ELSE 1
#define WHILE_LOOP 2
#define BREAK_LOOP 3
#define CONT_LOOP 4
#define REPEAT_LOOP 5
#define DO_LOOP 6
//Function type
#define FN_WRITE 0
#define FN_READ 1
//Data type
#define NO_TYPE 0
#define INTEGER 1
#define BOOLEAN 2 
#define STRING 3
#define PTR 5214
//Identifier Type
#define VARIABLE 0
#define POINTER 1
#define ARRAY1D 2
#define ARRAY2D 3
//Node Type
#define CONSTANT 0
#define OPERATOR 1
#define FUNCTION 2
#define CONNECTION 3
#define CONTROL 4
#define JMP 5
#define DATATYPE 6
#define IDENTIFIER 7
typedef struct snode{
    char *name;
    int dtype;
    int size;
    int csize;
    int bind;
    struct snode *n;
}snode;
typedef struct tnode{
    int val;
    int dtype;
    char *var;
    int ntype;
    snode *sym;
    struct tnode *l,*r,*e;
}tnode;
void Allocate(char*,int,int,int);
snode *getSymbol(char *s);
void printSymbols();
tnode *makeOpNode(char*,tnode*,tnode*,int);
tnode *makeNumNode(int);
tnode *makeIdNode(char*);
tnode *makeStrNode(char*);
tnode *makeUNode(tnode*,tnode*,int);
tnode *makeFnNode(int,tnode*);
tnode *makeConNode(tnode*,tnode*);
tnode *CtrlNode(tnode*,tnode*,tnode*,int);
tnode *makePtrNode(char*,tnode *);
#endif