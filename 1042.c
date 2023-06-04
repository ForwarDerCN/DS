#include <stdio.h>
#include <stdlib.h>

typedef struct bnode {
    char data;
    struct bnode *lc, *rc;
}bnode;
bnode *create();
int isop(char c);
int isle(char a, char b);
int islow(char a, char b);
void travel(bnode *t);
void init();
int ref[128];

int main()
{
    init();
    bnode *t;
    t=create();
    travel(t);
    return 0;
}

void init()
{
    ref['+']=ref['-']=1;
    ref['*']=ref['/']=2;
}

bnode *create()
{
    char ch;
    bnode *t;
    ch=getchar();
    if(ch=='#' || ch=='\n') return NULL;
    else {
        t=(bnode *)malloc(sizeof(bnode));
        t->data=ch;
        t->lc=create();
        t->rc=create();
        return t;
    }
}

// Mid-root Travel
void travel(bnode *t)
{
    if(t) {
        // Left subtree
        if(t->lc!=NULL) 
            if(isop(t->lc->data) && islow(t->lc->data, t->data)) {
                printf("(");
                travel(t->lc);
                printf(")");
            }else travel(t->lc);
        // Root
        printf("%c", t->data);
        // Right Subtree
        if(t->rc!=NULL) 
            if(isop(t->rc->data) && isle(t->rc->data, t->data)) {
                printf("(");
                travel(t->rc);
                printf(")");
            }else travel(t->rc);
    }
}

int isop(char c)
{
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

// If a's priority is lower/equal than b
int isle(char a, char b)
{
    return ref[a]<=ref[b];
}

int islow(char a, char b)
{
    return ref[a]<ref[b];
}