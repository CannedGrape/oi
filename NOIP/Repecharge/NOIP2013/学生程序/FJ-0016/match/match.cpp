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
#define F (99999997)
#define MAXN (500000+10)
typedef long long ll;
int n;
struct node
{
    ll x;int i;
    friend bool operator<(node a,node b){return a.x<b.x;} 
}a[MAXN],b[MAXN];
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&n);
    For(i,n) scanf("%lld",&a[i].x),a[i].i=i;
    For(i,n) scanf("%lld",&b[i].x),b[i].i=i;
    
//  For(i,n) cout<<a[i].x<<':'<<a[i].i<<' ';cout<<endl;    
//  For(i,n) cout<<b[i].x<<':'<<b[i].i<<' ';cout<<endl;    
    
    sort(a+1,a+1+n);sort(b+1,b+1+n);
    
//  For(i,n) cout<<a[i].x<<':'<<a[i].i<<' ';cout<<endl;    
//  For(i,n) cout<<b[i].x<<':'<<b[i].i<<' ';cout<<endl;    
    
    ll ans=0;
    For(i,n) 
    {
       if (a[i].i>b[i].i) ans=(ans+a[i].i-b[i].i);
       else ans=(ans-a[i].i+b[i].i);
    }
    printf("%lld\n",(ans/2)%F);
    
//  while(1);
    return 0;
}
