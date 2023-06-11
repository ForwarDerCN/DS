#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct node {
    int addr;
    int size;
}node;
int a, s;
vector<node> space;

bool cmp(node a, node b)
{
    return a.addr < b.addr;
}

int main()
{
    char c;
    while((c = getchar()) != EOF) {
        if(c == '0') {   // Empty space
            scanf(" %d %d\n", &a, &s);
            space.push_back({a, s});
        }else if(c == '1') { // recycle space
            scanf(" %d %d\n", &a, &s);
            bool isMerge = false;
            for(int i = 0; i < space.size(); i++) {
                if(a+s == space[i].addr) {
                    space[i].addr = a;
                    space[i].size += s;
                    isMerge = true;
                    break;
                } else if(a == space[i].addr + space[i].size) {
                    space[i].size += s;
                    isMerge = true;
                    break;
                } else if(i != space.size() - 1 && space[i].addr + space[i].size >= a && a+s >= space[i+1].addr) {
                    space[i].size = space[i+1].addr - space[i].addr + space[i+1].size;
                    space.erase(space.begin()+i+1);
                    isMerge = true;
                    break;
                }
            }
            if(!isMerge) {
                space.push_back({a, s});
            }
        }
        // getchar(); // '\n'
    }
    sort(space.begin(), space.end(), cmp);
    for(int i=0; i<space.size(); i++) {
        printf("0 %d %d", space[i].addr, space[i].size);
        if(i != space.size()-1) {
            printf("\n");
        }
    }
    return 0;
}