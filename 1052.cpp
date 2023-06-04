#include <iostream>
#define MAXV 10007
using namespace std;

int n;
char t[MAXV]; // Binary tree
int lc[MAXV], rc[MAXV]; // Left child and right child of each node

// Output tree t in postorder
void postorder(int root)
{
    //cout<<root<<" ";
    if(rc[root]) 
        postorder(rc[root]);
    if(lc[root]) 
        postorder(lc[root]);
    cout<<t[root];
}

int main()
{
    scanf("%d\n", &n);
    char c;
    c = getchar();
    int i = 0;
    while(i<n) {
        if(c=='+' || c=='-' || c=='*' || c=='/') {
            t[i] = c;
            getchar();  // sapce
            lc[i] = getchar()-'0';
            getchar();  // sapce
            rc[i] = getchar()-'0';
            getchar();  // \n
            c = getchar();
        } else {
            t[i] = c;
            getchar();  // \n
            c = getchar();
        }
        i++;
    }
    postorder(0);
    return 0;
}