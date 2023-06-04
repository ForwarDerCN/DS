#include <iostream>
#define MAXN 10007
using namespace std;

int g[MAXN][MAXN];
int n, a, b;
string op;

void InsertVex(int v)
{
    for(int i=n-1; i>=v; --i) {
        for(int j=0; j<n; ++j)
            g[i+1][j] = g[i][j];
    }
    int j=n-1;
    n++;
    while(j>=v) {
        for(int i=0; i<n; ++i)
            g[i][j+1] = g[i][j];
        j--;
    }
    for(int i=0; i<n; ++i) {
        g[i][v] = 0;
        g[v][i] = 0;
    }
}

void InsertArc(int v, int w)
{
    g[v][w] = 1;
    g[w][v] = 1;
}

void DeleteVex(int v)
{
    n--;
    for(int i=v; i<n; ++i) {
        for(int j=0; j<n+1; ++j)
            g[i][j] = g[i+1][j];
    }
    for(int j=v; j<n; ++j) {
        for(int i=0; i<n+1; ++i)
            g[i][j] = g[i][j+1];
    }
}

void DeleteArc(int v, int w)
{
    g[v][w] = 0;
    g[w][v] = 0;
}

// print g in matirx form
void printg()
{
    for(int i=0; i<n; ++i) {
        // Disable space after the last element
        for(int j=0; j<n; ++j) {
            cout<<g[i][j];
            if(j<n-1) cout<<" ";
        }
        // Disable the new line after the last line
        if(i<n-1) cout<<endl;
    }
}

int main()
{
    cin>>n;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j)
            cin>>g[i][j];
    }
    while(cin>>op) {
        if(op == "IV") {
            cin>>a;
            InsertVex(a);
        } else if(op == "IA") {
            cin>>a>>b;
            InsertArc(a, b);
        } else if(op == "DV") {
            cin>>a;
            DeleteVex(a);
        } else if(op == "DA") {
            cin>>a>>b;
            DeleteArc(a, b);
        }
    }
    printg();
    return 0;
}