#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
bool z[10001][10001];
int r[10001][10001],n,y2;
int bfs(int p,int z2)
{
  int i,ans=-1,bfsi;
  if(p==y2)
    return z2;
  for(i=1;i<=n;i++)
  {
    if(r[p][i]!=-1 && z[p][i]==false)
    {
      z[p][i]=z[i][p]=true;
      ans=max(ans,bfs(i,min(z2,r[i][p])));
      z[p][i]=z[i][p]=false;
    }
  }
  return ans;
}
int main()
{
  freopen("truck.in","r",stdin);
  freopen("truck.out","w",stdout);
  memset(r,-1,sizeof(r));
  int m;
  scanf("%d%d",&n,&m);
  int i,x2,z2;
  for(i=0;i<m;i++)
  {
    scanf("%d%d%d",&x2,&y2,&z2);
    if(r[x2][y2]<z2)
    {
      r[x2][y2]=z2;
      r[y2][x2]=z2;
    }
  }
  int q;
  scanf("%d",&q);
  memset(z,false,sizeof(z));
  for(i=1;i<=q;i++)
  {
    scanf("%d%d",&x2,&y2);
    printf("%d\n",bfs(x2,2147483647));
  }
//  system("pause");
  fclose(stdin);
  fclose(stdout);
  return 0;
}
