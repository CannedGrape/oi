#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
int n;
int h[100005],f[100005][2];

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	int i,j,ans=0;
	for (i=1;i<=n;++i) scanf("%d",&h[i]);	
	for (i=1;i<=n;++i)
	{
		f[i][1]=1;
		f[i][0]=0;
		for (j=1;j<i;++j)
		{
			if (h[i]>h[j]) f[i][0]=max(f[i][0],f[j][1]+1);
			if (h[i]<h[j]) f[i][1]=max(f[i][1],f[j][0]+1);
		}
		ans=max(ans,max(f[i][0],f[i][1]));
	}
	for (i=1;i<=n;++i)
	{
		f[i][1]=1;
		f[i][0]=0;
		for (j=1;j<i;++j)
		{
			if (h[i]<h[j]) f[i][0]=max(f[i][0],f[j][1]+1);
			if (h[i]>h[j]) f[i][1]=max(f[i][1],f[j][0]+1);
		}
		ans=max(ans,max(f[i][0],f[i][1]));
	}
	printf("%d\n",ans);
	return 0;
}

