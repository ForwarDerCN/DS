#include <stdio.h>
#define MAXN 1000006

char la[MAXN], lb[MAXN], lc[MAXN], lg[MAXN];
int pa, pb, pc, pg;

int main()
{
    char c;
    while(scanf("%c", &c) !=EOF) {
        la[pa++]=c;
        if((c=getchar())=='\n' || c=='\t') break;
    } 
    int k;
    while(scanf("%c", &c) !=EOF) {
        lb[pb++]=c;
        if((c=getchar())=='\n' || c=='\t') break;
        //printf("C3 :%c    ", c);
    } 
    //printf("C1 :%c    ", c);
    while(scanf("%c", &c) !=EOF) {
       // printf("C2 :%c    ", c);
        lc[pc++]=c;
        getchar();
    } 

   /*for(k=0; k<pa; ++k) printf("%c, ", la[k]);
        printf("\n");
    for(k=0; k<pb; ++k) printf("%c, ", lb[k]);
        printf("\n");
    for(k=0; k<pc; ++k) printf("%c, ", lc[k]);
        printf("\n");*/

    int i, bb=0, cc=0;
    for(i=0; i<pa; ++i) {
        while(lb[bb]<la[i] && bb<pb-1) bb++;
        while(lc[cc]<la[i] && cc<pc-1) cc++;
        if(!(lb[bb]==la[i] && lc[cc]==la[i])/* || ((bb==pb-1 && lb[bb]!=la[i]) && (cc==pc-1 && lc[cc]!=la[i]))*/)
            lg[pg++]=la[i];
    }
    for(i=0; i<pg; ++i) {
        printf("%c", lg[i]);
        if(i<pg-1) printf(",");
    }
    printf("\n");
    return 0;
}