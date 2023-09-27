typedef struct tnode{int val;char op;struct tnode *l,*r;}tnode;
tnode *makeOpNode(char,tnode*,tnode*);
tnode *makeLfNode(int);
int eval(tnode *t);