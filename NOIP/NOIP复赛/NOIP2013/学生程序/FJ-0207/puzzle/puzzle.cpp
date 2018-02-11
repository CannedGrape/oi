#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n,m,q,ans;
int a[105][105];
int s[1005][1005];
int workx(int x,int y,int z)
{	if (y==z)
	 return x;
	else
	 return z;
}
int worky(int x,int y,int z)
{	if (y==z)
	 return x;
	else
	 return z;
}
int gn(int x,int y)
{	return (x-1)*n+y;
}
void work(int wx,int wy,int gx,int gy,int rx,int ry,int k)
{	if (a[wx][wy]==0 || a[gx][gy]==0)
	 return;
	if (gx==rx && gy==ry)
	{ans=min(ans,k);
	 return;
	}
	//cout<<wx<<' '<<wy<<' '<<gx<<' '<<gy<<' '<<k<<endl;
	s[gn(wx,wy)][gn(gx,gy)]=1;
	if (wx>1 && !s[gn(wx-1,wy)][gn(workx(wx,wx-1,gx),worky(wy,wy,gy))])
	 work(wx-1,wy,workx(wx,wx-1,gx),worky(wy,wy,gy),rx,ry,k+1);
	if (wx<n && !s[gn(wx+1,wy)][gn(workx(wx,wx+1,gx),worky(wy,wy,gy))])
	 work(wx+1,wy,workx(wx,wx+1,gx),worky(wy,wy,gy),rx,ry,k+1);
	if (wy>1 && !s[gn(wx,wy-1)][gn(workx(wx,wx,gx),worky(wy,wy-1,gy))])
	 work(wx,wy-1,workx(wx,wx,gx),worky(wy,wy-1,gy),rx,ry,k+1);
	if (wy<m && !s[gn(wx,wy+1)][gn(workx(wx,wx,gx),worky(wy,wy+1,gy))])
	 work(wx,wy+1,workx(wx,wx,gx),worky(wy,wy+1,gy),rx,ry,k+1);
}
int main()
{	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	int i,j,k;
	int wx,wy,gx,gy,rx,ry;
	scanf ("%d %d %d",&n,&m,&q);
	for (i=1;i<=n;i++)
	 for (j=1;j<=m;j++)
	  scanf ("%d",&a[i][j]);
	for (k=1;k<=q;k++)
	{for (i=1;i<=950;i++)
	  for (j=1;j<=950;j++)
	   s[i][j]=0;
	 ans=2100000000;
     scanf ("%d %d %d %d %d %d",&wx,&wy,&gx,&gy,&rx,&ry);
     work(wx,wy,gx,gy,rx,ry,0);
     if (ans<2000000000)
      printf("%d\n",ans);
	 else
	  printf("-1\n");
	}
	return 0;
} 
