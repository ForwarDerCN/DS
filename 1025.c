#include <stdio.h>
#include <string.h>
#define MAXL 100005

char s[MAXL], t[MAXL];
int StrCompare(char s[], char t[]);

int main()
{
    scanf("%s %s", s, t);
    printf("%d\n", StrCompare(s, t));
    return 0;
}

int StrCompare(char s[], char t[])
{
    int i=0;
    while(s[i] != '\0' && t[i] != '\0' && t[i] == s[i]) {
        i++;
    }
    if(s[i] == '\0' && t[i] == '\0')    return 0;
    else if(s[i] > t[i])    return 1;
    else return -1;
}