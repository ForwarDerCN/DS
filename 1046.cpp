#include <stdio.h>
#include <stdlib.h>
#define INF 100007
#define MAXN 1007

typedef struct arc {
    int adjvex;
    struct arc *nextarc;
}arc;
typedef struct vnode {
    int data;
    arc *firstarc;
}vnode;
typedef struct {
    vnode vertices[MAXN];
    int vexnum, arcnum;  // Ignore Kind -- Know DG
}ALGraph;

void Create();
int Locate(int vp);
void AddVertex(int vp);
void AddArc(int a, int b);

ALGraph g;
int m, n;

int main()
{
    Create();
    scanf("%d,%d\n", &n, &m);
    int a, b;
    int oflag = 1;
    while(m--) {
        if(m>=1) scanf("%d-%d,", &a, &b);
        else scanf("%d-%d", &a, &b);
        if(a==0) oflag = 0;
        AddVertex(a);
        AddVertex(b);
        AddArc(a, b);
    }
    int i;
    for(i=oflag; i<n+oflag; ++i) {
        printf("%d ", i);
        arc *p;
        p = g.vertices[i].firstarc;
        if(p) p = p->nextarc; // visit first
        while(p != NULL) {
            printf("%d", p->adjvex);
            if(p->nextarc != NULL) printf(",");
            p = p->nextarc;
        }
        printf("\n");
    }
    return 0;
}

void Create()
{
    g.vexnum = g.arcnum = 0;
}

int Locate(int vp)
{
    int k;
    for(k=0; k<g.vexnum; ++k) {
        if(g.vertices[k].data == vp) return k;
    }
    return -1;
}

void AddVertex(int vp)
{
    if(Locate(vp) != -1) return ;
    g.vertices[g.vexnum].data = vp;
    arc *p;
    p = (arc *)malloc(sizeof(arc));
    p->adjvex = -1;
    p->nextarc = NULL;
    g.vertices[g.vexnum].firstarc = p;
    g.vexnum++;
}

void AddArc(int a, int b)
{
    arc *p, *q, *pre; // p-- find suitable insert position ; q -- new node
    int j;
    j = Locate(b);
    p = g.vertices[a].firstarc; // node a's head node ( Use head node to ease insertion)
    q = (arc *)malloc(sizeof(arc));
    q -> adjvex = b;

    if(p->adjvex == -1) {
        q->nextarc = NULL;
        p->adjvex = INF;
        p->nextarc = q; // Give the first son
    } else {
        while(p != NULL && p->adjvex > b) {
            pre = p;
            p = p->nextarc;
        }
        q->nextarc = p;
        pre->nextarc = q;
    } 

    g.arcnum++;
}
