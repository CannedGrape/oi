#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stack>
#define out(s) {k++;last[k]=s;}
using namespace std;
const int mod=10000;
char mid[3000001],last[3000001];
bool bigger(char a,char b)
{
    if(a=='+'&&b=='*') return false; else return true;
}
void step1(char* mid,char* last)
{
    stack <char> ops;
    int ml=strlen(mid),k=-1;
    for(int i=0;i<=ml-1;i++)
    {
        if(isdigit(mid[i])) {out(mid[i]); if(mid[i+1]=='*'||mid[i+1]=='+'||i==ml-1) out(' ');}
        else {while(!ops.empty()&&bigger(ops.top(),mid[i])) {out(ops.top()); out(' '); ops.pop();} ops.push(mid[i]);}
    }
    while(!ops.empty()) {out(ops.top()); out(' '); ops.pop();}
}
int step2(char* last)
{
    stack <int> numbers;
    int result=0,sl=strlen(last);
    bool sz=false;
    for(int i=0;i<=sl-1;i++)
    {
        if(isdigit(last[i])) {sz=true; result=result*10+last[i]-'0'; result%=mod;}
        if(last[i]==' ') {if(sz) numbers.push(result); result=0; sz=false;}
        if(last[i]=='+') {int a=numbers.top(); numbers.pop(); int b=numbers.top(); numbers.pop(); numbers.push((b+a)%mod);}
        if(last[i]=='*') {int a=numbers.top(); numbers.pop(); int b=numbers.top(); numbers.pop(); numbers.push((b*a)%mod);}
    }
    return numbers.top()%10000;
}
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    scanf("%s",mid);
    step1(mid,last);
    printf("%d",step2(last));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
