#include <stdio.h>
#include <stdlib.h>
#define MAXN 1007

typedef struct OLNode {
    int i, j;   // 非零元的行列下标
    int e;
    struct OLNode *right, *down;    // 行表和列表的后继链域
}OLNode, *OLink;

typedef struct {
    OLink *rhead, *chead;   // 行列表头数组的头指针
    int mu, nu, tu;     // 行数、列数、非零元个数
}CrossList;

int mm, nn;
int bufm[MAXN];
int pm;
CrossList a, b;

void Create(CrossList *m);
void Insert(CrossList *A, OLink node);

int main()
{
    scanf("%d %d", &mm, &nn);
    Create(&a);
    Create(&b);

    /*int j;
    OLNode *pa, *pb, *pre;
    OLNode *hl[MAXN];
    pa=a.rhead[1];
    pb=b.rhead[1];
    pre=NULL;
    for(j=1; j<a.nu; ++j) hl[j]=a.chead[j];
    while(pb!=NULL) {
        OLNode *p;
        p=(OLNode *)malloc(sizeof(OLNode));
        if(pa==NULL || pa->j > pb->j) {
            p->i=pb->i; p->j=pb->j; p->e=pb->e;
            p->down=pb->down; p->right=pb->right;
            if(pre == NULL)     a.rhead[p->i]=p;
            else {
                pre->right=p;
                p->right=pa;
                pre=p;
            }
            if(!a.chead[p->j] || a.chead[p->j]->i > p->i) {
                p->down=a.chead[p->j];
                a.chead[p->j]=p;
            }
        }
    }*/

    // Add
    OLink now;
    int k;
    for(k=1; k<=b.mu; k++)
    {
        now=b.rhead[k];
        while(now) {
            OLink temp=(OLink)malloc(sizeof(OLNode));
            temp->i=now->i, temp->j=now->j, temp->e=now->e;
            temp->down=now->down, temp->right=now->right;  // copy
            Insert(&a, temp);
            now=now->right;
        }
    }

    // print V
    int tot=a.tu;
    for(k=1; k<=mm; ++k) {
        OLNode *temp=a.rhead[k];
        while(temp) {
            printf("%d", temp->e);
            tot--;
            if(tot>0) printf(" ");
            temp=temp->right;
        }
    }
    //printf("END OF V");
    printf("\n");
    // print B
    int i, j;
    for(i=1; i<=mm; ++i) {
        OLNode *temp=a.rhead[i];
        for(j=1; j<=nn ;++j) {
            if(temp && i==temp->i && j==temp->j) {
                printf("1");
                if(j!=nn)   printf(" ");
                temp=temp->right;
            }else {
                printf("0");
                if(j!=nn)   printf(" ");
            }
        }
        if(i!=mm) printf("\n");
    }
    return 0;
}

void Create(CrossList *m)
{
    //if(m) free(m);
    m->mu=mm;
    m->nu=nn;

    // in m - V
    char cc;
    int num=0;
    int sign=1;
    int i, j;

    pm=0;
    getchar();
    while((cc=getchar()) != '\n') {
        if(cc!=' ') {
            if(cc=='-') sign=-1;
            else num=num*10+(cc-'0');
        }
        else {   // cc = ' '
            bufm[pm]=num*sign;
            //printf("Get: %d\n", num*sign);
            pm++;
            sign=1;
            num=0;
        }
    }
    bufm[pm]=num*sign;
    pm++;
    m->tu=pm;

    // Alloc heads
    m->rhead=(OLink *)malloc((mm+1)*sizeof(OLink));
    m->chead=(OLink *)malloc((nn+1)*sizeof(OLink));
    for(i=1; i<=mm; ++i) {
        m->rhead[i]=NULL;
    }
    for(i=1; i<=nn; ++i) {
        m->chead[i]=NULL;
    }

    // input m - B
    int p, ppm=0;
    for(i=1; i<=mm; ++i) {
        for(j=1; j<=nn; ++j) {
            scanf("%d", &p);
            if(p) {
                OLNode *np;
                np=(OLNode *)malloc(sizeof(OLNode));
                np->i=i;
                np->j=j;
                np->e=bufm[ppm++];
                // Insert Row
                if(m->rhead[i]==NULL || m->rhead[i]->j > j) {  // fst row
                    np->right=m->rhead[i];
                    m->rhead[i]=np;
                }else {  // find which row
                    OLNode *nq;
                    for(nq=m->rhead[i]; (nq->right) && nq->right->j < j; nq=nq->right) ;
                    np->right=nq->right;
                    nq->right=np;
                }
                // Insert Col
                if(m->chead[j]==NULL || m->chead[j]->i > i) {  // fst row
                    np->down=m->chead[j];
                    m->chead[j]=np;
                }else {  // find which row
                    OLNode *nq;
                    for(nq=m->chead[j]; (nq->down) && nq->down->i < i; nq=nq->down) ;
                    np->down=nq->down;
                    nq->down=np;
                }
            }
        }
    }
}

void Insert(CrossList *A, OLink node)
{
    int r=node->i, c=node->j, v=node->e;
    int del=0, added=0;     // del表示要不要删结点，added表示要不要加入结点
    if(A->rhead[r]==NULL||A->rhead[r]->j>c) {  //直接插在开头
        node->right=A->rhead[r];
        A->rhead[r]=node;
        added=1;
        A->tu++;
    }
    else {
        OLink temp=A->rhead[r],pre=temp;
        while(temp&&temp->j<c) //找到插入位置。保留前驱pre非常有用。
        {
            pre=temp;
            temp=temp->right;
        }
        if(!temp)  // 因为第r行至少有一个结点，则temp为NULL说明pre->j<c，需要插入结点
        {
            pre->right=node;
            A->tu++;
            added=1;
        }
        else if(temp->j==c)  // 等于要分情况:有一个结点和有多个结点
        {
            temp->e+=v;
            if(!temp->e)
            {
                del=1;
                A->tu--;
                if(pre==temp) // 我们只有头指针，没有头结点，所以pre==temp这里要特殊处理
                {
                    A->rhead[r]=temp->right; //有一个结点
                }
                else
                {
                    pre->right=temp->right; // 有多个结点
                }
            }
        }
        else if(temp->j>c) 
        {
            added=1;
            A->tu++;
            node->right=temp,pre->right=node;
        }
    }

    if(A->chead[c]==NULL||A->chead[c]->i>r)
    {
        node->down=A->chead[c];
        A->chead[c]=node;
    }
    else
    {
        OLink temp=A->chead[c],pre=temp;
        while(temp&&temp->i<r)
        {
            pre=temp;
            temp=temp->down;
        }
        if(added==1)
        {
            node->down=temp;
            pre->down=node;
        }
        else if(del==1)
        {
            pre->down=temp->down;
            free(temp),free(node);
        }
        else if(!added&&!del) free(node);
    }
}