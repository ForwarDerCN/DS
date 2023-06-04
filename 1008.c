#include <stdio.h>
#include <stdlib.h>

int m, n;
typedef struct lNode {
    int data;
    struct lNode *next;
}lnode;
lnode *init();
void insert(lnode *l, int data);
lnode *merge(lnode *a, lnode *b);
void printl(lnode *a);

int main()
{
    lnode *a=init();
    lnode *b=init();
    scanf("%d %d", &m, &n);
    int i, ea, eb;
    for(i=1; i<=m; ++i) {
        scanf("%d", &ea);
        insert(a, ea);
    }
    for(i=1; i<=n; ++i) {
        scanf("%d", &eb);
        insert(b, eb);
    }
    lnode *pc=merge(a, b);
    printl(pc);
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

lnode *merge(lnode *a, lnode *b)
{
    while(b->next != NULL) b=b->next;
    b->next=a;
    return b;
}

void printl(lnode *a)
{
    while(a->next != NULL) {
        printf("%d ", a->data);
        a=a->next;
    }
    printf("\n");
}
