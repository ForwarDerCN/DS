#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int i, j, v;
    struct node *right, *down;
}OLNode, *OList;

typedef struct {
    OList *rhead, *chead;
    int mu, nu, tu;
}CrossList;

void Create_CrossList(CrossList *L, int m, int n, int t)
{
    L->chead=(OList*)malloc(sizeof(OList)*(m+1));
    if(!L->chead) {
        printf("Error alloc\n");
        exit(-1);
    }
    L->rhead=(OList*)malloc(sizeof(OLNode)*(n+1));
    if(!L->rhead) {
        printf("Error alloc\n");
        exit(-1);
    }
    L->mu=m,L->nu=n,L->tu=t;
    int i;
    for(i=1;i<=m;i++)
    {
        L->rhead[i]=NULL;
    }
    for(i=1;i<=n;i++)///初始化指针数组
    {
        L->chead[i]=NULL;
    }
    for(i=1;i<=t;i++)
    {
        int r,c,v;
        scanf("%d%d%d",&r,&c,&v);
        OList node=(OList)malloc(sizeof(OLNode));
        if(!node)
        {
            printf("结点内存分配失败\n");
            exit(-1);
        }
        node->i=r,node->j=c,node->v=v;
        if(L->rhead[r]==NULL||L->rhead[r]->j>c)///可以直接插在开头
        {
            node->right=L->rhead[r];
            L->rhead[r]=node;
        }
        else
        {
            OList temp;
            for(temp=L->rhead[r];temp->right&&temp->right->j<c;temp=temp->right);
            ///寻找插入位置
            node->right=temp->right;
            temp->right=node;
        }
        if(L->chead[c]==NULL||L->chead[c]->i>r)///可以直接插在开头
        {
            node->down=L->chead[c];
            L->chead[c]=node;
        }
        else
        {
            OList temp;
            for(temp=L->chead[c];temp->down&&temp->down->i<r;temp=temp->down);
            ///寻找插入位置
            node->down=temp->down;
            temp->down=node;
        }
    }
}

void Insert(CrossList *A,OList node)
{
    int r=node->i,c=node->j,v=node->v;
    int del=0,added=0;///del表示要不要删结点，added表示要不要加入结点
    if(A->rhead[r]==NULL||A->rhead[r]->j>c)///直接插在开头
    {
        node->right=A->rhead[r];
        A->rhead[r]=node;
        added=1;
        A->tu++;
    }
    else
    {
        OList temp=A->rhead[r],pre=temp;
        while(temp&&temp->j<c)///找到插入位置。保留前驱pre非常有用。
        {
            pre=temp;
            temp=temp->right;
        }
        if(!temp)///因为第r行至少有一个结点，则temp为NULL说明pre->j<c，需要插入结点
        {
            pre->right=node;
            A->tu++;
            added=1;
        }
        else if(temp->j==c)///等于要分情况:有一个结点和有多个结点
        {
            temp->v+=v;
            if(!temp->v)
            {
                del=1;
                A->tu--;
                if(pre==temp)///我们只有头指针，没有头结点，所以pre==temp这里要特殊处理
                {
                    A->rhead[r]=temp->right;///有一个结点
                }
                else
                {
                    pre->right=temp->right;///有多个结点
                }
            }
        }
        else if(temp->j>c)///这一段不能省去。
        {
            added=1;
            A->tu++;
            node->right=temp,pre->right=node;
        }
    }
    if(A->chead[c]==NULL||A->chead[c]->i>r)///直接插在开头
    {
        node->down=A->chead[c];
        A->chead[c]=node;
    }
    else
    {
        OList temp=A->chead[c],pre=temp;
        while(temp&&temp->i<r)///找到插入位置。保留前驱pre非常有用。
        {
            pre=temp;
            temp=temp->down;
        }
        if(added==1)///需要插入
        {
            node->down=temp;
            pre->down=node;
        }
        else if(del==1)///需要删除
        {
            pre->down=temp->down;
            free(temp),free(node);
        }
        else if(!added&&!del) free(node);
    }
}
void add(CrossList *A,CrossList *B)
{
    OList now;
    int k;
    for(k=1;k<=B->mu;k++)
    {
        now=B->rhead[k];
        while(now)
        {
            OList temp=(OList)malloc(sizeof(OLNode));
            temp->i=now->i,temp->j=now->j,temp->v=now->v;
            temp->down=now->down,temp->right=now->right;///做一份拷贝，因为插入时涉及down和right域的改变
            Insert(A,temp);
            now=now->right;
        }
    }
}
void print_result(CrossList *A)
{
    int k;
    for(k=1;k<=A->mu;k++)
    {
        OList temp=A->rhead[k];
        while(temp)
        {
            printf("%d %d %d\n",temp->i,temp->j,temp->v);
            temp=temp->right;
        }
    }
}
int main()
{
    CrossList *A=(CrossList*)malloc(sizeof(CrossList));
    CrossList *B=(CrossList*)malloc(sizeof(CrossList));
    int m,n,t1,t2;
    scanf("%d%d%d%d",&m,&n,&t1,&t2);
    Create_CrossList(A,m,n,t1);///创建十字链表
    Create_CrossList(B,m,n,t2);
    add(A,B);///加法
    print_result(A);///输出结果
    free(A),free(B);
    return 0;
}
/*
3 4 3 2
1 1 1
1 3 1
2 2 2
1 2 1
2 2 3
*/
/*
3 4 3 2
1 1 4
2 2 3
3 3 2
1 1 -4
2 2 -3
*/

