#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define N 2010
#define M 9000000

int n,m,g[N][N],x,y,z,s=0;

int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	memset(g,0,sizeof(g));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
		scanf("%d%d%d",&x,&y,&z),
		g[x][y]=g[y][x]=z;
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=n;++j)
		{
			for (int k=1;k<=n;++k)
			{
				if (g[j][i]&&g[i][k]) g[j][k]=max(min(g[j][i],g[i][k]),g[j][k]);
				++s;
				if (s>M) break;
			}
			if (s>M) break;
		}
		if (s>M) break;
	}
	for (scanf("%d",&n);n--;)
		scanf("%d%d",&x,&y),
		printf("%d\n",g[x][y]?g[x][y]:-1);
	return 0;
}

