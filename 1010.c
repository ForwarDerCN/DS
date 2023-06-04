#include <stdio.h>
#include <stdlib.h>
#define MAXL 1000006

int m, n;
int st[MAXL];
typedef struct lNode {
    int data;
    struct lNode *next;
}lnode;
lnode *init();
void insert(lnode *l, int data);
void ldelete(lnode *l, int mink, int maxk);
void printl(lnode *a);

int main()
{
    lnode *a=init();
    int i=0, num=0;
    char c;
    while(scanf("%d", &num)!=EOF) {
        /*num=0;
        while(((c=getchar()) !=' ') && ((c=getchar()) !='\n')) num=num*10+c-'0';
        //if(c=='\n') c=getchar();*/
        st[i]=num;
        i++;
        //getchar();
    }
    int maxk=st[i-1];
    int mink=st[i-2];
    i-=2;
    int j;
    for(j=i-1; j>=0; --j) {
        insert(a, st[j]);
    }
    ldelete(a, mink, maxk);
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

void ldelete(lnode *l, int mink, int maxk)
{
    int n=0;
    lnode *pre, *p;
    pre=l;
    while(pre->next->data<=mink && pre!=NULL) {
        pre=pre->next;
    }
    while(pre!=NULL && pre->next!=NULL && pre->next->data<maxk) {
        p=pre->next;
        pre->next=p->next;
        free(p);
    }
}

void printl(lnode *a)
{
    lnode *p;
    p=a;
    int flag=1, nflag=1;
    while(p != NULL) {
        if(!flag) {
            printf("%d ", p->data);
            nflag=0;
        }
        p=p->next;
        flag=0;
    }
    if(nflag==1) printf("NULL");
    printf("\n");
}
