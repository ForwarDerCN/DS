#include <stdio.h>
#define MAXN 10007

int l[MAXN], r[MAXN];
int pl, pr;
int u, v;
int Search(int u, int c);

int main()
{
    char c;
    int num;
    // In l
    while((c=getchar())!='\n') {
        if(c!=' ') num=num*10+(c-'0');
        else {
            l[pl++]=num;
            num=0;
        }
    }
    l[pl++]=num;
    // In r
    num=0;
    while((c=getchar())!='\n') {
        if(c!=' ') num=num*10+(c-'0');
        else {
            r[pr++]=num;
            num=0;
        }
    }
    r[pr++]=num;

    scanf("%d %d", &u, &v);
    printf("%d", Search(u, v));
    return 0;
}

int Search(int u, int c)
{
    if(l[c]==u || r[c]==u) {
        return 1;
    }else {
        if(l[c] && Search(u, l[c])) return 1;
        if(r[c] && Search(u, r[c])) return 1;
    }
    return 0;
}