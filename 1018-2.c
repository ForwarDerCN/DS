#include <stdio.h>
#include <string.h>
#define MAXL 100005
#define MAXO 7

typedef struct node {
    char s[MAXL];
    int top;
} Stack;

char op[MAXO]={'+', '-', '*', '/', '(', ')', '#'};

int weight(char ch, int flag) // flag -- 1-in stack ; 0-in string
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '(' && flag == 1)   // ( itself in stack -- lowest
        return 0;
    if (ch == '(' && flag == 0)    // highest with (   if it is in string
        return 3;
}

int isop(char c)
{
    int i;
    for(i=0; i<MAXO; ++i) 
        if(op[i]==c)    return 1;
    return 0;
}

void transform(char str[])
{
    Stack a;
    a.top = -1;
    int i, f = 0, m = strlen(str);
    for (i = 0; i < m; i++) {
        if (!isop(str[i])) {    // not op codes -- out istantly
            printf("%c", str[i]);
        }
        else {   // opcodes ok 
            if (a.top == -1) {
                a.s[++a.top] = str[i];
                continue;
            }
            if (str[i] == ')') {   // 1 -- meet )
                while (a.top != -1 && a.s[a.top] != '(')      // out Until (
                    printf("%c", a.s[a.top--]);
                --a.top; // out )
                continue;
            }
            if (weight(str[i], 0) > weight(a.s[a.top], 1)) {   // 2 -- higher now -- just continue
                a.s[++a.top] = str[i];
                continue;
            }
            // 3 -- lower now -- can out previous op codes
            while (a.top != -1 && weight(str[i], 0) <= weight(a.s[a.top], 1)) {                                                             
                printf("%c", a.s[a.top]);                                    
                --a.top;                                                     
                f = 1;    // record if we need push the current op code in(in this while loop we can't)                                                    
            }
            if (f == 1) {
                a.s[++a.top] = str[i];
                f = 0;
            }
        }
    }
    while (a.top != -1) {
        printf("%c", a.s[a.top--]);
    }
}

int main()
{
    char str[MAXL], c;
    int i=0;
    while((c=getchar()) != '\n') {
        str[i++]=c;
    }
    str[i]='\0';
    transform(str);
    printf("\n");
    return 0;
}
