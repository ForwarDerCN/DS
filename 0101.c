#include <stdio.h>

int main()
{
    int a[3];
    for(int i=0; i<3; ++i) scanf("%d", &a[i]);
    for(int i=2; i>0; --i) {
        for(int j=i-1; j>=0; --j) {
            if(a[j]<a[i]) {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for(int i=0; i<3; ++i) printf("%d ", a[i]);
    printf("\n");
    return 0;
}