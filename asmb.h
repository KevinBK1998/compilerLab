#define RMAX 20
#define SP 4121
int getReg();
void freeReg();
int codeInit(char*);
int codeGen(tnode*);
int codeRead(int);
int codeWrite(int);
int codeExit();
int codeAsmble(tnode*);
int expCodeGen(tnode*);
int fnRead(tnode*);
int fnWrite(tnode*);
int getVar(tnode*);