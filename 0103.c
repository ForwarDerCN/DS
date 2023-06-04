#include <stdio.h>
#define MAXN 6
#define MAXM 4
#define MAXL 65535

int score[MAXN][MAXM];
// College && Gender
// Gender 1-M  2-F

int main()
{
    char s[MAXL], gender, college, c;
    int sc;
    while((c=getchar())!=EOF) {
       // while((c=getchar())!=' ') ;
        scanf(" %c %c %d\n", &gender, &college, &sc);
        int g=(gender=='M')?1:2;
        int cc=college-'A'+1;
        score[cc][g]+=sc;
    }
    int i;
    for(i=1; i<=5; ++i) {
        if(score[i][1])
            printf("%c M %d\n", 'A'+i-1, score[i][1]);
        if(score[i][2])
            printf("%c F %d\n", 'A'+i-1, score[i][2]);
        if(score[i][1]+score[i][2])
            printf("%c %d\n", 'A'+i-1, score[i][1]+score[i][2]);
    }
    return 0;
}