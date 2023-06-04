#include <stdio.h>
#define MAXN 100005

int main()
{
    int f[MAXN], n, i;
    f[0]=1;
    scanf("%d", &n);
    for(i=1; i<=n; ++i) {
        f[i]=i*f[i/2];
    }
    printf("%d\n", f[n]);
    return 0;
}