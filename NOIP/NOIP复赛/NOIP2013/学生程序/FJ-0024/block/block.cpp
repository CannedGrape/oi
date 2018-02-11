#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,h[100010];
int f[100010][18],w[100010][18];
long long ans;
void work(int l,int r,int cnt)
{
     if(l>r)  return;
     if(l==r)  {ans+=h[l]-cnt;return;}
     int ww,k=log(r-l+1)/log(2.00);
     if(f[l][k]<=f[r-(1<<k)+1][k])  ww=w[l][k];
     else  ww=w[r-(1<<k)+1][k];
     ans+=h[ww]-cnt;
     work(l,ww-1,cnt+(h[ww]-cnt));work(ww+1,r,cnt+(h[ww]-cnt));
}
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {scanf("%d",&h[i]);f[i][0]=h[i];w[i][0]=i;}
    for(j=1;j<=17;j++)
    {
        k=(1<<j);
        for(i=1;i<=n-k+1;i++)
        {
            if(f[i][j-1]<=f[i+(1<<(j-1))][j-1])
            {
               f[i][j]=f[i][j-1];w[i][j]=w[i][j-1];
            }
            else
            {
                f[i][j]=f[i+(1<<(j-1))][j-1];w[i][j]=w[i+(1<<(j-1))][j-1];
            }
        }
    }
    work(1,n,0);
    cout<<ans<<endl;
   // system("pause");
    return 0;
}
