#include <iostream>
#include <cstdlib>
#define FootLoc(p)  p + p->size - 1
using namespace std;

typedef struct WORD {
    union {
        WORD *llink;
        WORD *uplink;
    };
    int tag;
    int size;
    WORD *rlink;
}WORD, head, foot, *Space;
Space s;

void CreateSpace(int addr, int size)
{
    WORD *p;
    p = (WORD *)malloc(sizeof(WORD));
    if(s->rlink == NULL) {
        s->rlink = p;
        p->llink = s;
        p->rlink = FootLoc(p);
        p->size = size;
        
    }

}

void FreeSpace(int addr, int size)
{

}

// Get free spaces and recycle spaces
void init()
{
    char tag;
    int addr, size;
    while((tag = getchar()) != EOF) {
        if(tag == '0') {
            scanf("%d %d\n", &addr, &size);
            CreateSpace(addr, size);
        } else if(tag == '1') {
            scanf("%d %d\n", &addr, &size);
            FreeSpace(addr, size);
        } else if(tag == '\n') {
            continue;
        }
    }
}

int main()
{

}