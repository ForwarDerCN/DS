#include <stdio.h>
#include <stdlib.h>
#define MAXN 10007

typedef struct bnode {
    char data;
    int num;
    int lc, rc;
}bnode;
bnode t[MAXN];  
bnode *q[MAXN];  // A queue that stores ADREESSES
int order[MAXN];
int head, tail;
int num; // NUM of nodes

void gettree();
void init();
void enqueue(bnode *x);
bnode *dequeue();
int isempty();
void wtravel();
void check();

int main()
{
    gettree();
    wtravel();
    check();
    return 0;
}

void gettree()
{
    bnode tt;
    //tt=(bnode *)malloc(sizeof(bnode));
    char ch;
    int l, r;
    int i=1;
    while(scanf("%c %d %d\n", &ch, &l, &r)!=EOF) {
        tt.data=ch;
        tt.num=0;
        tt.lc=l;
        tt.rc=r;
        t[i]=tt;
        i++;
    }
    num=i-1;
}

void wtravel()
{
    init();
    enqueue(&t[1]);
    int order=1;
    while(!isempty()) {
        bnode *cur;
        cur=dequeue();
        cur->num=order;
        order++;
        if(cur->lc!=-1) enqueue(&t[cur->lc]);
        if(cur->rc!=-1) enqueue(&t[cur->rc]);
    }
}

void check()
{
    int i;
    int flag=1;
    for(i=1; i<=num; ++i) {
        if(!((t[i].lc==-1 || t[i].num * 2 == t[t[i].lc].num)
        && (t[i].rc==-1 || t[i].num * 2 + 1 == t[t[i].rc].num)))
            flag=0;
    }
    if(flag==1) printf("Yes");
    else printf("No");
}

void init()
{
    head=0;
    tail=0;
}

void enqueue(bnode *x)
{
    q[tail]=x;
    tail++;
}

bnode *dequeue()
{
    bnode *ret=q[head];
    head++;
    return ret;
}

int isempty()
{
    return (head==tail);
}