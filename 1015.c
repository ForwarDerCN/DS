#include <stdio.h>
#include <string.h>
#define MAXL 1000006

char s[MAXL];

int main()
{
    int i=0, j;
    int ans;
    char c;
    while((c=getchar()) != '\n') {
        s[i++]=c;
    }
    s[i]='\0';
    int l=strlen(s);
    //printf("Len of s: %d\n", l);
    i=0; j=l-2;
    while(i<j) {
        if(s[i]!=s[j]) break;
        i++;
        j--;
    }
    if(i==j && s[i]==s[j] && s[i]=='&') ans=1;
    else ans=0;
    printf("%d\n", ans);
    return 0;
}