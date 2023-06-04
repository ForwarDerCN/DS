#include <iostream>
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
int n, k;
int a, b;
graph g;

// get arcs using the form of a-b,c-d,e-f
void init()
{
    scanf("%d,%d\n", &n, &k); // n nodes; k length
    scanf("%d,%d\n", &a, &b);
    char c;
    int v, w;
    while(scanf("%d-%d", &v, &w)) {
        arc *p = new arc;
        p->adjvex = w;
        p->nextarc = g.vexs[v].firstarc;
        g.vexs[v].firstarc = p;
        g.arcnum++; 
        scanf("%c", &c);
        if(c == ',') continue;
        else break;
    }
}

// Check if there is a simple path with length k from v to w
int dfs(int v, int w, int len)
{
    if(len == k && v==w) return 1;
    if(len == k) return 0;
    arc *p = g.vexs[v].firstarc;
    while(p) {
        if(dfs(p->adjvex, w, len+1)) return 1;
        p = p->nextarc;
    }
    return 0;
}

int main()
{
    init();
    if(dfs(a, b, 0)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}