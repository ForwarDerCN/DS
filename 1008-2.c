#include <stdio.h>
#define MAXL 1000006

int main()
{
    int m, n;
    int la[MAXL], lb[MAXL];
    scanf("%d %d", &m, &n);
    int i;
    for(i=1; i<=m; ++i) {
        scanf("%d", &la[i]);
    }
    for(i=1; i<=n; ++i) {
        scanf("%d", &lb[i]);
    }
    for(i=1; i<=n; ++i) printf("%d ", lb[i]);
    for(i=1; i<=m; ++i) printf("%d ", la[i]);
    printf("\n");
    return 0;
}   