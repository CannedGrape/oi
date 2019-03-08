#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

long long num[100005];
char op[100005];

int main() {
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    int index=0;
    long long t=0;
    char c=0;
    while((c=getchar())&&c!='\n'&&c!=EOF) {
        if(c>='0'&&c<='9') {
            t*=10;
            t+=c-'0';
        }
        else {
            num[index]=t;
            t=0;
            op[index]=c;
            index++;
        }
        
    }
    num[index]=t;
    for(int i=0;i^index;i++) {
        if(op[i]=='*') {
            long long t=(num[i]*num[i+1])%10000;
            op[i]='+';
            num[i]=0;
            num[i+1]=t;
        }
    }
    for(int i=0;i^index;i++) {
        num[i+1]+=num[i];
        num[i+1]%=10000;
    }
    int ans=num[index];
    printf("%d\n",ans);
}
