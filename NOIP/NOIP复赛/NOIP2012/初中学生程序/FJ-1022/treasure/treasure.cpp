#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,ans;
int map[10001][101];
int fl[10001][101],st;
int main()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    cin>>n>>m;
    ans=0;
    int i,j,k;
    for(i=1;i<=n;i++)
      for(j=0;j<m;j++)
       cin>>fl[i][j]>>map[i][j];
    cin>>st;
    for(i=1;i<=n;i++)
    {
    ans=(ans+map[i][st])%20123;
    k=map[i][st];
    for(j=1;j<=k;j++)
      {
      while(fl[i][st]==0) {st++; if (st==m) st=0;}
      st++;
      if (st==m) st=0;
      }
    st--;
    if (st==-1) st=m-1;
    }
    cout<<ans%20123;
    fclose(stdin);
    fclose(stdout);
   // system("pause");
    return 0;
}
