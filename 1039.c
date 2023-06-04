#include <stdio.h>
#define MAXN 10007

int l[MAXN], r[MAXN];
int pr, pl;

int main()
{
    int num;
    char c;
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
    int i;
    for(i=0; i<pr; ++i) {
        printf("%d", r[i]);
        if(i!=pr-1) printf(" ");
    }
    printf("\n");
    for(i=0; i<pl; ++i) {
        printf("%d", l[i]);
        if(i!=pl-1) printf(" ");
    }
    return 0;
}