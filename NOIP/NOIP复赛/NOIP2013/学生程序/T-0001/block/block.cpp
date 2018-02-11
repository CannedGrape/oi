#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n,l,r,h,maxx;
int sz[100002];
long long ans=0;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	maxx=0;
	for (int i=1;i<=n;i++)scanf("%d",&sz[i]),maxx=max(maxx,sz[i]);
	if (n<1000)
	{
		for (int i=1;i<=maxx;i++)
		{
			int j=1,k;
			while (j<=n)
			{
				k=j;
				while (sz[j]>=i)j++;
				if (j>k) ans++;
				j++;
			}
		}
	}else
	{
		sz[n+1]=0;
		l=1;r=2;h=sz[l];
		while ((l<r)&&(r<=n))
		{
			while ((sz[r]>=sz[l])&&(r<=n))
			{
				h=max(h,sz[r]);
				r++;
			}
			ans=ans+h-sz[r];
			l=r;
			h=sz[l];
			r++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
