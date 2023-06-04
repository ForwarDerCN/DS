#include <stdio.h>
#define MAXN 100007

typedef struct bt {
    int order;
    char data;
    int lc, rc;
}bt;
bt t[MAXN];
bt st[MAXN];
int ps=0, num=0;
void init();
void push(bt x);
bt pop();
bt gettop();
int isempty();
void travel();

int main()
{
    int i=1;
    char ch;
    int l, r;
    while(scanf("%c %d %d\n", &ch, &l, &r)!=EOF) {
        t[i].order=i;
        t[i].data=ch;
        t[i].lc=l;
        t[i].rc=r;
        i++;
    }
    num=i-1;
    init();
    travel();
    return 0;
}

void init()
{
    bt base;
    base.data='#';
    base.lc=base.rc=-1;
    st[0]=base;
    ps++;
}

void push(bt x)
{
    st[ps]=x;
    ps++;
}

bt pop()
{
    ps--;
    bt ret=st[ps];
    bt emp;
    emp.data=0;
    emp.lc=emp.rc=0;
    st[ps]=emp;
    return ret;
}

bt gettop()
{
    return st[ps-1];
}

int isempty()
{
    return (gettop().data=='#');
}

void travel()
{
    bt c;
    push(t[1]);  // ROOT
    while(!isempty()) {
        c=gettop();
        printf("%c ", c.data);  // ROOT first
        if(t[c.order].lc!=-1) {
            push(t[t[c.order].lc]);  // Left subtree's ROOT
        } else {  // Left tree empty 
            while(!isempty()) {  // go to upmost in the right subtree
                c=pop();
                if(t[c.order].rc!=-1) {  // go up , until find somewhere can go right
                    push(t[t[c.order].rc]);    // Push the ROOT of right subtree
                    break;
                }
            }
        }
    }
}