#include <stdio.h>
#include <stdbool.h>
#define MAXN 21

int n, arrsize;

int main()
{
    scanf("%d %d", &n, &arrsize);
    if(n>arrsize) {
        printf("-1\n");
        return 0;
    }
    unsigned long long frac=1, times=1, a[MAXN];
    int i;
    bool flag=false;
    for(i=0; i<n; ++i) {
        if(i>0) frac*=i;
        a[i]=frac*times;
        if(a[i]>(((unsigned long long)1<<32)-1)) {
            flag=true;
            break;
        }
        times*=2;
    }
    if(flag) printf("-1\n");
    else {
        for(i=0; i<n; ++i) 
            printf("%lld ", a[i]);
        printf("\n");
    }
    return 0;
}