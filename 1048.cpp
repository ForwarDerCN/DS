#include <iostream>
#include <cstdio>
#define MAXV 1007
using namespace std;

typedef struct arc {
    int adjvex;
    struct arc *nextarc;
}arc;
typedef struct vex {
    int data;
    arc *firstarc;
}vex;
typedef struct {
    vex vexs[MAXV];
    int vexnum, arcnum;
}graph;

graph g;
int n, m, a, b;

// Check if there is a path from v to w
int dfs(int v, int w)
{
    if(v==w) return 1;
    arc *p = g.vexs[v].firstarc;
    while(p) {
        if(dfs(p->adjvex, w)) return 1;
        p = p->nextarc;
    }
    return 0;
}

int main()
{
    cin>>n;
    // Get arcs using the form of a-b,c-d,e-f
    char c;
    while(scanf("%d-%d", &a, &b)) {
        arc *p = new arc;
        p->adjvex = b;
        p->nextarc = g.vexs[a].firstarc;
        g.vexs[a].firstarc = p;
        g.arcnum++;
        scanf("%c", &c);
        if(c == ',') continue;
        else break;
    }
    scanf("%d,%d", &a, &b);
    if(dfs(a, b)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}