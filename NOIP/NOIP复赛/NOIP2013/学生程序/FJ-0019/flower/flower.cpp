#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define MAXN 100010
using namespace std;
int n,a[MAXN],que[MAXN],head,tail,ans;
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for (i=1;i<=n;++i)
		scanf("%d",&a[i]);
	que[tail=1]=a[1];
	que[head=0]=-1;
	bool flag=1;
	for (i=2;i<=n;++i)
	{
		if (flag)
		{
			if (a[i]<que[tail])	que[++tail]=a[i],flag^=1;
			else
				que[tail]=a[i];
		}
		else
		{
			if (a[i]>que[tail]) que[++tail]=a[i],flag^=1;
			else
				que[tail]=a[i];
		}
	}
	ans=tail;
	que[tail=1]=a[1];
	que[head=0]=1000010;
	flag=0;
	for (i=2;i<=n;++i)
	{
		if (flag)
		{
			if (a[i]<que[tail])	que[++tail]=a[i],flag^=1;
			else
				que[tail]=a[i];
		}
		else
		{
			if (a[i]>que[tail]) que[++tail]=a[i],flag^=1;
			else
				que[tail]=a[i];
		}
	}
	ans=max(ans,tail);
	printf("%d",ans);
	//system("pause");
	return 0;
}
