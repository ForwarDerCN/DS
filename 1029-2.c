#include <stdio.h>
#include <string.h>
#define MAXL 100007

char s[MAXL];

int main()
{
    scanf("%s", s);
    int i, j, k, l;  // i -- starting point ; j -- length ; k -- new string point; l -- new len
    char ts[MAXL];
    int maxl=0, pos;
    int len=strlen(s);
    for(i=0; i<len; ++i) {
        for(j=0; i+j<len; ++j) {
            ts[j]=s[i+j];
            for(k=i+1; k+j<len; ++k) {
                int flag=1;
                for(l=k; l<=k+j; ++l) {
                    if(s[l]!=ts[l-k]) {
                        flag=0;
                        break;
                    }  
                }
                if(flag && j>maxl) {
                    maxl=j;
                    pos=i;
                }
            }
        }
    }
    if(maxl>0) {
        for(i=pos; i<=pos+maxl; ++i) printf("%c", s[i]);
        printf(" %d\n", pos);
    }else 
        printf("-1\n");
    return 0;
}