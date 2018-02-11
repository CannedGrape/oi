#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<cstdlib>
using namespace std;
int n,a[3][100001],ans=0;
bool b;
int allmin(int x,int y,int z,int w)
{
    if(((x-y)*(x-y)+(z-w)*(z-w))>((x-w)*(x-w)+(y-z)*(y-z)))
    b=true;
}
int main()
{
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  int i,j,k;
  scanf("%d",&n);
  for(j=1;j<=2;j++)
  for(i=1;i<=n;i++)
  scanf("%d",&a[j][i]);  

  for(i=1;i<=n;i++)   
  for(k=1;k<=2;k++)
  for(j=1;j<n;j++)
{
          b=false;        
  allmin(a[1][j],a[2][j],a[1][j+1],a[2][j+1]);
  if(b)
  {
       ans++;
  swap(a[k][j],a[k][j+1]);
  }
  }
  ans=ans%99999997;
  printf("%d",ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
