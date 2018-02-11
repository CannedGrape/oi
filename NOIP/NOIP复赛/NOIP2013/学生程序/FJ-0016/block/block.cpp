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
#include<set>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define Rep(i,n) for(int i=0;i<n;i++)
#define RepD(i,n) for(int i=n-1;i>=0;i--)
#define For2k(i,k,n) for(int i=k;i<=n;i++)
#define For2kD(i,k,n) for(int i=n;i>=k;i--)
#define INF (2139062143)
#define MAXN (100000+10)
#define MAXHi (10000+10)
typedef long long ll;
int n,a[MAXN];
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    scanf("%d",&n);
    For(i,n) scanf("%d",&a[i]);a[0]=a[n+1]=0;a[n+2]=1;
    ll ans=0;
    while (n)
    {
       n=unique(a+1,a+1+n)-(a+1);
       /*
       cout<<n<<endl;
       For(i,n) cout<<a[i]<<' ';cout<<endl;
       */
       
       if (n==1&&a[1]==0) break;
       
       a[0]=a[n+1]=0;a[n+2]=1;
              
       int l=0,r=0,maxi=0;
       bool up=1;
       while(l<=r&&r<=n+1)
       {
          r++;
          if (a[r-1]<=a[r]&&(up)) maxi=a[r];
          else if (a[r-1]<=a[r]&&(!up))
          {
               int lowh=max(a[l],a[r-1]);
               int delta=maxi-max(a[l],a[r-1]);
               ans+=delta;
               For2k(i,l,r-1) if (a[i]>=lowh) a[i]=lowh;
               l=r-1;maxi=a[r];    
          }
          else //a[r-1]>a[r]
          {
              if (up) 
              {
                 up=0;     
              }
          }         
       }
    }
    
    printf("%lld\n",ans);
//  while(1);
    return 0;
}
