#include <iostream>
#include <string>
using namespace std;

int main()
{
    int m, n;
    string str, sub;
    cin>>m>>n;
    cin>>str;
    cin>>sub;
    if(str.find(sub)>=0 && str.find(sub)<=m) {
        cout<<str.find(sub)<<endl;
    }else {
        cout<<-1<<endl;
    }
    
    return 0;
}