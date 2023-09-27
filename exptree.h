//Control Type
#define SIMPLE_IF 0
#define IF_ELSE 1
#define IF_ELSE_HEAD 2
#define WHILE_LOOP 3
#define IF_THEN 4
//Function type
#define FN_READ 1
#define FN_WRITE 0
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
typedef struct tnode{
    int val;
    int dtype;
    char var;
    int ntype;
    struct tnode *l,*r;
}tnode;
tnode *makeOpNode(char,tnode*,tnode*,int);
tnode *makeNumNode(int);
tnode *makeIdNode(char);
tnode *makeFnNode(int,tnode*);
tnode *makeConNode(tnode*,tnode*);
tnode *CtrlNode(tnode*,tnode*,int);