#include <stdio.h>
#define MAXN 10007

typedef struct bt {
    int order;
    char data;
    int lc, rc;
    int depth;
}bt;
bt t[MAXN];
int num=0;

int main()
{
    char ch;
    int l, r, i=1;
    t[1].depth=1;
    while(scanf("%c %d %d\n", &ch, &l, &r)!=EOF) {
        t[i].order=i;
        t[i].data=ch;
        t[i].lc=l;
        t[i].rc=r;
        t[l].depth=t[i].depth+1;
        t[r].depth=t[i].depth+1;
        i++;
    }
    num=i-1;
    int d=t[num].depth;
    int isPerf=1;
    for(i=1; i<=num; ++i) {
        if(!((t[t[i].lc].order==t[i].order*2 || t[i].lc==-1) && t[t[i].rc].order==i*2+1 || t[i].rc==-1))
            isPerf=0;
    }
    if(isPerf) printf("Yes");
    else printf("No");
    return 0;
}
