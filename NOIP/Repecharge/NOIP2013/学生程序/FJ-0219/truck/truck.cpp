#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

using namespace std;

int map[10005][10005];
int n,m,q;

int main()
{
	int i,j,k,a,b,c;
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			map[i][j]=0;
		}
	}
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		map[a][b]=map[b][a]=c;
	}
	for (k=1;k<=n;k++)
	{
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				if (i!=j) map[i][j]=MAX(map[i][j],MIN(map[i][k],map[k][j]));
			}
		}
	}
	scanf("%d",&q);
	for (i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",map[a][b]);
	}
	return 0;
}
