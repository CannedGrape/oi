#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#define N 35
using namespace std;

struct point
{
	int x1,y1,x2,y2;
};

int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
int dp[N][N][N][N],map1[N][N],i,j,k,m,n,min1,t,ex,ey,sx,sy,tx,ty,xx,yy;
bool bo[N][N][N][N],ok;
queue <point> q;
point p,p1;

int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	cin >> n >> m >> t;
	for (i=1; i<=n; i++)
	  for (j=1; j<=m; j++) cin >> map1[i][j];
	for (k=1; k<=t; k++)
	{
		ok=false;
		cin >> ex >> ey >> sx >> sy >> tx >> ty;
		while (!q.empty()) q.pop();
		p.x1=ex; p.y1=ey; p.x2=sx; p.y2=sy; q.push(p);
		memset(dp,127,sizeof(dp)); dp[p.x1][p.y1][p.x2][p.y2]=0;
		memset(bo,false,sizeof(bo)); bo[p.x1][p.y1][p.x2][p.y2]=true;
		while (!q.empty())
		{
			if (ok) break;
			p=q.front(); q.pop();
			for (i=0; i<=3; i++)
			{
				xx=p.x1+fx[i]; yy=p.y1+fy[i]; 
				if (xx>n || xx<1 || yy>n || yy<1 || map1[xx][yy]==0) continue;
				if (xx==p.x2 && yy==p.y2)
				{
					p1.x1=p.x2; p1.y1=p.y2; p1.x2=p.x1; p1.y2=p.y1;
				} else
				{
					p1=p; p1.x1=xx; p1.y1=yy;
				}
				if (bo[p1.x1][p1.y1][p1.x2][p1.y2]) continue;
				q.push(p1); dp[p1.x1][p1.y1][p1.x2][p1.y2]=dp[p.x1][p.y1][p.x2][p.y2]+1;
				bo[p1.x1][p1.y1][p1.x2][p1.y2]=true;
				if (p1.x2==tx && p1.y2==ty)
				{
					ok=true;
					cout << dp[p1.x1][p1.y1][p1.x2][p1.y2] << endl;
					break;
				}
			}
		}
		if (!ok) cout << -1 << endl;
	}
	return 0;
}
