#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;
const int dxy[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int n,m,q,map[35][35],dis[35][35][4][4],ans[35][35][4],que[35*35][3],Q[35*35*35*35][3],Qhead,Qtail,head,tail;
bool vis[35][35],mark[35][35][4];
int bfs(int x1,int y1,int x2,int y2,int x3,int y3)
{
	head=0;
	que[tail=1][0]=x1; que[1][1]=y1;
	memset(vis,0,sizeof(vis));
	vis[x1][y1]=1;
	while (head<tail)
	{
		int x=que[++head][0],y=que[head][1],i,xx,yy;
		if (x==x2 && y==y2) return que[head][2];
		for (i=0;i<4;++i)
		{
			xx=x+dxy[i][0],yy=y+dxy[i][1];
			if (xx>0 && yy>0 && xx<=n && yy<=m && map[xx][yy] && (xx!=x3 || yy!=y3) && !vis[xx][yy])
				vis[xx][yy]=1,que[++tail][0]=xx,que[tail][1]=yy,que[tail][2]=que[head][2]+1;
		}
	}
	return -1;
}
void dfs(int x,int y)
{
	int i,j,xx,yy,xxx,yyy;
	for (i=0;i<4;++i)
		for (j=i+1;j<4;++j)
		{
			xx=x+dxy[i][0]; yy=y+dxy[i][1];
			xxx=x+dxy[j][0]; yyy=y+dxy[j][1];
			if (map[xx][yy] && map[xxx][yyy] && xx>0 && yy>0 && xxx>0 && yyy>0 && xx<=n && xxx<=n && yy<=m && yyy<=m)
				dis[x][y][i][j]=dis[x][y][j][i]=bfs(xx,yy,xxx,yyy,x,y);
			else
				dis[x][y][i][j]=dis[x][y][j][i]=-1;
		}
}
void Solve()
{
	int kx,ky,sx,sy,ex,ey,i,j,tmp,flag,sum;
	scanf("%d%d%d%d%d%d",&kx,&ky,&sx,&sy,&ex,&ey);
	memset(ans,60,sizeof(ans));
	flag=sum=ans[0][0][0];
	Qhead=0; Qtail=0;
	for (i=0;i<4;++i)
	{
		int x=sx+dxy[i][0],y=sy+dxy[i][1];
		if (x>0 && y>0 && x<=n && y<=m && map[x][y])
		{
			tmp=bfs(kx,ky,x,y,sx,sy);
			if (tmp!=-1)
			{
				Q[++Qtail][0]=sx;
				Q[Qtail][1]=sy;
				Q[Qtail][2]=i;
				//mark[x][y][i^1]=1;
				mark[sx][sy][i]=1;
				ans[sx][sy][i]=tmp;
				//dis[x][y][i^1]=tmp+1;
			}
		}
	}
	while (Qhead<Qtail)
	{
		int x=Q[++Qhead][0],y=Q[Qhead][1],d=Q[Qhead][2],xx,yy;
		xx=x+dxy[d][0],yy=y+dxy[d][1];
		if (ans[x][y][d]+1<ans[xx][yy][d^1])
		{
			ans[xx][yy][d^1]=ans[x][y][d]+1;
			if (!mark[xx][yy][d^1])
				Q[++Qtail][0]=xx,Q[Qtail][1]=yy,Q[Qtail][2]=d^1;
		}
		for (i=0;i<4;++i)
			if (i!=d && dis[x][y][d][i]!=-1 && ans[x][y][i]>ans[x][y][d]+dis[x][y][d][i])
			{
				ans[x][y][i]=ans[x][y][d]+dis[x][y][d][i];
				if (!mark[x][y][i])
					Q[++Qtail][0]=x,Q[Qtail][1]=y,Q[Qtail][2]=i;
			}
		mark[x][y][d]=0;
	}
	for (i=0;i<4;++i)
		sum=min(sum,ans[ex][ey][i]);
	if (sum==flag)
		puts("-1");
	else
		printf("%d\n",sum);
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	int i,j;
	scanf("%d%d%d",&n,&m,&q);
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j)
			scanf("%d",&map[i][j]);
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j)
			if (map[i][j]) dfs(i,j);
	for (i=1;i<=q;++i)
		Solve();
	//system("pause");
	return 0;
}
