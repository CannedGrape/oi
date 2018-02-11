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
#define MAXHi (1000000+10)
typedef long long ll;
int n,a[MAXN],f[MAXN][2],T[MAXN][2];
bool cmp(int a,int b,int j){if (j==0) return a<b;else return a>b;}
int check(int h,int j) //return max f
{
     int l=1,r=n,ans=0;
     while (l<=r)
     {
        int m=(l+r)>>1;
        if (cmp(T[m][j^1],h,j)) ans=m,l=m+1;
        else r=m-1;
     }
     return ans;
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&n);
    For(i,n) scanf("%d",&a[i]);
    For(i,n) f[i][0]=f[i][1]=1;
    For(i,n) T[i][0]=-1,T[i][1]=MAXHi+1;
    
    int ans=0;
    For(i,n)
       Rep(j,2)
       {
          f[i][j]=max(f[i][j],check(a[i],j)+1);
          if (j==0) 
          {
              T[f[i][j]][j]=max(T[f[i][j]][j],a[i]);
              for(int k=f[i][j]-1;k>=1;k--)
                  if (T[k][0]<T[k+1][0]) T[k][0]=T[k+1][0];else break;
          }
          else
          {
              T[f[i][j]][j]=min(T[f[i][j]][j],a[i]);
              for(int k=f[i][j]-1;k>=1;k--)
                  if (T[k][1]>T[k+1][1]) T[k][1]=T[k+1][1];else break;
          }
          ans=max(ans,f[i][j]);
       }
    /*
    For(i,n) cout<<f[i][0]<<' ';cout<<endl;
    For(i,n) cout<<f[i][1]<<' ';cout<<endl;
    cout<<endl;
    For(i,n) cout<<T[i][0]<<' ';cout<<endl;
    For(i,n) cout<<T[i][1]<<' ';cout<<endl;
    */
    
    
    
    printf("%d\n",ans);
//  while(1);
    return 0;
}
