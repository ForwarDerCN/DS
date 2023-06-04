#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 10007

char s[MAXN], out[MAXN];
int ps, po;
char g;
typedef enum{ATOM, LIST} ElemTag;
typedef struct GLNode {
    ElemTag tag;
    union {
        char atom;  // Data of atom
        struct{struct GLNode *hp, *tp;} ptr;  // head & tail pointers
    };
}GLNode, *Glist;
void Create(Glist *l);
void Make(Glist *l);
void Delete(Glist *l, char x);
void Print(Glist l);
void Clear(Glist *l);

int main()
{
    scanf("%s %c", s+1, &g);
    s[0]=strlen(s+1);
    ps=1;
    Glist l;
    Create(&l);
    Delete(&l, g);
    Print(l);
    int i, j;
    for(i=0; i<strlen(out); ++i) {
        if(out[i]==',' && out[i+1]==')') {
                for(j=i; j<strlen(out)-1; ++j) {
                    out[i]=out[i+1];
                }
                out[strlen(out)-1]='\0';
            }
    }
    if(strlen(out)==0) {
        printf("-1\n");
    }else {
        printf("(");
        printf("%s", out);
        printf(")");
    }
    return 0;
}

void Create(Glist *l)
{
    char ch;
    ch = s[ps++];
    if(ch=='(') {  // Skip the first (
        Make(l);
    }
}

void Make(Glist *l) 
{
    char ch;
    ch=s[ps++];
    if(ch==' ') {       // Blank List
        *l=NULL;
        if(s[ps++] != ')') return ;
    } else {
        *l=(Glist)malloc(sizeof(GLNode));
        (*l)->tag=LIST;
        if(ch>='a' && ch<='z') {    // Build Atom Node
            (*l)->ptr.hp=(Glist)malloc(sizeof(GLNode));
            (*l)->ptr.hp->tag=ATOM;
            (*l)->ptr.hp->atom=ch;
        } else {
            if(ch=='(') {
                Make(&((*l)->ptr.hp));  // New @ head
            }
        }
        ch=s[ps++];     // CHECK if Tail
        if(ch==')') {
            (*l)->ptr.tp=NULL;
        }else if(ch==',') {  // New @ Tail
            Make(&((*l)->ptr.tp));
        }
    }
}

void Delete(Glist *l, char x)
{
    Glist h, p;
    if(*l && (*l)->tag==LIST) {
        h=(*l)->ptr.hp;
        if(h) {
            if(h->tag==LIST) {
                Delete(&((*l)->ptr.hp), x);
                Delete(&((*l)->ptr.tp), x);
            } else {
                if(h->atom==x) {  // Find & Delete
                    p=*l;
                    *l=(*l)->ptr.tp;
                    p->ptr.tp=NULL;
                    //Clear(&p);
                    Delete(l, x);
                }else {
                    Delete(&((*l)->ptr.tp), x);
                }
            }
        }else {
            if((*l)->ptr.tp) {
                Delete(&((*l)->ptr.tp), x);
            }
        }
    }
}

void Print(Glist l)
{
    if(l!=NULL) {
        if(l->tag==ATOM) {
            out[po++]=l->atom;
        }else if(l->ptr.hp && l->ptr.hp->tag==ATOM) {
            Print(l->ptr.hp);
        }else if(l->ptr.hp && l->ptr.hp->tag==LIST) {
            out[po++]='(';
            Print(l->ptr.hp);
            out[po++]=')';
            out[po]='\0';
        }
        if(l->ptr.tp!=NULL) {
            out[po++]=',';
        }
        Print(l->ptr.tp);
    }
}

void Clear(Glist *l)
{
    Glist p=(*l);
    while(p!=NULL) {
        if(p->tag==ATOM) {
            (*l)->ptr.tp=p->ptr.tp;
            free(p);
            p=(*l)->ptr.tp;
        }else {
            Clear(&(p->ptr.hp));
            p=p->ptr.tp;
        }
    }
}
