#include <stdio.h>
#define MAXN 1007

// 三元组顺序表存储
int m, n;

typedef struct {
    int i, j;
    int e;
}Triple;
typedef struct {
    Triple data[MAXN];
    int mu, nu, tu;
    // 行数，列数，非零元个数
}TSMatrix;

TSMatrix a, b, c;
//int bufa[MAXN*MAXN], bufb[MAXN*MAXN];
int pa, pb;

int getValue(TSMatrix a, int x, int y);

int main()
{
    scanf("%d %d", &m, &n);
    a.mu=b.mu=c.mu=m;
    a.nu=b.nu=c.nu=n;
    a.tu=b.tu=c.tu=0;
    int i, j;
    char cc;
    int num=0;
    // in A - V
    int sign=1;
    getchar();
    while((cc=getchar()) != '\n') {
        if(cc!=' ') {
            if(cc=='-') sign=-1;
            else num=num*10+(cc-'0');
        }
        else {   // cc = ' '
            a.data[pa].e=num*sign;
            //printf("Get: %d\n", num*sign);
            pa++;
            sign=1;
            num=0;
        }
    }
    a.data[pa].e=num*sign;
    //printf("Get: %d\n", num*sign);
    pa++;
    // in A - B and Store
    int p;
    for(i=1; i<=m; ++i) {
        for(j=1; j<=n; ++j) {
            scanf("%d", &p);
            if(p) {
                a.data[a.tu].i=i;
                a.data[a.tu].j=j;
                a.tu++;
            }
        }
    }
    /*printf("i\tj\te\t\n");
    for(i=0; i<a.tu; ++i) {
        printf("%d\t%d\t%d\t\n", a.data[i].i, a.data[i].j, a.data[i].e);
    }*/

    // in B - V
    num=0;
    sign=1;
    getchar();
    while((cc=getchar()) != '\n') {
        if(cc!=' ') {
            if(cc=='-') sign=-1;
            else num=num*10+(cc-'0');
        }
        else {
            b.data[pb++].e=num*sign;
            sign=1;
            num=0;
        }
    }
    b.data[pb++].e=num*sign;
    // in B - B and Store
    for(i=1; i<=m; ++i) {
        for(j=1; j<=n; ++j) {
            scanf("%d", &p);
            if(p) {
                b.data[b.tu].i=i;
                b.data[b.tu].j=j;
                b.tu++;
            }
        }
    }

    /*printf("i\tj\te\t\n");
    for(i=0; i<b.tu; ++i) {
        printf("%d\t%d\t%d\t\n", b.data[i].i, b.data[i].j, b.data[i].e);
    }*/

    // Get c
    /*pa=pb=0;
    int pc=0;
    while((pa<=a.tu && pb<=b.tu)) {
        if((a.data[pa].i<b.data[pb].i) || ((a.data[pa].i == b.data[pb].i) && (a.data[pa].j<b.data[pb].j)) || (pb==b.tu && pa<a.tu)) {
            c.data[pc].i=a.data[pa].i;
            c.data[pc].j=a.data[pa].j;
            c.data[pc].e=a.data[pa].e;
            pa++;
            c.tu++;
            pc++;
            printf("Case 1\n");
        }else if((a.data[pa].i==b.data[pb].i) && (a.data[pa].j==b.data[pb].j)) {
            if((a.data[pa].e + b.data[pb].e) != 0) {
                c.data[pc].i=a.data[pa].i;
                c.data[pc].j=a.data[pa].j;
                c.data[pc].e=a.data[pa].e + b.data[pb].e;
                c.tu++;
                pc++;
                printf("Case 2.1\n");
            }
            pa++; pb++;
            printf("Case 2.2\n");
        }else {
            c.data[pc].i=b.data[pb].i;
            c.data[pc].j=b.data[pb].j;
            c.data[pc].e=b.data[pb].e;
            pb++;
            c.tu++;
            pc++;
            printf("Case 3\n");
        }
    }*/
    int pc=0;
    for(i=1; i<=m; ++i) {
        for(j=1; j<=n; ++j) {
            if(getValue(a, i, j) + getValue(b, i, j) != 0) {
                c.data[pc].e = getValue(a, i, j) + getValue(b, i, j);
                c.data[pc].i=i;
                c.data[pc].j=j;
                pc++;
                c.tu++;
            }
        }
    }
    // Out c
    for(i=0; i<c.tu; ++i) {
        if(i!=c.tu-1) printf("%d ", c.data[i].e);
        else printf("%d", c.data[i].e);
    }
    printf("\n");
    Triple next;
    pc=0;
    next=c.data[0];
    for(i=1; i<=m; ++i) {
        for(j=1; j<=n; ++j) {
            if(i==next.i && j==next.j) {
                if(j!=n) printf("1 ");
                else printf("1");
                pc++;
                if(pc<c.tu) next=c.data[pc];
            }else {
                if(j!=n) printf("0 ");
                else printf("0");
            }
        }
        if(i!=m) printf("\n");
    }
    return 0;
}

int getValue(TSMatrix a, int x, int y)
{
    int i;
    for(i=0; i<a.tu; ++i) {
        if(a.data[i].i==x && a.data[i].j==y)
            return a.data[i].e;
    }
    return 0;
}