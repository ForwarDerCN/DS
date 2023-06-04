#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 10007
#define MAXL 107

char s[MAXN];
char g;
typedef enum{ATOM, LIST} ElemTag;
typedef struct GLNode {
    ElemTag tag;
    union {
        char atom;  // Data of atom
        struct{struct GLNode *hp, *tp;} ptr;  // head & tail pointers
    };
}GLNode, *Glist;

void sever(char s[], char h[]);
void Substring(char ret[], char s[], int pos, int len);
void Create(GLNode *l, char s[]);
void DeleteAtom(GLNode *l);
void PrintList(GLNode *l);

int main()
{
    scanf("%s %c", s+1, &g);
    printf("g= %c\n", g);
    s[0]=strlen(s+1);
    GLNode *l;
    Create(l, s);
    DeleteAtom(l);
    PrintList(l);
    return 0;
}

void sever(char s[], char h[])
{
    int n=strlen(s+1);
    int i=0, k=0;
    char t[MAXN];
    do {
        ++i;
        Substring(t, s, i, 1);
        if(strcmp("(", t)==0) ++k;
        else if(strcmp(")", t)==0) --k;
    }while(i<n && (strcmp(t, ",") || k!=0));
    if(i<n) {
        Substring(h, s, 1, i-1);
        Substring(s, s, i+1, n-i);
    } else {
        strcpy(h, s);
        s[0]=0;  s[1]='\0';
    }
}

void Substring(char ret[], char s[], int pos, int len)
{
    int i;
    for(i=1; i<=len; ++i) {
        ret[i]=s[pos+i-1];
    }
    ret[0]=len;
}

void Create(GLNode *l, char s[])
{
    char sub[MAXL], hsub[MAXL];
    Glist p, q;
    if(s[1]=='\0' || strcmp(s, "()")==0)  {
        l=NULL;
        return ;
    }
    else {
        l=(Glist)malloc(sizeof(GLNode));
        if(s[0]==1) {
            l->tag=ATOM;
            l->atom=s[1];
            printf("Get ATOM : %c\n", l->atom);
        } else {
            l->tag=LIST;
            p=l;
            Substring(sub, s, 2, s[0]-2);
            do {
                sever(sub, hsub);
                Create(p->ptr.hp, hsub);
                q=p;
                if(sub[0]>0) {
                    p=(GLNode *)malloc(sizeof(GLNode));
                    p->tag=LIST;
                    p->ptr.tp=p;
                }
            }while(sub[0]>0);
            q->ptr.tp=NULL;
        }
    }
}

void DeleteAtom(GLNode *l)
{
    if(!l)  return ;
    if(l->tag == ATOM && l->atom==g) {
        l->atom=-1;
        return ;
    }
    GLNode *pp;
    for(pp=l; pp; pp=pp->ptr.tp) {
        DeleteAtom(pp->ptr.hp);
    }
}

void PrintList(GLNode *l)
{
    if(!l)  return ;
    if(l->tag == ATOM && l->atom!=-1) {
        printf("%c,", l->atom);
    }else {
        printf("(");
        PrintList(l->ptr.hp);
        PrintList(l->ptr.tp);
        printf(")");
    }
    printf("\n");
}