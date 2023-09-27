#ifndef EXPR_TREE_H
#define EXPR_TREE_H
//Control Type
#define SIMPLE_IF 0
#define IF_ELSE 1
#define WHILE_LOOP 2
#define BREAK_LOOP 3
#define CONT_LOOP 4
//Function type
#define FN_WRITE 0
#define FN_READ 1
//Data type
#define NO_TYPE 0
#define INTEGER 1
#define BOOLEAN 2 
//Data Storage Type for Leaf Node
#define NUMERIC 0
#define IDENTIFIER 1
//Node Type
#define LEAF 0
#define OPERATOR 1
#define FUNCTION 2
#define CONNECTION 3
#define CONTROL 4
#define JMP 5
typedef struct tnode{
    int val;
    int dtype;
    char var;
    int ntype;
    struct tnode *l,*r,*e;
}tnode;
tnode *makeOpNode(char,tnode*,tnode*,int);
tnode *makeNumNode(int);
tnode *makeUNode(tnode*,tnode*,int);
tnode *makeIdNode(char);
tnode *makeFnNode(int,tnode*);
tnode *makeConNode(tnode*,tnode*);
tnode *CtrlNode(tnode*,tnode*,tnode*,int);

#endif