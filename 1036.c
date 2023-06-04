#include <stdio.h>
#define MAXN 10007

int t[MAXN], l[MAXN], r[MAXN];
int pt, pr, pl;
int u, v;
int search(int u, int v);

int main()
{
    char c;
    int num;
    // In t
    num=0;
    while((c=getchar())!='\n') {
        if(c!=' ') num=num*10+(c-'0');
        else {
            t[pt++]=num;
            num=0;
        }
    }
    t[pt++]=num;
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
    printf("%d\n", search(u, v));
    return 0;
}

int search(int u, int v)
{
    if(t[u]==v) return 1;
    else {
        if(t[u] && search(t[u], v)) return 1;
    }
    return 0;
}