#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>
#define MAX(a,b) ((a)>(b))?(a):(b)

using namespace std;

int n;
int high[100005];
int ans[100005][2];
int maxn=0;

int main()
{
	int i,j;
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	if (n<=2) {printf("%d\n",n); return 0;}
	for (i=1;i<=n;i++) scanf("%d",&high[i]);
	ans[1][0]=1; ans[1][1]=1;
	for (i=2;i<=n;i++)
	{
		ans[i][0]=1; ans[i][1]=1;
		for (j=i-1;j>=1;j--)
		{
			if (high[i]<high[j]) ans[i][0]=MAX(ans[j][1]+1,ans[i][0]);
			if (high[i]>high[j]) ans[i][1]=MAX(ans[j][0]+1,ans[i][1]);
		}
		if (ans[i][0]>maxn) maxn=ans[i][0];
		if (ans[i][1]>maxn) maxn=ans[i][1];
	}
	printf("%d\n",maxn);
	return 0;
}
