#include <stdio.h>
#define MAXN 1007
#define UB 0x0fffffff
#define LB -0x0fffffff

int a[MAXN][MAXN];
int m, n;
int isMinInRow[MAXN][MAXN];

int main()
{
    scanf("%d %d", &m, &n);
    int i, j;
    int minvalue=UB, mincol;   // In row -- min value & which col
    for(i=1; i<=m; ++i) {
        minvalue=UB;
        for(j=1; j<=n; ++j) {
            scanf("%d", &a[i][j]);
            if(a[i][j]<minvalue) {
                mincol=j;
                minvalue=a[i][j];
            }
        }
        isMinInRow[i][mincol]=1;
        for(j=1; j<=n; ++j) {
            if(a[i][j]==minvalue) {
                isMinInRow[i][j]=1;
            }
        }
    }
    int maxvalue=LB, minrow[MAXN], l=0, k; // In a col -- max value & which row
    for(j=1; j<=n; j++) {
        maxvalue=LB;
        for(i=1; i<=m; ++i) {
            if(a[i][j]>maxvalue) {
                l=0;
                maxvalue=a[i][j];
                minrow[l++]=i;
            }else if(a[i][j]==maxvalue) {
                minrow[l++]=i;
            }
        }
        for(k=0; k<l; ++k) {
            if(isMinInRow[minrow[k]][j]) {
                printf("%d ", a[minrow[k]][j]);
            }
        }
    }
    printf("\n");
    return 0;
}