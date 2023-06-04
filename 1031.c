#include <stdio.h>
#define MAXN 1007

int c[MAXN][MAXN], vis[MAXN][MAXN];
int m, n;

int main()
{
    scanf("%d %d", &m, &n);
    int i, j;
    for(i=0; i<m; ++i)
        for(j=0; j<n; ++j)
            scanf("%d", &c[i][j]);
    int x, y;
    for(x=m-1; x>=0; --x) {
        for(y=n-1; y>=0; --y) {
            if(c[x][y]) {
                if(c[x][y]>1 || c[x][y]<0) printf("%d", c[x][y]);
                if(x) printf("xE%d", x);
                if(y) printf("yE%d", y);
                if(x || y)  printf("+");
            }
        }
    }
    printf("\n");
    return 0;
}
