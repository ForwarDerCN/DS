#include <iostream>
#define MAXN 10007
using namespace std;

int n;
int s[MAXN], fst[MAXN], lst[MAXN];

// s[i] is the successor of a graph
// fst[i] to lst[i] as indexes in s[i] is the successors of i
// get the 3 arrays
void init()
{
    cin>>n;
    int i=0;
    char c;
    scanf("%d", &s[i++]);
    while((c=getchar()) != '\n') {
        scanf("%d", &s[i++]);
    }
    for(i=0; i<=n; ++i) cin>>fst[i];
    for(i=0; i<=n; ++i) cin>>lst[i];
}

// Check if there is a loop
int dfs(int v, int w, bool flag)
{
    if(v==w && !flag) return 1;
    int p = fst[v];
    while(p < lst[v]) {
        if(dfs(s[p], w, false)) return 1;
        p++;
    }
    return 0;
}

int main()
{
    init();
    bool haveloop = false;
    for(int i=1; i<=n; ++i) {
        if(dfs(i, i, true)) {
            haveloop = true;
            break;
        }
    }
    if(haveloop) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}