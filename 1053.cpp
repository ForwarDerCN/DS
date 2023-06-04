#include <iostream>
#define MAXV 10007
#define INT_MAX 0x7fffffff
using namespace std;

int n, origin;
// Store the graph using adjacency list
typedef struct arc {
    int adjvex;
    int w; // weight of the arc
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

// Get the graph using the form of a-b weight
void init()
{
    scanf("%d %d", &n, &origin);
    int a, b, v;
    while(scanf("%d-%d %d\n", &a, &b, &v) != EOF) {
        arc *p = new arc;
        p->adjvex = b;
        p->w = v;
        p->nextarc = g.vexs[a].firstarc;
        g.vexs[a].firstarc = p;
        g.arcnum++;
    }
}

// Get the shortest path from v using Dijsktra algorithm
void dijsktra(int v)
{
    int dist[MAXV];
    int path[MAXV];
    bool s[MAXV];
    for(int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        s[i] = false;
    }
    arc *p = g.vexs[v].firstarc;
    // Initialize dist and path (Init nodes adjacent to v)
    while(p) {
        dist[p->adjvex] = p->w; 
        path[p->adjvex] = v; 
        p = p->nextarc;
    }
    dist[v] = 0;
    s[v] = true; 
    for(int i = 1; i <= n; i++) {
        int min = INT_MAX;
        int u = v;
        for(int j = 1; j <= n; j++) {
            if(!s[j] && dist[j] < min) {
                min = dist[j]; // Find the node with the shortest distance from v
                u = j;
            }
        }
        // Add u to s and see from u, if there is a shorter path to other nodes
        s[u] = true;
        p = g.vexs[u].firstarc;
        // Update dist and path
        while(p) {
            if(!s[p->adjvex] && dist[u]+p->w < dist[p->adjvex]) { // If there is a shorter path
                dist[p->adjvex] = dist[u]+p->w;
                path[p->adjvex] = u; // previous node of p->adjvex is u
            }
            p = p->nextarc; // Check next node
        }
    }
    // Output the shortest distance from origin to each vertex using the form of a,b,c
    for(int i = 1; i <= n; i++) {
        if(i!=origin) {
            printf("%d", dist[i]);
            if(i != n) printf(",");
        }     
    }  
}

int main()
{
    init();
    dijsktra(origin);
    return 0;
}