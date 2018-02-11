#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>

using namespace std;

const int MAXN=100100;

struct node
{
	int x,y,z;
}f[MAXN];

int h[MAXN];
int n,ans,tmp;

int getmax(int a,int b,int c)
{
	int tmp=a;
	if (b>tmp) tmp=b;
	if (c>tmp) tmp=c;
	return tmp;
}

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	
	int i,j,k;
	
	scanf("%d",&n);
	for (i=1; i<=n; i++)
	  scanf("%d",&h[i]);
	
	// 第一种情况：偶数较大
	 
	f[1].x=0;  // x为作为偶数边
	f[1].y=1;  // y为作为奇数边
	f[1].z=0;  // z为不选 
	
	for (i=2; i<=n; i++)
	{
		int maxx=0,maxy=0;
	    for (k=1; k<i; k++)
	    {
			if ( h[i]>h[k] && f[k].y>maxx)
			  maxx=f[k].y;
			if ( h[i]<h[k] && f[k].x>maxy)
			  maxy=f[k].x;
		}
		if (maxx!=0) f[i].x=maxx+1;
		f[i].y=maxy+1;
		f[i].z=getmax(f[i-1].z,f[i-1].x,f[i-1].y);
	}
	
	//for (i=1; i<=n; i++)
	//  cout<<"i="<<i<<" f.x="<<f[i].x<<" f.y="<<f[i].y<<" f.z="<<f[i].z<<endl;
	
	ans=getmax(f[n].z,f[n].x,f[n].y);
	
	// 第二种情况： 偶数较小
	
	memset(f,0,sizeof(f));
	f[1].x=0;  // x为作为偶数边
	f[1].y=1;  // y为作为奇数边
	f[1].z=0;  // z为不选 
	
	for (i=2; i<=n; i++)
	{
		int maxx=0,maxy=0;
	    for (k=1; k<i; k++)
	    {
			if ( h[i]<h[k] && f[k].y>maxx)
			  maxx=f[k].y;
			if ( h[i]>h[k] && f[k].x>maxy)
			  maxy=f[k].x;
		}
		if (maxx!=0) f[i].x=maxx+1;
		f[i].y=maxy+1;
		f[i].z=getmax(f[i-1].z,f[i-1].x,f[i-1].y);
	}
	//for (i=1; i<=n; i++)
	//  cout<<"i="<<i<<" f.x="<<f[i].x<<" f.y="<<f[i].y<<" f.z="<<f[i].z<<endl;
	tmp=getmax(f[n].z,f[n].x,f[n].y);
	if (tmp>ans) ans=tmp;
	
	printf("%d\n",ans);
	
	return 0;
}
