// 广义表调试暂时失败，因此采用串处理
#include <stdio.h>
#include <string.h>
#define MAXL 10007

int main()
{
    char s[MAXL], g, t[MAXL];
    scanf("%s %c", s, &g);
    int i, pg=0;
    for(i=0; i<strlen(s); ++i) {
        if(s[i]!=g && !(s[i+1]==g && s[i]==',')) t[pg++]=s[i];
        else if(s[i+1]==',') i++;
    }
    t[pg]='\0';
    int flag=0;
    for(i=0; i<strlen(t); ++i) {
        if(t[i]>='a' && t[i]<='z') flag=1;
    }
    int j;
    for(i=0; i<strlen(t); ++i) {
        if(t[i]=='(' && t[i+1]==')') {
            for(j=i; j<strlen(t)-2; ++j) {
                t[i]=t[i+2];
            }
            t[strlen(t)-2]='\0';
        }
        //printf("I=%d, T=%s\n", i, t);    
    }
    for(i=0; i<strlen(t); ++i) {
        if(t[i]==',' && t[i+1]==')') {
                for(j=i; j<strlen(t)-1; ++j) {
                    t[i]=t[i+1];
                }
                t[strlen(t)-1]='\0';
            }
    }
    if(!flag) printf("-1");
    else {
        for(i=0; i<strlen(t); ++i) {
            if(t[i]!=-1) printf("%c", t[i]);
        }
    }
    printf("\n");
    return 0;
}

/*void Print(Glist l)
{
    if(l!=NULL) {
        if(l->tag==LIST) {
            if(l->ptr.hp!=NULL) {
                out[po++]='(';
                Print(l->ptr.hp);
            }
        }else {
            out[po++]=l->atom;
        }       
        if(l->tag==LIST && l->ptr.hp!=NULL) {
            out[po++]=')';
            out[po]='\0';
        }
        if(l->ptr.tp!=NULL) {
            out[po++]=',';
            Print(l->ptr.tp);
        }  
    }
    
}*/

/*void Print(Glist l)
{
    Glist t=l;
    Glist q, p;
    out[po++]='(';
    while(t)
    {
        p=t->ptr.hp;
        q=t->ptr.tp;
        if(p && q && p->tag==ATOM) {  // atom and later
            out[po++]=p->atom;
            out[po++]=',';
            p=q->ptr.hp;
            q=q->ptr.tp;
        }
        if(p && p->tag == ATOM) {
            out[po++]=p->atom;
            break;
        } else {
            if(p) Print(p);
            if(q) out[po++]=',';
            t=q;
        }
    }
    out[po++]=')';
}*/