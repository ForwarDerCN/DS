#include <iostream>
#define MAXV 1007
using namespace std;

typedef struct arc {
    int adjvex;
    struct arc *nextarc;
}arc;
typedef struct vex {
    int data;
    int MPL;
    arc *firstarc;
}vex;
typedef struct {
    vex vexs[MAXV];
    int vexnum, arcnum;
}graph;
int n;
int v, w;
graph g;

// get the graph using the form of a-b,c-d,e-f
void init()
{
    scanf("%d\n", &n);
    char c;
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

// Get longest path starting from v and store it in MPL
void dfs(int origin, int v, int len)
{
    arc *p = g.vexs[v].firstarc;
    while(p) {
        dfs(origin, p->adjvex, len+1);
        if(len > g.vexs[origin].MPL) g.vexs[origin].MPL = len;
        p = p->nextarc;
    }
}

int main()
{
    init();
    // Get MPL of each vertex
    for(int i = 1; i <= n; i++) {
        dfs(i, i, 1);
    }
    // Output the longest path of each node using the form of a,b,c
    for(int i = 1; i <= n; i++) {
        printf("%d", g.vexs[i].MPL);
        if(i != n) printf(",");
    }
    return 0;
}