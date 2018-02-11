#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
int n,a[100003],cut[400010],L,R,ans=0,temp=1,tp;
void init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)  scanf("%d",&a[i]);
}
struct dd
{
	int t,pla;
}tree[400010];
dd minn(dd ab,dd cd)
{
	if (ab.t<cd.t)  return ab;
	return cd;
}
dd dfstree(int l,int r,int root)
{
	if (l>=L&&r<=R)  return tree[root];
	else if (r<L||l>R)  {dd fg;fg.t=2312231;return fg;}
	else
	{
		int x=(l+r)/2;
		dd tt=minn(dfstree(l,x,2*root),dfstree(x+1,r,2*root+1));
		return tt;
	}
}
dd cshtree(int l,int r,int root)
{
	if (l!=r)
	{
		int x=(l+r)/2;
		tree[root]=minn(cshtree(l,x,2*root),cshtree(x+1,r,2*root+1));
	}
	return tree[root];
}
void csh()
{
	while (temp<n)  temp*=2;
	for (int i=1;i<=temp+213;i++)  tree[i].t=2312231;
	tp=temp;
	for (int i=1;i<=n;i++,temp++)  {tree[temp].t=a[i];tree[temp].pla=i;}
	cshtree(1,tp,1);
}
void work()
{
	csh();
	//for (int i=1;i<temp;i++)  printf("%d %d %d\n",i,tree[i].t,tree[i].pla);
    L=1,R=n+1;
    int ty=1,tu,ti=n,to;
    while (ty<ti)
    {
		to=2139019;
		while (a[ty]==0)  ty++;
		tu=ty;
		while (a[tu]!=0&&tu<n)
		{
			tu++;
			if (a[tu]<to)  to=a[tu];
		}
		ans+=to;
		for (int i=ty;i<=tu;i++)
		{
			a[i]-=to;
		}
	}
	printf("%d",ans);
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	init();
	work();
	return 0;
}
