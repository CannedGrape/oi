#include <iostream>
#include <cstdio>

using namespace std;

const int maxn=100010;
int a[maxn];
int n;

void init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)  scanf("%d",&a[i]);
}

void solve()
{
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>a[i-1]) ans+=a[i]-a[i-1];
		if (a[i]>a[i+1]) ans+=a[i]-a[i+1];
	}
	int maxh=0;
	for (int i=1;i<=n;i++) maxh=maxh<a[i]?a[i]:maxh;
	printf("%d\n",(ans-2*maxh)/2+maxh);
}

int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	init();
	solve();
	return 0;
}
