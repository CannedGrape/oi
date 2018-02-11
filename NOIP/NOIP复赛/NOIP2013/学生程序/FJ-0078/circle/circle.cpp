#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
#define ll long long
ll n,m,k,x;
ll mod;
inline ll gcd(ll x,ll y)
{
    register ll tmp;
    while(y){
             tmp=x%y;
             x=y;
             y=tmp;
    }
    return x;
}
inline ll fastpow(ll a,ll x)
{
    register ll res=1;
    while(x){
             if(x&1)
               res=(res*a)%mod;
             x>>=1;
             a=(a*a)%mod;
    }
    return res;
}
inline void init()
{
      scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
}
inline void solve()
{
       register ll i,r,ans;
       mod=n/gcd(n,m);
       r=fastpow(10,k);
       ans=((r%n)*(m%n)+(x%n))%n;
       printf("%lld\n",ans);
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    init();
    solve();
    fclose(stdout);
    fclose(stdin);
    //system("pause");
    return 0;
}
//10 3 4 5 2147483647
