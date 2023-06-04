#include <stdio.h>
#include <string.h>
#define MAXL 100007
#define BASE 26
#define MOD 100007

char s[MAXL];
int ls;
int code[MAXL]; // str-code from index
int hash[MAXL];
int isl(int len);

int main()
{
    scanf("%s", s);
    ls=strlen(s);
    // binary search len
    int lb=0, ub=strlen(s);
    int mid=(lb+ub)/2;
    int pos;
    int i;

    while(lb<=ub) {
        mid=(lb+ub)/2;
        for(i=0; i<MAXL; ++i) {
            code[i]=0;
            hash[i]=0;
        }
        if((pos=isl(mid)) != -1) {
            lb=mid+1;
        } else {
            ub=mid-1;
        }
        printf("Current Pos: %d ; Mid: %d\n", pos, mid);
    }
    /*for(i=strlen(s)-1; i>=0; --i) {
        if(pos=isl(i) != -1) {
            lb=i;
            //break;
        }        
    }*/
    for(i=pos; i<pos+mid; ++i) {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}

int isl(int len)
{
    int i, j , lcode=0, base=1;
    for(i=len-1; i>=0; i--) {
        lcode=(lcode + (s[i]-'a')*base) % MOD;
        if(i>0) base=(base*BASE) % MOD;
    }
    code[0]=lcode;
    hash[lcode]++;
    for(i=1; i<ls-len; ++i) {
        lcode=0;
        lcode=((code[i-1]-(s[i-1]-'a')*base)*BASE+(s[i+len-1]-'a')) % MOD;
        hash[lcode]++;
        if(hash[lcode]>=2)  {
            for(j=0; j<i; ++j) {
                if(code[j]==lcode) return j;
            }
        }
        code[i]=lcode;
    }
    return -1;
}