#include <stdio.h>
#include <string.h>
#define MAXN 100005

char s[MAXN];
int n;

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    int i=0; 
    int j=strlen(s)-1;
    while(i<j) {
        if(s[i]!=s[j]) break;
        i++; j--;
    }
    if(i>=j) printf("1\n");
    else printf("0\n");
    return 0;
}