#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define INF (2139062143)
#define For(i,n) for(int i=1;i<=n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define Rep(i,n) for(int i=0;i<n;i++)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define For2k(i,k,n) for(int i=k;i<=n;i++)
#define For2kD(i,k,n) for(int i=n;i>=k;i--)
#define MAXN (1000000+10)
#define MAXK (1000000000+10)
typedef long long ll;
ll n,m,x,k;
ll pow2(ll a,ll b)
{
   if (b==1) return a;
   if (b==0) return 1;
   ll p=pow2(a,b/2)%n;
   p=(p*p)%n;
   if (b&1)
   {
       p=(p*a)%n;
   }
   return p;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
    ll t=pow2(10,k);
    t=(t*m)%n;
    t=(t+x)%n;
    printf("%lld\n",t);
//  while(1);
    return 0;
}
