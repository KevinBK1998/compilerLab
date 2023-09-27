#define LVAL 0
#define RVAL 1
int evalCode(tnode*);
int read(tnode*);
int calculate(tnode*);
int write(tnode*);
int getVar(tnode*,int);
int evalCtrl(tnode *t);