#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>

using namespace std;

const int Max=35;

int n,m,q;
int map[Max][Max];
int ex,ey,sx,sy,tx,ty;

void init()
{
	scanf(" %d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) scanf(" %d",&map[i][j]);
		
	for(int i=1;i<=n;i++)
		map[i][0]=map[i][m+1]=0;
	for(int j=1;j<=m;j++)
		map[0][j]=map[n+1][j]=0;
		
	/*for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=m+1;j++) printf("%d ",map[i][j]);
		printf("%d\n");
	}*/
}

int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	
	init();
	for(int i=1;i<=q;i++)
	{
		scanf(" %d %d %d %d %d %d",&ex,&ey,&sx,&sy,&tx,&ty);
		int ts=map[sx+1][sy]+map[sx-1][sy]+map[sx][sy+1]+map[sx][sy-1];
		int tt=map[tx+1][ty]+map[tx-1][ty]+map[tx][ty+1]+map[tx][ty-1];
		if(ts<=1 || tt<=1){printf("-1\n"); continue;}
		printf("%d\n",abs(sx-tx)+abs(sy-ty));
	}
	
	//system("pause");
	return 0;
}

