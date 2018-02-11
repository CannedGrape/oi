#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=100100;

int n,Tnum,ans;
int A[maxn],f[maxn],g[maxn],num[maxn],C1[maxn],C2[maxn];

void init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++) scanf("%d",&A[i]),num[i]=A[i];
     sort(num+1,num+n+1); Tnum=unique(num+1,num+n+1)-num-1;
     for(int i=1;i<=n;i++) A[i]=lower_bound(num+1,num+Tnum+1,A[i])-num;
}

void modify1(int k,int x)
{
     for(;k;k-=k&(-k)) C1[k]=max(C1[k],x);
}

void modify2(int k,int x)
{
     for(;k<=Tnum;k+=k&(-k)) C2[k]=max(C2[k],x);
}

int getmax1(int k)
{
    int res=0;
    for(;k<=Tnum;k+=k&(-k)) res=max(res,C1[k]);
    return res;
}

int getmax2(int k)
{
    int res=0;
    for(;k;k-=k&(-k)) res=max(res,C2[k]);
    return res;
}

void work()
{
     for(int i=1;i<=n;i++) C1[i]=C2[i]=0;
     for(int i=1;i<=n;i++)
     {
         f[i]=getmax2(A[i]-1)+1; g[i]=getmax1(A[i]+1)+1;
         modify1(A[i],f[i]); modify2(A[i],g[i]);
     }
     ans=0;
     for(int i=1;i<=n;i++) ans=max(ans,max(f[i],g[i]));
     printf("%d\n",ans);
}

int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    init();
    work();
    return 0;
}

