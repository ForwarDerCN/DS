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
void ldelete(lnode *l, int pos);
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
    int pos=st[i-1];
    i--;
    if(i==1) {
        printf("NULL\n");
        return 0;
    }
    int j;
    for(j=i-1; j>=0; --j) {
        insert(a, st[j]);
    }
    ldelete(a, pos);
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

void ldelete(lnode *l, int pos)
{
    int n=0;
    lnode *pre, *p;
    pre=l;
    while(n<pos && pre!=NULL) {
        pre=pre->next;
        n++;
    }
    if(pre!=NULL) {
        p=pre->next;
        pre->next=p->next;
        free(p);
    }
}

void printl(lnode *a)
{
    lnode *p;
    p=a;
    int flag=1;
    while(p != NULL) {
        if(!flag) printf("%d ", p->data);
        p=p->next;
        flag=0;
    }
    printf("\n");
}
