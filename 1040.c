#include <stdio.h>
#include <stdlib.h>

typedef struct bnode {
    char data;
    struct bnode *lc, *rc;
}bnode;
char u, v;
bnode *t;  // The main tree
bnode *Create();
void acc(bnode *t, char p, char q, int *k);
bnode *NCA(bnode *t, char p, char q);
bnode *findfather(bnode *c, char p);

int main()
{
    t=Create();
    scanf("\n%c %c", &u, &v);
    bnode *ans=NCA(t, u, v);
    printf("%c\n", ans->data);
    return 0;
}

bnode *Create()
{
    char ch;
    bnode *t;
    ch=getchar();
    if(ch=='^' || ch=='\n') return NULL;
    else {
        t=(bnode *)malloc(sizeof(bnode));
        t->data=ch;
        t->lc=Create();
        t->rc=Create();
        return t;
    }
}

void acc(bnode *t, char p, char q, int *k)
{
    if(t==NULL) return ;
    else {
        if(t->data==p || t->data==q) (*k)++;
        acc(t->lc, p, q, k);
        acc(t->rc, p, q, k);
    }
}

bnode *NCA(bnode *s, char p, char q)
{
    int numl=0, numr=0;
    acc(s->lc, p, q, &numl);
    acc(s->rc, p, q, &numr);
    //printf("NUML: %d ; NUMR: %d\n", numl, numr);
    if(s->data==p || s->data==q)
        return findfather(t, s->data);
    else if(numl == numr)  // find p & q respectively in L & R
            return s;
    else if(numl==2)    NCA(s->lc, p, q);
        else NCA(s->rc, p, q);
}

bnode *findfather(bnode *c, char p)
{
    if(c->lc!=NULL)
        if(c->lc->data==p) 
            return c;
    if(c->rc!=NULL)
        if(c->rc->data==p)
            return c;
    else {
        findfather(c->lc, p);
        findfather(c->rc, p);
    }
}