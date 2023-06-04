#include <stdio.h>

int main()
{
    int x, xx, n, a;
    int ans=0;
    scanf("%d %d", &x, &n);
    xx=x;
    scanf("%d", &a);
    ans+=a;
    while(n--) {
        scanf("%d", &a);
        ans+=xx*a;
        xx=xx*x;
    }
    printf("%d\n", ans);
    return 0;
}