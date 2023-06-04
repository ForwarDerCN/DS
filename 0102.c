#include <stdio.h>
#define MAXN 100005

int f[MAXN];
int fib(int k ,int m);
void init(int k);

int main()
{
    int k, m;
    scanf("%d%d", &k, &m);
    printf("%d\n", fib(k, m));
    return 0;
}

void init(int k)
{
    int i;
    for(i=0; i<=k-2; ++i)   f[i]=0;
    f[k-1]=1;
}

int fib(int k ,int m)
{
    init(k);
    int i, j;
    for(i=k; i<=m; ++i) {
        for(j=i-1; j>=i-k; --j) {
            f[i]+=f[j];
        }
    }
    return f[m];
}