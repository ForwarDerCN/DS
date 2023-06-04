#include <stdio.h>
#include <stdbool.h>
#define MAXL 102
#define MAX(X, Y) (X>Y ? X : Y)

char a[MAXL], b[MAXL];
char c;

int main()
{
    bool isa=true;
    int pa=0, pb=0;
    int ans;
    while((c=getchar())!=EOF) {
        if(isa) a[pa]=c, pa++;
        else b[pb]=c, pb++;
        c=getchar();
        if(c=='\n') isa=false;
    }
    int i;
    for(i=0; i<MAX(pa, pb); ++i) {
        if(a[i]!=b[i]) break; 
    }
    if(i==pa && i==pb) ans=0;
    else {
        if(a[i+1]>b[i+1]) ans=2;
        else ans=1;
    }
    printf("%d\n", ans);
    return 0;
}