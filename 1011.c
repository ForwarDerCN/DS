#include <stdio.h>
#include <stdlib.h>
#define MAXL 1000006

int m, n;
char st[MAXL];
typedef struct lNode {
    char data;
    struct lNode *next;
}lnode;
lnode *init();
void insert(lnode *l, int data);
void printl(lnode *a);
void lreverse(lnode *a);

int main()
{
    lnode *a=init();
    int i=0;
    char num;
    char c;
    while(scanf("%c,", &num)!=EOF) {
        st[i]=num;
        i++;
        //getchar();
    }
    int j;
    for(j=i-1; j>=0; --j) {
        insert(a, st[j]);
    }
    lreverse(a);
    printl(a);
    return 0;
}

lnode* init()
{
   lnode *plist;
   plist=(lnode *)malloc(sizeof(lnode));
   plist->next=NULL;
   return plist;
}

void insert(lnode *l, int data) {
    lnode *p;
    p=(lnode *)malloc(sizeof(lnode));
    p->data=data;
    if(l->next == NULL) {
        p->next=NULL;
        l->next=p;
    } else {
        p->next=l->next;
        l->next=p;
    }
}

void printl(lnode *a)
{
    lnode *p;
    p=a;
    int flag=1, nflag=1;
    while(p != NULL) {
        if(!flag) {
            printf("%c", p->data);
            if(p->next != NULL && p->next->next != NULL) printf(",");
            nflag=0;
        }
        p=p->next;
        flag=0;
    }
    if(nflag==1) printf("NULL");
    printf("\n");
}

void lreverse(lnode *a)
{
    int i=0, j;
    lnode *p;
    p=a;
    int flag=1;
    while(p!=NULL) {
        if(!flag)   {
            st[i]=p->data;
            i++;
        }
        p=p->next;
        flag=0;
    }
    p=a;
    for(j=i-1; j>=0; --j) {
        p->data=st[j];
        p=p->next;
    }
}
