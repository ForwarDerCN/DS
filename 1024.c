#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXL 100005

char s[MAXL], t[MAXL], r[MAXL];
int ps, pt, pr;
bool vis[MAXL];
int ord[MAXL];

int main()
{
    scanf("%s %s", s, t);
    int i, j, num=0;
    for(i=0; i<strlen(s); ++i) {
        char cur=s[i];
        if(vis[cur]) continue ;
        if(strchr(t, cur) == NULL) {
            //printf("Pr: %d\n", pr);
            ord[pr]=i;
            r[pr++]=cur;
            for(j=i; j<strlen(s); ++j) {
                if(s[j] == cur) {
                    vis[s[j]]=true;
                    num++;
                    //printf("Num %d\n", num);
                }
            }
        }
    }
    if(num==0) {
        printf("-1\n");
        return 0;
    }
    r[pr]='\0';
    printf("%s ", r);
    for(i=0; i<pr; ++i) printf("%d", ord[i]);
    printf("\n");
    return 0;
}