typedef struct tnode{int val;char op;struct tnode *l,*r;}tnode;
tnode *makeOpNode(char,tnode*,tnode*);
tnode *makeLfNode(int);
int eval(tnode*);
char *pst(tnode*);
int pre(tnode*);
int countDigit(long long);