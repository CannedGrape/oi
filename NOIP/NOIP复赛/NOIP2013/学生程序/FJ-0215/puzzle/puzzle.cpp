#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MaxN=35;
const int MaxT=MaxN*MaxN*MaxN*MaxN;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

int n,m,a[MaxN][MaxN],ans;
bool v[MaxN][MaxN][MaxN][MaxN];
int q[MaxT][5];
int p;
int kx,ky,sx,sy,tx,ty;

int bfs()
{
	memset(v,0,sizeof(v));
	v[kx][ky][sx][sy]=1;
	q[0][0]=kx;
	q[0][1]=ky;
	q[0][2]=sx;
	q[0][3]=sy;
	q[0][4]=0;
	for (int first=0,last=1;first!=last;first++)
	{
		if (first>=MaxT)
		{
			first-=MaxT;
		}
		int x=q[first][0],y=q[first][1];
		if (q[first][2]==tx && q[first][3]==ty)
		{
			return q[first][4];
		}
		for (int i=0;i<4;i++)
		{
			int x1=x+dx[i],y1=y+dy[i],x2,y2;
			if (x1<=0 || y1<=0 || x1>n || y1>m || a[x1][y1]==0)
			{
				continue;
			}
			if (x1==q[first][2] && y1==q[first][3])
			{
				x2=x;
				y2=y;
			}
			else
			{
				x2=q[first][2];
				y2=q[first][3];
			}
			if (v[x1][y1][x2][y2]==0)
			{
				v[x1][y1][x2][y2]=1;
				q[last][0]=x1;
				q[last][1]=y1;
				q[last][2]=x2;
				q[last][3]=y2;
				q[last][4]=q[first][4]+1;
				last++;
				if (last>=MaxT)
				{
					last-=MaxT;
				}
			}
		}
	}
	return -1;
}

int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for (int i=0;i<p;i++)
	{
		scanf("%d%d%d%d%d%d",&kx,&ky,&sx,&sy,&tx,&ty);
		printf("%d\n",bfs());
	}
	return 0;
}
