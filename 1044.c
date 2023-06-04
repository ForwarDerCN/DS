#include <stdio.h>
#include <stdlib.h>
#define MAXN 10007

typedef struct bnode {
    char data;
    struct bnode *lc, *rc;
}bnode;

bnode *Create();
void init();
void push(bnode *x);
bnode *pop();
bnode *gettop();
int isempty();
int getpri(char a, char b);
void lstTravel(bnode *t);

char fst[MAXN], mid[MAXN];
bnode *st[MAXN];
int ps;


int main()
{
    init();
    scanf("%s\n%s", fst, mid);
    bnode *t;
    t=Create();
    lstTravel(t);
    return 0;
}

// No recursive
bnode *Create()
{
    bnode *a, *b, *t, *r;
    t=NULL;
    int p=-1;
    while(fst[p+1]!='\0') {
        p++;
        a=(bnode *)malloc(sizeof(bnode));
        a->data=fst[p]; // Fst Travel 's current NODE -- @data p, Pointer a
        if(t==NULL) t=a;
        else {
            r=gettop();     // Former ROOT
            if(getpri(fst[p], r->data)<0)   // fst[p] is left to cur root
                r->lc=a;      // Currrent is the FORMER ROOT's left son
            else {                  // right to , pop to find the last in the right
                do {
                    r=pop();
                    if(!isempty()) b=gettop();  // b is the first that is not left than cur a
                    else break;                 // Meanwhile, r is the last that is left than cur a
                }while(getpri(fst[p], b->data)>0);
                r->rc=a;  // Former root r & the last left than a & Current is not its left son => Current is right son
            }
        }
        push(a);
    }
    return t;
}

int getpri(char a, char b)
{
    int pa=-1, pb=-1;
    int i;
    for(i=0; mid[i]!='\0'; ++i) {
        if(mid[i]==a)  pa=i;
        if(mid[i]==b)  pb=i; 
    }
    if(pa>=0 && pb>=0) {
        if(pa<pb)   return -1;
        else return 1;
    }else {
        return 0;
    }
}

void lstTravel(bnode *t)
{
    if(t!=NULL) {
        if(t->lc!=NULL) lstTravel(t->lc);
        if(t->rc!=NULL) lstTravel(t->rc);
        printf("%c", t->data);
    }
}

void init()
{
    bnode *base;
    base=(bnode *)malloc(sizeof(bnode));
    base->data='#';
    base->lc=base->rc=NULL;
    st[0]=base;
    ps++;
}

void push(bnode *x)
{
    st[ps]=x;
    ps++;
}

bnode *pop()
{
    ps--;
    bnode *ret=st[ps];
    bnode *emp;
    emp=(bnode *)malloc(sizeof(bnode));
    emp->data=0;
    emp->lc=emp->rc=NULL;
    st[ps]=emp;
    return ret;
}

bnode *gettop()
{
    return st[ps-1];
}

int isempty()
{
    return ((gettop()->data)=='#');
}