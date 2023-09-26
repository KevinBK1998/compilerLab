//Control Type
#define SIMPLE_IF 0
#define IF_ELSE 1
#define WHILE_LOOP 2
#define BREAK_LOOP 3
#define CONT_LOOP 4
#define REPEAT_LOOP 5
#define DO_LOOP 6
#define RETURN_FN 7
#define LOCALREF 8000
#define SELFREF 9000 
//Function type
#define IO_WRITE 8
#define IO_READ 9
#define DMA_INIT 10
#define DMA_ALLOC 11
#define DMA_NEW 40
#define DMA_FREE 12
#define FN_USER 13
#define FN_DRVR 14
#define FN_CALL 15
#define FN_MEMBR 16
//Data type
#define NO_TYPE -1
#define INTEGER 1000
#define BOOLEAN 2000 
#define STRING 3000
#define PTR 4000
#define UDTYPE 5000
//Identifier Type
#define VARIABLE 17
#define POINTER 18
#define ARRAY 19
#define FLD_CHILD 20
#define FLD_PARENT 21
//Node Type
#define CONSTANT 22
#define OPERATOR 23
#define IO 24
#define CONNECTION 25
#define CONTROL 26
#define JMP 27
#define DATATYPE 28
#define IDENTIFIER 29
#define FUNCTION 30
#define DMAFNS 31
#define DMANULL 32
#define LDECLARE 33
#define LST 34
#define FNDEFNS 35
#define FNDEFNSr 36
#define FNDEFNSe 37
#define MEMFN_LST 38
#define MEMFN_PAR 39

#define HB_SIZE 8
#define MF_LIMIT 8
typedef struct fnode{   //Node to create Type Table's Field Row
    char *name;
    int ind;
    struct tnode *dtype;    
    struct fnode *n;
}fnode;
typedef struct cfnode{   //Node to create Class Table's Field Row
    char *name;
    int ind;
    struct tnode *dtype;
    struct cfnode*n;
    int fnid;
    struct cnode *ctype;
    struct cfnode *p;
}cfnode;
typedef struct tnode{   //Node to create Type Table
    char *name;
    int size;
    struct fnode *decl;
    struct tnode *n;
}tnode;
typedef struct cnode{   //Node to create Class Table
    char *name;
    int size;
    struct cfnode *decl;
    struct node *fdef;
    struct cnode *n;
}cnode;
typedef struct lsnode{  //Node used to create Local Symbol Table
    char *name;
    struct tnode *dtype;
    int bind;
    struct lsnode *n;
}lsnode;
typedef struct gsnode{  //Node used to create Global Symbol Table
    char *name;
    struct tnode *dtype;
    struct cnode *ctype;
    int flabel;         //pointer or function
    int size;
    int bind;
    struct lsnode *p;
    struct gsnode *n;
}gsnode;
typedef struct node{    //Node used to create AST
    int val;
    struct tnode *dtype;
    struct cnode *ctype;
    char *var;
    int ntype;    
    gsnode *sym;
    struct node *l,*r,*e;
}node;
void GAllocate(node*,node*,int);
tnode *getTSymbol(char*);
void GDeclare(node *,node *);
void LDeclare(lsnode **,node *,node *);
lsnode *PDeclare(node *);
lsnode *getLSymbol(lsnode*,char *);
fnode *getFSymbol(fnode*,char *);
gsnode *getGSymbol(char *);
void printGSymbols();
node *makeOpNode(char*,node*,node*);
node *makeNumNode(int);
node *makeIdNode(char*);
node *makeUNode(node*,node*,int);
node *makeIONode(int,node*);
node *makeConNode(node*,node*);
node *CtrlNode(node*,node*,node*,int);
node *makePtrNode(char*,node*);
tnode *boolType();
tnode *checkTypeError(node*);
tnode *assgnType(node*);
cfnode *getcFSymbol(cfnode*,char*);
cnode *getCSymbol(char*);
void printcFSymbols(char*,cfnode*);
cfnode *cPDeclare(node*,char*);
node *DefineMemFns(cfnode*,node*,char*);