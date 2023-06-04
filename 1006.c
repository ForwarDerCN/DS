#include <stdio.h>
#define MAXL 101

int main()
{
    int num, a[MAXL], x, n=0 ;
    while(scanf("%d", &num)!=EOF) {
        a[n]=num;
        n++;
    }
    x=a[n-1];
    n-=1;
    int i, j;
    for(i=0; i<n; ++i) {
        if(a[i]>x) {
            for(j=n-1; j>=i; --j) {
                a[j+1]=a[j];
            }
            a[i]=x;
            break;
        }
    }
    for(i=0; i<n+1; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}