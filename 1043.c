#include <stdio.h>
#define MAXN 10007

// Skip threading
typedef struct bnode {
    int lc, rc;
}bnode;
bnode f[MAXN];
int o, p, pf, ps, tot;

void gettree();
void Insert();
void fstTravel(int x);

int main()
{
    gettree();
    Insert();
    fstTravel(1);
    return 0;
}

void Insert()
{
    int i, fa, flag;
    if(f[p].lc == 0) {
        f[p].lc = o;
    } else {
        f[o+1].rc=f[p].lc;
        f[p].lc = o;
    }
    /*printf("AFTER:\nLC: \n");
    for(i=1; i<=tot; ++i) {
        printf("%d ", f[i].lc);
    }
    printf("\n");
    printf("RC: \n");
    for(i=1; i<=tot; ++i) {
        printf("%d ", f[i].rc);
    }
    printf("\n");*/
}

void fstTravel(int x)
{
    if(x) {
        if(x<o) {
            if(f[x].lc!=0 && f[x].lc!=x) fstTravel(f[x].lc);
            printf("%d ", x);
            if(f[x].rc!=0 && f[x].rc!=x) fstTravel(f[x].rc);
        }else {
            if(f[x+1].lc!=0 && f[x+1].lc!=x) fstTravel(f[x+1].lc);
            printf("%d ", x);
            if(f[x+1].rc!=0 && f[x+1].rc!=x) fstTravel(f[x+1].rc);
        }
    }
}

void gettree()
{
    char c;
    int num;
    // In f - l
    num=0;
    while((c=getchar())!='\n') {
        if(c!=' ') num=num*10+(c-'0');
        else {
            f[pf++].lc=num;
            num=0;
        }
    }
    f[pf++].lc=num;
    // In f - r
    num=0;
    pf=0;
    while((c=getchar())!='\n') {
        if(c!=' ') num=num*10+(c-'0');
        else {
            f[pf++].rc=num;
            num=0;
        }
    }
    f[pf++].rc=num;
    // In p
    scanf("%d\n", &p);
    // In s - l
    num=0;
    ps=pf;
    int flag=0;
    while((c=getchar())!='\n') {
        if(c!=' ') num=num*10+(c-'0');
        else {
            if(!flag) {
                o=num;
                ps=num;
                flag=1;
            }
            f[ps++].lc=num;
            num=0;
        }
    }
    f[o+ps++].lc=num;
    // In s - r
    num=0;
    ps=o;
    while((c=getchar())!='\n') {
        if(c!=' ') num=num*10+(c-'0');
        else {
            f[ps++].rc=num;
            num=0;
        }
    }
    f[o+ps++].rc=num;
    tot=o+ps;
    int i;
    /*printf("LC: \n");
    for(i=1; i<=tot; ++i) {
        printf("%d ", f[i].lc);
    }
    printf("\n");
    printf("RC: \n");
    for(i=1; i<=tot; ++i) {
        printf("%d ", f[i].rc);
    }
    printf("\n");*/
}