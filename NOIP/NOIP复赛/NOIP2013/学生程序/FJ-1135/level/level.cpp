#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int i,j,s,n,m,x,mx,a[1010];
int main()
{
  freopen("level.in","r",stdin);
  freopen("level.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(i=1;i<=m;i++)
  {
	scanf("%d",&x);
	scanf("%d",&s);
	for(j=2;j<x;j++)
	{
	  scanf("%d",&s);
	  a[s]=a[s]+1;
	}
	scanf("%d",&s);
  }
  for(i=1;i<=n;i++)if(a[i]>mx)mx=a[i];
  printf("%d\n",mx);
  return 0;
}
