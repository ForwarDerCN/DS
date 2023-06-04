#include <stdio.h>
#include <stdlib.h>
#define MAXL 100004

typedef struct Squeue {
    int *base;
    int front;
    int rear;
}squeue;

squeue *initq() 
{
    squeue *sq=(squeue *)malloc(sizeof(squeue));
    sq->base=(int *)malloc(MAXL * sizeof(int));
    sq->front=sq->rear=0;
}

void enq(squeue *q, int x)
{
    q->base[q->rear]=x;
    q->rear=(q->rear+1) % MAXL;
}

int deq(squeue *q)
{
    int ret;
    ret=q->base[q->front];
    q->front=(q->front+1) % MAXL;
}

int lenq(squeue *q)
{
    return (q->rear - q->front + MAXL) % MAXL;
}

int main()
{
    squeue *q;
    int n, e, i;
    q=initq();
    scanf("%d", &n);
    for(i=0; i<n; ++i) {
        scanf("%d", &e);
        enq(q, e);
    }
    i=1;
    while(lenq(q)>0) {
        printf("%d", deq(q));
        if(i++<n) printf(",");
    }
    printf("\n");
    return 0;
}