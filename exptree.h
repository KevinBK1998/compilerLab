#define NUMERIC 0
#define IDENTIFIER 1
#define LEAF 0
#define OPERATOR 1
#define FUNCTION 2
#define CONNECTION 3
typedef struct tnode{
    int val;
    int dtype;
    char var;
    int ntype;
    struct tnode *l,*r;
}tnode;
tnode *makeOpNode(char,tnode*,tnode*);
tnode *makeNumNode(int);
tnode *makeIdNode(char);
tnode *makeFnNode(int,tnode*);
tnode *makeConNode(tnode*,tnode*);