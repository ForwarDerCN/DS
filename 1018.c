#include <stdio.h>
#include <string.h>
#define MAXO 7
#define MAXD 100005

char op[MAXO]={'+', '-', '*', '/', '(', ')', '#'};
/*char prior[MAXO][MAXO] = 
    {'>','>','<','<','<','>','>',
    '>','>','<','<','<','>','>',
    '>','>','>','>','<','>','>',
    '>','>','>','>','<','>','>', // '>' come first, though the same level
    '<','<','<','<','<','=',' ',
    '>','>','>','>',' ','>','>', 
    '<','<','<','<','<',' ','='
    };*/
int stop[MAXD], stout[MAXD]; // in stack, only ops
int tpop, tpout;
char s[MAXD];
int getod(char c);
//int getod(char c);
int isop(char c);
//char getpr(int o1, int o2);

int main()
{
    int i=0;
    char c;
    while((c=getchar()) != '\n') {
        s[i++]=c;
    }
    //s[i]='#';
    //i++;
    s[i]='\0';
    stop[tpop++]='#';
    int len=strlen(s);
    for(i=0; i<len; ++i) {
        if(!isop(s[i])) {
            stout[tpout++]=s[i];
        }else {
            if(s[i]==')') {
                while(tpop>0 && stop[tpop]!='(') {
                    stout[tpout++]=stop[tpop]; // get the top to out
                    tpop--;
                }    
                tpop--; // out'('          
            }else {
                while(getod(s[i])<=getod(stop[tpop]) && tpop>0) {    // Out lower prior
                    //if(stop[tpop-1]!='(') 
                        stout[tpout++]=stop[tpop];
                    tpop--;
                }
                stop[tpop++]=s[i];
            }
        }
    }
    while(tpop>0) {
        stout[tpout++]=stop[tpop];
        tpop--;
    }
    for(i=0; i<tpout; ++i) printf("%c", stout[i]);
    printf("\n");
    return 0;
}

int getod(char c)
{
    if(c=='(') return 3;
    if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
}

/*int getod(char c)
{
    int i;
    for(i=0; i<MAXO; ++i) 
        if(op[i]==c)    return i;
}*/

int isop(char c)
{
    int i;
    for(i=0; i<MAXO; ++i) 
        if(op[i]==c)    return 1;
    return 0;
}
/*
char getpr(int o1, int o2)
{
    return prior[getod(o1)][getod(o2)];
}*/
