#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 1000006
using namespace std;

typedef struct Node {
    int data;
    int freq;
    int fv;
}node;
node l[MAXN];
int n, vis, tm=0;
void locate(int p, int tm);
bool cmp(node a, node b) {
    if(a.freq>b.freq) return true;
    else if(a.freq==b.freq && a.fv<b.fv) return true;
    else return false;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>l[i].data;
        l[i].freq=0;
        l[i].fv=-1;
    }
    while((scanf("%d", &vis))!=EOF) {
        locate(vis, tm++);
    }
    sort(l+1, l+n+1, cmp);
    for(int i=1; i<=n; ++i) {
        cout<<l[i].data<<" ";
    }
    cout<<endl;
    return 0;
}

void locate(int p, int tm)
{
    for(int i=1; i<=n; ++i) {
        if(l[i].data==p) {
            l[i].freq++;
            if(l[i].fv==-1) l[i].fv=tm;
            break;
        }
    }
}