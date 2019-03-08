#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MaxN=100001;

int n,h[MaxN],ans=0;
int t[8*MaxN];

void build(int x,int l,int r)
{
	if (l==r)
	{
		t[x]=l;
		return;
	}
	int mid=(l+r)/2;
	build(2*x,l,mid);
	build(2*x+1,mid+1,r);
	if (h[t[2*x]]<h[t[2*x+1]])
	{
		t[x]=t[2*x];
	}
	else
	{
		t[x]=t[2*x+1];
	}
	//cout<<x<<' '<<l<<' '<<r<<' '<<t[x]<<' '<<h[t[x]]<<endl;
}

int get(int x,int l,int r,int vl,int vr)
{
	if (l==vl && r==vr)
	{
		return t[x];
	}
	int mid=(l+r)/2;
	if (mid>=vr)
	{
		return get(2*x,l,mid,vl,vr);
	}
	if (mid<vl)
	{
		return get(2*x+1,mid+1,r,vl,vr);
	}
	int a=get(2*x,l,mid,vl,mid),b=get(2*x+1,mid+1,r,mid+1,vr);
	if (h[a]<h[b])
	{
		return a;
	}
	else
	{
		return b;
	}
}

int work(int l,int r,int v)
{
	/*if (l>r)
	{
		return 0;
	}*/
	int x=get(1,0,n-1,l,r),ans=h[x]-v;
	/*if (l==r)
	{
		return ans;
	}*/
	if (x-1>=l)
	{
		ans+=work(l,x-1,h[x]);
	}
	if (x+1<=r)
	{
		ans+=work(x+1,r,h[x]);
	}
	//cout<<l<<' '<<r<<' '<<x<<' '<<v<<' '<<ans<<endl;
	return ans;
}

int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&h[i]);
	}
	build(1,0,n-1);
	printf("%d\n",work(0,n-1,0));
	//system("pause");
	return 0;
}

