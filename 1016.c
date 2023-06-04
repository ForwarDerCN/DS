#include <stdio.h>
#define MAXL 1000006

int main()
{
    char c;
    int lft=0, isok=1;
    while((c=getchar())!='\n') {
        if(c=='(') lft++;
        else if(c==')') {
            if(lft<=0) {
                isok=0;
                break;
            }else {
                lft--;
            }
        }else continue;
    }
    if(lft>0) isok=0;
    printf("%d\n", isok);
    return 0;
}
