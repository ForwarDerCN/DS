#include <stdio.h>
#include <string.h>
#define MAXL 100005

char s[MAXL], t[MAXL], v[MAXL];
char *tail;
int isfind;
void Replace(char s[], char t[]);

int main()
{
    scanf("%s %s %s", s, t, v);
    Replace(s, t);
    if(isfind) printf("%s%s%s\n", s, v, tail);
    else printf("%s\n", s);
    return 0;
}

void Replace(char s[], char t[])
{
    char *pos=strstr(s, t);
    if(pos == 0) {
        return;
    }
    isfind=1;
    *pos = '\0';
    tail = pos + strlen(t);
}