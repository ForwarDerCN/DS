#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXL 1000006
#define ABS(x) (x>=0) ? (x) : (-x)

typedef struct Poly {
    int tm;
    int cof;
    struct Poly *next;
}poly;
char s[MAXL];
int pos;
poly *initp();
poly geti();
void insert(poly *p, poly ne);
void df(poly *p);
void printp(poly *p);

int main()
{
    char c;
    int i=0;
    while((c=getchar())!='\n') {
        s[i++]=c;
    }
    s[i]='\0';
    poly *p;
    p=initp();
    pos=-1;
    // printf("Len of s: %ld\n", strlen(s));
    while(pos<(int)strlen(s)) {
        poly ele=geti();
        // printf("Get ele cof: %d  ele : %d \n", ele.cof, ele.tm);
        insert(p, ele);
    }
    df(p);
    printp(p);
    return 0;
}

poly *initp()
{
    poly *pl=(poly *)malloc(sizeof(poly));
    pl->next=NULL;
    pl->cof=0xfffffff;
    pl->tm=0xfffffff;
    return pl;
}

poly geti()
{
    poly t;
    int sign=1, num=0, tm=0;
    pos++;
    //printf("Ins geti , pos: %d\n", pos);
    if(!('0'<=s[pos] && '9'>=s[pos])) {     // pos=0
        if(s[pos]=='+')  sign=1;  // 0
        else if(s[pos]=='-') sign=-1;
        pos++;    // ' '
        pos++;    // number
    }
    while(1) {
        num=num*10+s[pos]-'0';   // numbers
        pos++;
        if(s[pos]=='x') break;   //'x'
        else if(s[pos]==' ' || s[pos]=='\0') {   // or 0 time  ' '
            t.cof=num*sign;
            t.tm=0;
            return t;
        }
    }
    pos++;   // ^ or ' '(1 time)
    if(s[pos]==' ' || s[pos]=='\0') { // 1 time
        t.cof=num*sign;
        t.tm=1;
        return t;
    }
    pos++;  // number of times
    while(1) {
        tm=tm*10+s[pos]-'0';
        pos++;
        if(s[pos]==' ' || s[pos]=='\0') break;
    }
    t.cof=num*sign;
    t.tm=tm;
    return t;
}

void insert(poly *p, poly ne)
{
    //printf("In insert, cof= %d , tm= %d \n", ne.cof, ne.tm);
    poly *q, *pre;
    pre=p;
    if(p->next!=NULL) q=p->next;
    while(pre->next!=NULL && q->tm>ne.tm) {
        pre=q;
        q=q->next;
    } // out when q->tm >= ne.tm
    if(pre->next!=NULL && q->tm==ne.tm) {
        q->cof+=ne.cof;
    } else { // q->tm>ne.tm && pre->tm<ne.tm
        poly *np=(poly *)malloc(sizeof(poly));
        np->cof=ne.cof;
        np->tm=ne.tm;
        //printf("Insert: cof %d tm %d\n", np->cof, np->tm);
        if(pre->next!=NULL) {
            np->next=q;
        }else {
            np->next=NULL;
        }
        pre->next=np;
    }
}

void df(poly *p)
{
    poly *q;
    q=p->next;
    while(q!=NULL) {
        q->cof=q->cof*q->tm;
        q->tm=q->tm-1;
        q=q->next;
    }
}

void printp(poly *p)
{
    poly *q;
    q=p->next;
    bool isout=false;
    while(q!=NULL) {
        int sign=(q->cof>0) ? 1 : -1;
        if(sign==1 && q!=p->next) printf("+ ");
        else if(sign==-1 && q->cof!=0) printf("- ");
        if(q->tm>=2) {
            if(q->cof!=0) {
                printf("%dx^%d", ABS(q->cof), q->tm);
                isout=true;
            }
        }else if(q->tm==1) {
            if(q->cof!=0) {
                printf("%dx", ABS(q->cof));
                isout=true;
            }
        }else if(q->tm==0) {
            if(q->cof!=0) {
                printf("%d", ABS(q->cof));
                isout=true;
            }
        }else if(q->tm==-1) {
            if(q->cof==0 && q==p->next) {
                printf("0");
                isout=true;
            }
        }
        if(isout) printf(" ");
        q=q->next;
    }
    if(!isout)  printf("0");
    printf("\n");
}