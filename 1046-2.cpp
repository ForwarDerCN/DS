#include <iostream>
#include <cstdio>
#define MAXN 1007
#define INF 10007
using namespace std;

int g[MAXN][MAXN];
int minc[MAXN], ise[MAXN];
int m, n, a, b;

int main()
{
    scanf("%d,%d\n", &n, &m); // n nodes; m arcs
    int oflag = 1;
    for(int i=0; i<MAXN; ++i) {
        minc[i] = INF;
        ise[i] = 1;
    }
    while(m--) {
        if(m>=1) scanf("%d-%d,", &a, &b);
        else scanf("%d-%d", &a, &b);
        if(a==0) oflag = 0;
        g[a][b] = 1;
        ise[a] = 0;
        if(b < minc[a]) minc[a] = b;
    }
    for(int i=oflag; i<oflag+n; ++i) {
        cout<<i;
        if(!ise[i]) cout<<" ";
        for(int j=oflag+n-1; j>=oflag; --j) {
            if(g[i][j] && j>minc[i]) cout<<j<<",";
            else if(g[i][j]) cout<<j;
        }
        if(i<oflag+n-1) cout<<endl;
    }
    return 0;
}
