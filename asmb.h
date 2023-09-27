#define RMAX 20
#define SP 4121
#define OUT_LOOP 0
#define IN_LOOP 1
int getReg();
void freeReg();
int codeInit(char*);
int codeGen(tnode*,int,int,int);
int loopCodeGen(tnode*,int,int);
int codeRead(int);
int codeWrite(int);
int codeExit();
int codeAsmble(tnode*);
int expCodeGen(tnode*);
int fnRead(tnode*);
int fnWrite(tnode*);
int getVar(tnode*);
int brkFlowGen(tnode*,int,int,int);