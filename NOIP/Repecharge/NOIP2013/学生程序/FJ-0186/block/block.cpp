#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=100100;

int n,ans,A[maxn];

void init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++) scanf("%d",&A[i]);
     A[0]=0; A[++n]=0;
}

void work()
{
     ans=0;
     for(int i=1;i<=n;i++) if(A[i]>A[i-1]) ans+=A[i]-A[i-1];
     printf("%d\n",ans);
}

int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    init();
    work();
    return 0;
}

