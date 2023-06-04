#include <stdio.h>
#define MAXN 20005

int m, n, sm, sn, dir, color;
int mp[MAXN][MAXN], vis[MAXN][MAXN];
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};
void search(int x, int y);

int main()
{
    scanf("%d %d %d %d %d", &m, &n, &sm, &sn, &dir);
    int i, j;
    for(i=0; i<m; ++i)
        for(j=0; j<n; ++j) 
            scanf("%d", &mp[i][j]);
    color=mp[sm][sn];
    search(sm, sn);
    for(i=0; i<m; ++i) {
        for(j=0; j<n; ++j) 
            printf("%d", mp[i][j]);
        printf("\n");
    }
    return 0;   
}

void search(int x, int y)
{
    mp[x][y]=2;
    vis[x][y]=1;
    int k;
    for(k=0; k<4; ++k) {
        int nx=x+dx[k], ny=y+dy[k];
        if(nx>=0 && nx<m && ny>=0 && ny<n && mp[nx][ny]==color && !vis[nx][ny]) 
            search(nx, ny);
    }
}