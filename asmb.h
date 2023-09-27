#define RMAX 20
#define OUT_LOOP 0
#define IN_LOOP 1
int getReg();
void freeReg();
int codeInit(char*);
int codeGen(tnode*,int,int,int);
int loopCodeGen(tnode*,int,int);
int codeRead(tnode*);
int codeWrite(tnode*);
int codeExit();
int codeAsmble(tnode*);
int expCodeGen(tnode*);
int getVar(tnode*);
int brkFlowGen(tnode*,int,int,int);