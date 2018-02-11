#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int xsz[5]={0,0,1,0,-1},ysz[5]={0,1,0,-1,0};

int n,m,q,ex,ey,sx,sy,tx,ty,ans;
int bz[33][33],map[33][33],sz[1000][4];

int bfs(int x1,int y1,int x2,int y2)
{
	for (int i=0;i<=n+1;i++)
		for (int j=0;j<=m+1;j++)bz[i][j]=1;
	int l=1,r=2;
	sz[l][1]=x1;sz[l][2]=x2,sz[l][3]=0,bz[x1][y1]=0;
	while (l<r)
	{
		for(int i=1;i<=4;i++)
		{
			int x=sz[l][1]+xsz[i],y=sz[l][2]+ysz[i];
			if (map[x][y]&&bz[x][y])
			{
				sz[r][1]=x;
				sz[r][2]=y;
				sz[r][3]=sz[l][3]+1;
				bz[x][y]=0;
			}
			if (x==x2&&y==y2)return sz[r][3];
		}	
		l++;
	}
}

int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<=n+1;i++)
		for (int j=0;j<=m+1;j++)map[i][j]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)scanf("%d",&map[i][j]);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		int js1,js2,js3;
		js1=0,js2=0,js3=0;
		for (int i=1;i<=4;i++)
		{
			if (map[ex+xsz[i]][ey+ysz[i]])js1++;
			if (map[sx+xsz[i]][sy+ysz[i]])js2++;
			if (map[tx+xsz[i]][ty+ysz[i]])js3++;
		}
		if (js1<2||js2<2||js3<2)printf("%d\n",-1);else
		{
			ans=0;
			ans+=bfs(tx,ty,ex,ey);
			ans+=1+(bfs(sx,sy,tx,ty)-1)*3;
			printf("%d\n",ans);
		}
	}
	return 0;
}
