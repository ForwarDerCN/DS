#include <stdio.h>
#include <string.h>
#define MAXL 10004

int ishw(char s[]);

int main()
{
    char s[MAXL], c;
    int i=0;
    while(1) {
        i=0;
        while((c=getchar())!=EOF && c!='\n') {
            s[i++]=c;
            //getchar();
        }
        s[i]='\0';
        if(c==EOF)  break;
       // printf("Get:  %s\n", s);
        printf("%d\n", ishw(s));
    }
    return 0;
}

int ishw(char s[])
{
    int len=strlen(s);
    int i=0, j=len-2, flag=1;
    while(i<j) {
        if(s[i]!=s[j]) {
            flag=0;
            break;
        }
        i++;
        j--;
    }
    return flag;
}