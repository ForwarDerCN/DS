#include <stdio.h>
#include <string.h>
#define MAXL 10004

int main()
{
    char s[MAXL], t, c;
    int i=0;
    while((c=getchar())!='\n') {
        s[i++]=c;
    }
    s[i]='\0';
    i=0;
    int j=strlen(s)-1;
    while(i<j) {
        t=s[i];
        s[i]=s[j];
        s[j]=t;
        i++;
        j--;
    }
    printf("%s\n", s);
    return 0;
}