#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 80
#define MAXD 100005

typedef struct Chunk {
    char s[SIZE];
    struct Chunk *next;
}chunk;

typedef struct {
    chunk *head, *tail;
    int curlen;
}lstring;

int st[MAXD], n, stp=0;

int main()
{
    scanf("%d", &n);
    char c;
    int i;
    lstring str;
    chunk *ss=(chunk *)malloc(sizeof(chunk));
    str.head=str.tail=ss;
    for(i=0; i<n; ++i) {
        c=getchar();
        str.tail->s[i%SIZE]=c;
        str.curlen++;
        if(str.curlen>0 && str.curlen%SIZE == 0) {
            chunk *ns=(chunk *)malloc(sizeof(chunk));
            str.tail->next=ns;
            str.tail=ns;
        }
    }
    int tot = 0;
    int flag=1;
    while(str.head != str.tail) {
        char *t=str.head->s;
        for(i=0; i<strlen(t); ++i) {
            if(tot <= n/2) st[stp++]=t[i];
            if(tot%2 && tot == n/2+1) continue;
            if(tot > n/2) {
                if(st[stp-1] == t[i]) stp--;
                else {
                    flag=0;
                    break;
                }
            }
        }
        str.head=str.head->next;
    }
    printf("%d\n", flag);
    return 0;
}