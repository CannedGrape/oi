#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

long long data[1000000];
long long value[1000000];
long long score[1000000];

int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,p;
    scanf("%d%d",&n,&p);
    for(int i=0;i^n;i++) {
        int t;
        scanf("%d",&t);
        data[i]=t;
    }
    value[0]=data[0];
    for(int i=1;i^n;i++) {
        value[i]=max(max(value[i-1],data[i]),value[i-1]+data[i]);
    }
    score[0]=value[0];
    score[1]=score[0]+value[0];
    for(int i=2;i^n;i++) {
        score[i]=max(score[i-1]+value[i-1],score[i-1]);
    }
    printf("%d\n",score[n-1]%p);
}
