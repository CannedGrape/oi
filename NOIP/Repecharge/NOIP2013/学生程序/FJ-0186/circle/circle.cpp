#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=1001000;

int n,m,K,X,tot,vis[maxn],V[maxn];

void init()
{
     scanf("%d %d %d %d",&n,&m,&K,&X);
}

LL MI(int a,int x,int p)
{
    LL Tas=1,b=a;
    for(;x;x>>=1,b=b*b%p) if(x&1) Tas=Tas*b%p;
    return int(Tas);
}

void work()
{
     tot=0;
     memset(vis,0,sizeof(vis));
     for(int i=(X+m)%n;vis[i]==0;)
     {
         vis[i]=1; V[++tot]=i;
         i+=m; if(i>=n) i-=n;
     }
     int p=MI(10,K,tot); if(!p) p=tot; 
     printf("%d\n",V[p]);
}

int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    init();
    work();
    return 0;
}

