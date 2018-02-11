#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int main()
{
  freopen("treasure.in","r",stdin);
  freopen("treasure.out","w",stdout);
  long long a[1000][101][2],ans=0,lj,y;
  int m,n,x;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=0;j<m;j++)
      cin>>a[i][j][0]>>a[i][j][1];
  cin>>x;
  for(int i=1;i<=n;i++)
    {
    lj=0;
    y=a[i][x][1];
    ans=ans+a[i][x][1];
    while(lj!=y)
    {
      if(x==m)
        x=0;
      if(a[i][x][0]==1)
        lj++;
      x++;
      
    }
    x--;
    ans=ans%20123;
   }
  cout<<ans;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
