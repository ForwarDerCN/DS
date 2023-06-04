#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}qnode;

typedef struct Linkq {
    qnode *front;
    qnode *rear;
}linkq;


int getf(linkq *q)
{
    return q->front->next->data;
}

void enq(linkq *q, int x)
{
    qnode *p=(qnode *)malloc(sizeof(qnode));
    p->data=x;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;   // update new rear
}

void deq(linkq *q)
{
    qnode *p;
    p=q->front->next;   // get front ele store
    q->front->next=p->next;   // update new front
    if(q->rear==p) q->rear=q->front;   //  ??
    free(p);
}

linkq *initq()
{
    linkq *q=(linkq *)malloc(sizeof(linkq));
    q->front=q->rear=(qnode *)malloc(sizeof(qnode));
    q->front->next=NULL;
    return q;
}

int isempty(linkq *q)
{
    return (q->front==q->rear);
}

int main()
{
    linkq *q;
    int n, e, i;
    q=initq();
    scanf("%d", &n);
    for(i=0; i<n; ++i) {
        scanf("%d", &e);
        enq(q, e);
    }
    i=1;
    while(!isempty(q)) {
        printf("%d", getf(q));
        if(i++<n) printf(",");
        deq(q);
    }
    printf("\n");
    return 0;
}