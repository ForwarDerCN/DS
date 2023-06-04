#include <stdio.h>
#define MAXN 10007

typedef struct bnode {
    char data;
    int fc, ns;
}bnode;

bnode t[MAXN];
int tot;
void gettree();
void printt(int x, int depth);

int main()
{
    gettree();
    printt(1, 0);
    return 0;
}

void gettree()
{
    int f, n;
    char ch;
    int i=1;
    while(scanf("%c %d %d\n", &ch, &f, &n) != EOF) {
        t[i].data=ch;
        t[i].fc=f;
        t[i].ns=n;
        i++;
    }
    tot=i-1;
}

void printt(int x, int depth)
{
    int i;
    if(x!=-1) {
        for(i=1; i<=depth; ++i) printf("-");
        printf("%c\n", t[x].data);
        if(t[x].fc!=-1) printt(t[x].fc, depth+1);
        if(t[x].ns!=-1) printt(t[x].ns, depth);
    }
}