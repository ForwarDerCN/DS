#include <stdio.h>
#define MAXL 10007

int a[MAXL][MAXL];
int m, n;

int main()
{
    scanf("%d %d", &m, &n);
    int i, j;
    for(i=1; i<=m; ++i)
        for(j=1; j<=n; ++j)
            scanf("%d", &a[i][j]);
    
}