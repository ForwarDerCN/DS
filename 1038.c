#include <stdio.h>
#include <stdlib.h>
#define MAXN 10007
#define MAXBT 107

typedef struct tnode {
    int data;
    int fc, ns; // first child's num and next sibling's name
}tnode;
tnode tt[MAXN];
int n, tot;
int vis[MAXN];
int isson[MAXN];

typedef enum {Null, Link, Thread} pTag;
typedef struct bnode {
    int data;
    struct bnode *lc, *rc;
    pTag lTag, rTag;
}bnode;
bnode *bts[MAXBT];

int pbt = 0;
int lf[MAXN], rf[MAXN], ordf[MAXN];
int lm[MAXN], rm[MAXN], ordm[MAXN];
int ll[MAXN], rl[MAXN], ordl[MAXN];
int pf, pm, pl;

void gettree();
void trigerTobt();
bnode *treeTobt(int x);
bnode *forestTobt(bnode *t[]);
void fstTravel(bnode *t);
void midTravel(bnode *t);
void lstTravel(bnode *t);
void getord();
void printl();

int main()
{
    bnode *fbt;
    gettree();
    trigerTobt();
    fbt=forestTobt(bts);
    rf[0]=lf[0]=rm[0]=lm[0]=rl[0]=ll[0]=fbt->data;
    fstTravel(fbt);
    midTravel(fbt);
    lstTravel(fbt);
    getord();
    printl();
    return 0;
}

void gettree()
{
    scanf("%d\n", &n);
    int i;
    for(i=1; i<=n; ++i) {
        scanf("%d %d %d\n", &tt[i].data, &tt[i].fc, &tt[i].ns);
        isson[tt[i].fc]=1; isson[tt[i].ns]=1;
    }
}

void trigerTobt()
{
    bnode *t;
    int i;
    for(i=1; i<=n; ++i) {
        if(!isson[i]) tot++;
    }
    while(tot>0) {
        //free(t);
        for(i=1; i<=n; ++i) {
            if(!vis[i] /*&& tt[i].fc!=0 && tt[i].ns==0 */ && !isson[i]) {
                t=(bnode *)malloc(sizeof(bnode));
                tot--;
                t->data=tt[i].data;
                t->lTag=Link;
                t->rTag=Thread;
                t->rc=NULL;
                vis[i]=1;
                t->lc=treeTobt(tt[i].fc);
                //printf("PBT=%d,  Trigerred: %d \n", pbt, i);
                bts[pbt++]=t;
                break;
            }
        }
    }
}

bnode *treeTobt(int x)
{
    int pt;
    bnode *t;
    t=(bnode *)malloc(sizeof(bnode));
    if(!tt[x].data) return NULL;
    else {
        // root
        t->data=tt[x].data;
        // left sub bt
        if(tt[x].fc) {
            t->lTag=Link;
            t->lc=treeTobt(tt[x].fc);
        }else {
            t->lTag=Thread;
            t->lc=NULL;
        }
        // right
        if(tt[x].ns) {
            t->rTag=Link;
            t->rc=treeTobt(tt[x].ns);
        }else {
            t->rTag=Thread;
            t->rc=NULL;
        }
    }
    return t;
}

bnode *forestTobt(bnode *t[])
{
    int i;
    for(i=0; i<pbt-1; ++i) {
        // printf("ROOT %d, Value %d\n", i, t[i]->data);
        t[i]->rTag=Link;
        t[i]->rc=t[i+1];
    }
    return t[0];
}

void fstTravel(bnode *t)
{
    if(t->data) {
        // make the ROOT
        //printf("FST at %d\n", t->data);
        ordf[++pf]=t->data;
        if(t->lTag == Link && t->lc !=NULL) {
            lf[t->data]=t->lc->data;
        }
        if(t->rTag == Link && t->rc != NULL) {
            rf[t->data]=t->rc->data;
        }
        // To left Subtree
        if(t->lTag == Link && t->lc != NULL) fstTravel(t->lc);
        // To right
        if(t->rTag == Link && t->rc != NULL) fstTravel(t->rc);
    }
}

void midTravel(bnode *t)
{
    if(t->data) {
        // To left Subtree
        if(t->lTag == Link && t->lc != NULL) midTravel(t->lc);
        // make the ROOT
        //printf("MID at %d\n", t->data);
        ordm[++pm]=t->data;
        if(t->lTag == Link && t->lc != NULL) {
            lm[t->data]=t->lc->data;
        }
        if(t->rTag == Link && t->rc != NULL) {
            rm[t->data]=t->rc->data;
        }
        // To right
        if(t->rTag == Link && t->rc != NULL) midTravel(t->rc);
    }
}

void lstTravel(bnode *t)
{
    if(t->data) {
        // To left Subtree
        if(t->lTag == Link && t->lc != NULL) lstTravel(t->lc);
        // To right
        if(t->rTag == Link && t->rc != NULL) lstTravel(t->rc);
        // make the ROOT
        ordl[++pl]=t->data;
        if(t->rTag == Link && t->rc != NULL) {
            rl[t->data]=t->rc->data;
        }
        if(t->lTag == Link && t->lc != NULL) {
            ll[t->data]=t->lc->data;
        }
    }
}

void getord()
{
    int i, j;
    // get lf
    for(i=1; i<=n; ++i) {
        if(!lf[i])
            for(j=2; j<=n; ++j) {  // fst travel -- visit i at pos j
                if(ordf[j]==i) {
                    lf[i]=ordf[j-1];
                }
            }
    }
    // get lm 
    for(i=1; i<=n; ++i) {
        if(!lm[i])
            for(j=2; j<=n; ++j) {  // mid travel -- visit i at pos j
                if(ordm[j]==i) {
                    lm[i]=ordm[j-1];
                }
            }
    }
    // get rm
    for(i=1; i<=n; ++i) {
        if(!rm[i])
            for(j=1; j<=n-1; ++j) {  // mid travel -- visit i at pos j
                if(ordm[j]==i) {
                    rm[i]=ordm[j+1];
                }
            }
    }
    // get rl
    for(i=1; i<=n; ++i) {
        if(!rl[i])
            for(j=1; j<=n-1; ++j) {  // lst travel -- visit i at pos j
                if(ordl[j]==i) {
                    rl[i]=ordl[j+1];
                }
            }
    }
}

void printl()
{
    int i;
    for(i=0; i<=n; ++i) {printf("%d", lf[i]); if(i!=n) printf(" "); }
    printf("\n");
    for(i=0; i<=n; ++i) {printf("%d", rf[i]); if(i!=n) printf(" "); }
    printf("\n");
    for(i=0; i<=n; ++i) {printf("%d", lm[i]); if(i!=n) printf(" "); }
    printf("\n");
    for(i=0; i<=n; ++i) {printf("%d", rm[i]); if(i!=n) printf(" "); }
    printf("\n");
    for(i=0; i<=n; ++i) {printf("%d", ll[i]); if(i!=n) printf(" "); }
    printf("\n");
    for(i=0; i<=n; ++i) {printf("%d", rl[i]); if(i!=n) printf(" "); }
}