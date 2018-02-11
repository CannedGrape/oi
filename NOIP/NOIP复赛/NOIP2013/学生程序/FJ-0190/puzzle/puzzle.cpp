#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int n,m,q,b[40][40],x,y,ans,X,Y,XX,YY,s,B[40][40],BX,BY,min,s2,p,Z;
bool v[40][40],z;

inline void copy()
{
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			B[i][j]=b[i][j];
}

inline void dfs(int xx,int yy)
{
	if ((xx==x)&&(yy==y)) {if (s<ans) ans=s,copy(),BX=xx,BY=yy; return;}
	if (s>=ans) return;
	if (b[xx][yy-1])
		b[xx][yy]=b[xx][yy-1],b[xx][yy-1]=-1,++s,
		dfs(xx,yy-1),
		--s,b[xx][yy-1]=b[xx][yy],b[xx][yy]=-1;
	if (b[xx][yy+1])
		b[xx][yy]=b[xx][yy+1],b[xx][yy+1]=-1,++s,
		dfs(xx,yy+1),
		--s,b[xx][yy+1]=b[xx][yy],b[xx][yy]=-1;
	if (b[xx-1][yy])
		b[xx][yy]=b[xx-1][yy],b[xx-1][yy]=-1,++s,
		dfs(xx-1,yy),
		--s,b[xx-1][yy]=b[xx][yy],b[xx][yy]=-1;
	if (b[xx+1][yy])
		b[xx][yy]=b[xx+1][yy],b[xx+1][yy]=-1,++s,
		dfs(xx+1,yy),
		--s,b[xx+1][yy]=b[xx][yy],b[xx][yy]=-1;	
}

inline void DFS(int xx,int yy)
{
	if (v[BX][BY])
	{
		if (!z) return;
		if (s<min)
		{
			if (s2<p) p=s2;
			min=s;
		}
		return;
	}
	if (s>=min) return;
	if ((!v[xx][yy-1])&&(B[xx][yy-1]))
	{
		v[xx][yy-1]=1,++s;
		Z=z;
		if (!z) ++s2;
		if (B[xx][yy-1]==2) z=1;
		DFS(xx,yy-1);
		--s,v[xx][yy-1]=0,z=0;
		if (!z) --s2;
	}
	if ((!v[xx][yy+1])&&(B[xx][yy+1]))
	{
		v[xx][yy+1]=1,++s;
		Z=z;
		if (!z) ++s2;
		if (B[xx][yy+1]==2) z=1;
		DFS(xx,yy+1);
		--s,v[xx][yy+1]=0,z=0;
		if (!z) --s2;
	}
	if ((!v[xx-1][yy])&&(B[xx-1][yy]))
	{
		v[xx-1][yy]=1,++s;
		Z=z;
		if (!z) ++s2;
		if (B[xx-1][yy]==2) z=1;
		DFS(xx-1,yy);
		--s,v[xx-1][yy]=0,z=0;
		if (!z) --s2;
	}
	if ((!v[xx+1][yy])&&(B[xx+1][yy]))
	{
		v[xx+1][yy]=1,++s;
		Z=z;
		if (!z) ++s2;
		if (B[xx+1][yy]==2) z=1;
		DFS(xx+1,yy);
		--s,v[xx+1][yy]=0,z=0;
		if (!z) --s2;
	}
}

int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	memset(b,0,sizeof(b));
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			scanf("%d",&b[i][j]);
	while (q--)
	{
		memset(v,0,sizeof(v));
		scanf("%d%d",&x,&y),b[x][y]=-1,X=x,Y=y;
		scanf("%d%d",&x,&y),b[x][y]=2,XX=x,YY=y;
		scanf("%d%d",&x,&y);
		ans=1000,s=0;
		dfs(X,Y);
		b[X][Y]=b[XX][YY]=1;
		min=p=1000,s=s2=z=0;
		DFS(BX,BY);
		if (min==1000) {puts("-1"); continue;}
		printf("%d\n",ans+min-p);
	}
	return 0;
}
