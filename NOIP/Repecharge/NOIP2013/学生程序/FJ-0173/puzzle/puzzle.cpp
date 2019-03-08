#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int Inf=729000001;
const int F=90001;
const int K[4][2]={{-1,0},{0,1},{0,-1},{1,0}};
const int U[8][2]={{-2,0},{0,-2},{0,2},{2,0},{1,-1},{-1,1},{1,1},{-1,-1}};
int task[32][32][4][8],dist[32][32],tt,SS;
int f[32][32][4],a[32][32],T,ex,ey,sx,sy,tx,ty,n,m,q,i,j,k,u;
bool sign[32][32][4];
bool pd(int x,int y)
{
	return ((x<=n)&&(y<=m)&&(x>0)&&(y>0)&&(a[x][y]==1));
}
void askdist(int x,int y)
{
	int ti,tj,tn=1,t=0;
	bool coed[32][32];
	int g[90001][3];
	for (ti=0;ti<=n+1;ti++)
		for (tj=0;tj<=m+1;tj++)
		{
			dist[ti][tj]=Inf;
			coed[ti][tj]=true;
		}
	if (!pd(x,y)) return;
	coed[x][y]=false;
	g[1][0]=x;g[1][1]=y;g[1][2]=0;
	while (t!=tn)
	{
		t++;if (t>F) t-=F;
		dist[g[t][0]][g[t][1]]=g[t][2];
		for (ti=0;ti<4;ti++)
		{
			if ((pd(g[t][0]+K[ti][0],g[t][1]+K[ti][1]))
			&&(coed[g[t][0]+K[ti][0]][g[t][1]+K[ti][1]]))
			{
				coed[g[t][0]+K[ti][0]][g[t][1]+K[ti][1]]=false;
				tn++;if (tn>F) tn-=F;
				g[tn][0]=g[t][0]+K[ti][0];
				g[tn][1]=g[t][1]+K[ti][1];
				g[tn][2]=g[t][2]+1;
			}
		}
	}
}
int askd(int x,int y,int dx,int dy,int tk)
{
	for (int tu=0;tu<8;tu++)
	{
		if ((U[tu][0]==dx)&&(U[tu][1]==dy))
			return task[x][y][tk][tu];
	}
	return Inf;
}
int askf(int x,int y,int tk)
{
	
	if (f[x][y][tk]>=0) return f[x][y][tk];
	if (!(pd(x,y) && sign[x][y][tk])) {f[x][y][tk]=Inf;return Inf;}
	sign[x][y][tk]=false;
	int ts,tmp[4],k1;
	ts=askf(x+K[tk][0],y+K[tk][1],3-tk)+1;
	for (k1=0;k1<4;k1++)
	if (k1!=tk)
	{tmp[k1]=askf(x,y,k1);}
	for (k1=0;k1<4;k1++)
		if ((tk!=k1)&&(tmp[k1]<Inf))
			ts=min(ts,tmp[k1]+
			askd(x+K[k1][0],y+K[k1][1],K[tk][0]-K[k1][0],K[tk][1]-K[k1][1],3-k1));
	f[x][y][tk]=ts;
	sign[x][y][tk]=true;
	return ts;
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			for (k=0;k<4;k++)
				for (u=0;u<8;u++)
					task[i][j][k][u]=Inf;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			for (k=0;k<4;k++)
				if (pd(i+K[k][0],j+K[k][1]))
				{
					tt=a[i+K[k][0]][j+K[k][1]];
					a[i+K[k][0]][j+K[k][1]]=0;
					askdist(i,j);
					for (u=0;u<8;u++)
						if (pd(i+U[u][0],j+U[u][1]))
							task[i][j][k][u]=dist[i+U[u][0]][j+U[u][1]];
					a[i+K[k][0]][j+K[k][1]]=tt;
				}
	for (T=1;T<=q;T++)
	{
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		tt=a[sx][sy];
		a[sx][sy]=0;
		askdist(ex,ey);
		a[sx][sy]=tt;
		SS=Inf;
		for (k=0;k<4;k++)
		{
			for (i=0;i<=n+1;i++)
				for (j=0;j<=m+1;j++)
					for (u=0;u<4;u++)
					{
						sign[i][j][u]=true;
						f[i][j][u]=-1;
					}
			for (u=0;u<4;u++)
				f[sx][sy][u]=dist[sx+K[u][0]][sy+K[u][1]];
				SS=min(askf(tx,ty,k),SS);
		}
		if (SS>=Inf) printf("-1\n");
		else printf("%d\n",SS);
	}
	return 0;
}
