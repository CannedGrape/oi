#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int n,m,q,ans;
bool map[35][35],tmp;
bool visit[35][35];
int ex,ey,sx,sy,tx,ty,xx,yy;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};

void dfs(int x,int y,int step)
{
	visit[x][y]=1;
	if (sx==tx && sy==ty)
	{
		if (step<ans) ans=step;
		return;
	}
	for (int i=0;i<4;++i)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		if (1<=xx && xx<=n && 1<=yy && yy<=m && !visit[xx][yy])
		{
			if (xx==sx && yy==sy)
			{
				sx-=dx[i];
				sy-=dy[i];
				tmp=map[xx][yy];
				map[xx][yy]=map[x][y];
				map[x][y]=tmp;
				dfs(xx,yy,step+1);
				tmp=map[xx][yy];
				map[xx][yy]=map[x][y];
				map[x][y]=tmp;
				sx+=dx[i];
				sy+=dy[i];
			}
			else
			{
				tmp=map[xx][yy];
				map[xx][yy]=map[x][y];
				map[x][y]=tmp;
				dfs(xx,yy,step+1);
				tmp=map[xx][yy];
				map[xx][yy]=map[x][y];
				map[x][y]=tmp;
			}
		}
	}
}

int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	int i,j;
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j) scanf("%d",&map[i][j]);
	while (q--)
	{
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		ans=1<<30;
		memset(visit,0,sizeof(visit));
		dfs(ex,ey,0);
		if (ans!=(1<<30))printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}

