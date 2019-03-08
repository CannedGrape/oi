#include <iostream>
#include <cstdio>

using namespace std;

const int maxl=100000000;
int f[32][32][5][5];
int d[32][32][5];
int temp[32][32];
int step[5][3];
bool can_go[32][32],found[32][32],found1[32][32][5];

int n,m,ques;

void init()
{
	scanf("%d%d%d",&n,&m,&ques);
	for (int i=0;i<=n+1;i++)
		for (int j=0;j<=m+1;j++)
			can_go[i][j]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			int k;
			scanf("%d",&k);
			can_go[i][j]=k;
		}
}

void bfs_pre_work(int x1,int y1)
{
	int q[10000][3];
	int f=1,l=1;
	q[1][1]=x1;
	q[1][2]=y1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			found[i][j]=0;
	found[x1][y1]=1;
	while (f<=l)
	{
		int x=q[f][1],y=q[f][2];
		++f;
		for (int i=1;i<=4;i++)
		{
			int xx=x+step[i][1],yy=y+step[i][2];
			if (can_go[xx][yy] && temp[x][y]+1<temp[xx][yy])
			{
				temp[xx][yy]=temp[x][y]+1;
				if (!found[xx][yy])
				{
					++l;
					q[l][1]=xx;
					q[l][2]=yy;
					found[xx][yy]=1;
				}
			}
		}
		found[x][y]=0;
	}
}

void pre_work()
{
	step[1][1]=0; step[1][2]=1;
	step[2][1]=0; step[2][2]=-1;
	step[3][1]=-1; step[3][2]=0;
	step[4][1]=1; step[4][2]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k1=1;k1<=4;k1++)
				for (int k2=1;k2<=4;k2++)
					if (k1!=k2)
					{
						f[i][j][k1][k2]=maxl;
						int x1=i+step[k1][1],y1=j+step[k1][2];
						int x2=i+step[k2][1],y2=j+step[k2][2];
						if (!can_go[x1][y1]) continue;
						if (!can_go[x2][y2]) continue;
						if (!can_go[i][j]) continue;
						for (int i1=1;i1<=n;i1++)
							for (int j1=1;j1<=m;j1++)
								temp[i1][j1]=maxl;/*
						int x1=i+step[k1][1],y1=j+step[k1][2];
						int x2=i+step[k2][1],y2=j+step[k2][2];*/
						temp[i][j]=0;
						can_go[i][j]=0;
						
						bfs_pre_work(x1,y1);
						f[i][j][k1][k2]=temp[x2][y2];
						
						can_go[i][j]=1;
					}
}

void bfs(int sx,int sy)
{
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k=1;k<=4;k++)
				found1[i][j][k]=0;
	int q[100000][5];
	int first=1,last=0;
	for (int i=1;i<=4;i++)
	{
		int x,y;
		x=sx+step[i][1];
		y=sy+step[i][2];
		if (can_go[x][y]) 
		{
			++last;
			q[last][1]=sx;
			q[last][2]=sy;
			q[last][3]=i;
			found1[sx][sy][i]=1;
		}
	}
	while (first<=last)
	{
		int x=q[first][1];
		int y=q[first][2];
		int k=q[first][3];
		++first;
		int ano;
		if (k==1 || k==3) ano=k+1; else ano=k-1;
		int x1,y1;
		x1=x+step[ano][1];
		y1=y+step[ano][2];
		if (can_go[x1][y1] && d[x][y][k]+f[x][y][k][ano]+1<d[x1][y1][k])
		{
			d[x1][y1][k]=d[x][y][k]+f[x][y][k][ano]+1;
			if (!found1[x1][y1][k])
			{
				++last;
				q[last][1]=x1;
				q[last][2]=y1;
				q[last][3]=k;
				found1[x1][y1][k]=1;
			}
		}
		found1[x][y][k]=0;
	}
}
	
void solve()
{
//	cout<<"sfasdfasd"<<endl;
	for (int p=1;p<=ques;p++)
	{
		int ex,ey,sx,sy,tx,ty;
		int ans=maxl;
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		can_go[sx][sy]=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) temp[i][j]=maxl;
		temp[ex][ey]=0;
		bfs_pre_work(ex,ey);
		for (int i=1;i<=4;i++)
		{
			int x,y;
			x=sx+step[i][1];
			y=sy+step[i][2];
			d[sx][sy][i]=temp[x][y];
		}
		can_go[sx][sy]=1;
		
		bfs(sx,sy);
		
		for (int i=1;i<=4;i++)
		{
			int x,y,ano;
			x=tx+step[i][1];
			y=ty=step[i][2];
			if (i==1 || i==3) ano=i+1; else ano=i-1;
			ans=min(ans,d[x][y][ano]+1);
		}
		if (ans>=maxl) printf("-1\n"); else printf("%d\n",ans);
	}
}
	

int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	init();/*
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k1=1;k1<=4;k1++)
				for (int k2=1;k2<=4;k2++)
					printf("%d",f[i][j][k1][k2]);*/
	pre_work();
	solve();
	return 0;
}

