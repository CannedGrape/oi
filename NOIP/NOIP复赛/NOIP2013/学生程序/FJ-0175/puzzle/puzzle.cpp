#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;
const int size=810005;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
struct dot{int x1,y1,x2,y2;}Q[size];
int n,m,q,e[35][35][35][35],col[35][35][35][35],map[35][35],num[2];
void work(int ex,int ey,int sx,int sy,int tx,int ty)
{
	memset(e,-1,sizeof(e)); memset(col,-1,sizeof(col));
	int l=1,r=2; Q[1].x1=ex,Q[1].y1=ey,Q[1].x2=sx,Q[1].y2=sy,e[ex][ey][sx][sy]=0,col[ex][ey][sx][sy]=0; num[0]++;
	for (int i=0;i<4;i++)
	{
		int px=tx+dx[i],py=ty+dy[i];
		if (map[px][py])
			Q[r].x1=px,Q[r].y2=py,Q[r].x2=tx,Q[r].y2=ty,e[px][py][tx][ty]=0,col[ex][ey][sx][sy]=1,r++,num[1]++;
	}
	while (l!=r)
	{
		dot t=Q[l];
		for (int i=0;i<4;i++)
		{
			int px=t.x1+dx[i],py=t.y1+dy[i],qx,qy;
			if (!map[px][py]) continue;
			if (px==t.x2 && py==t.y2) qx=t.x1,qy=t.y1; else qx=t.x2,qy=t.y2;
			if (e[px][py][qx][qy]==-1)
			{
				e[px][py][qx][qy]=e[t.x1][t.y1][t.x2][t.y2]+1;
				col[px][py][qx][qy]=col[t.x1][t.y1][t.x2][t.y2];
				Q[r].x1=px,Q[r].y1=py,Q[r].x2=qx,Q[r].y2=qy,r++,r%=size;
				num[col[px][py][qx][qy]]++;
			}
			if (col[px][py][qx][qy]!=col[t.x1][t.y1][t.x2][t.y2])
			{
				printf("%d\n",e[px][py][qx][qy]+e[t.x1][t.y1][t.x2][t.y2]+1);
				return;
			}
		}
		num[col[t.x1][t.y1][t.x2][t.y2]]--;
		if (!num[0] || !num[1]) {printf("-1\n"); return;}
		l++,l%=size;
	}
	printf("-1\n");
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q); int ex,ey,sx,sy,tx,ty;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%d",&map[i][j]);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		work(ex,ey,sx,sy,tx,ty);
	}
	return 0;
}

