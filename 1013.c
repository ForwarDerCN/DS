#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000006

typedef struct Node {
	int data;
	struct Node *prior, *next;
	int freq;
	int fp;
}node;
node *initl();
void insert(node *l, int x);
void locate(node *l, int x, int fp); // keep the high frequency at front
int n, st[MAXN];

int main()
{
	scanf("%d", &n);
	int i, vis;
	for(i=1; i<=n; ++i) {
		scanf("%d", &st[i]);
	}
	node *l=initl();
	for(i=n; i>=1; --i) {
		insert(l, st[i]);
	}
	int fp=1;
	while(scanf("%d", &vis) != EOF) {
		locate(l, vis, fp++);
	}
	node *q=l->next;
	node *p;
	while(q!=l) {
		p=q;
		while(p->prior!=l && ((p->freq)>(p->prior->freq) || (p->freq==p->prior->freq && p->fp<p->prior->fp))) {
			node *tp, *tpre;
			tpre=p->prior;    // swap p and p->prior
			tp=p;
			printf("Want to swap: %d and %d \n", tpre->data, tp->data);

			tpre->next=tp->next;
			tp->prior=tpre->prior;
			tpre->prior=tp;
			tp->next=tpre;

			tp->prior->next=tp;
			tpre->next->prior=tpre;

			p=tp->prior;
		}
		q=q->next;
	}
	
	p=l;
	p=p->next;
	while(p!=l) {
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n");
	return 0;
}

node *initl()
{
	node *ll=(node *)malloc(sizeof(node));
	ll->prior=ll;
	ll->next=ll;
	ll->data=ll->freq=0;
	return ll;
}

void insert(node *l, int x)  // checked
{
	node *p=(node *)malloc(sizeof(node));
	p->data=x;
	p->freq=0;
	p->fp=-1;
	p->next=l->next;
	l->next->prior=p;
	p->prior=l;
	l->next=p;
}

void locate(node *l, int x, int fp)
{
	node *p=l->next;
	while(p!=l && p->data!=x) {
		p=p->next;
	} 
	if(p->data==x) {
		p->freq++;
		if(p->fp==-1)	p->fp=fp;
		//printf("Visit Data: %d, freq to %d \n", p->data, p->freq); 
		while(p->prior!=l && ((p->freq)>(p->prior->freq) || (p->freq==p->prior->freq && p->fp<p->prior->fp))) {
			node *tp, *tpre;
			tpre=p->prior;    // swap p and p->prior
			tp=p;
			printf("Want to swap: %d and %d \n", tpre->data, tp->data);

			tpre->next=tp->next;
			tp->prior=tpre->prior;
			tpre->prior=tp;
			tp->next=tpre;

			tp->prior->next=tp;
			tpre->next->prior=tpre;

			p=tp->prior;
		}
	}
}