typedef struct node{
    char *label;
    int target;
    struct node *next;
}node;
node *create(char *,int);
void insertN(node **,node *);
void insert(node **,char *,int);
void printlist(node *);
int sub(node*,char *);