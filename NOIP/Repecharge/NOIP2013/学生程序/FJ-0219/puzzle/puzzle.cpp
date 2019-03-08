#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>
#define MIN(a,b) ((a)<(b))?(a):(b)
#define swap(a,b) t=(a); (a)=(b); (b)=t;

using namespace std;

int ex,ey,sx,sy,tx,ty;
//空白位置，起始位置，目标位置; 

int map[35][35];//1,3
bool used[35][35][35][35];
bool key[35][35][35][35];
int n,m,q,sum,minn,t;
bool flag;

void search(int x,int y)
{
	if (map[tx][ty]==3) {minn=MIN(minn,sum); flag=1; return;}
	if (sum>=minn) return;
	if (x+1<=n && map[x+1][y]!=0 && (!used[x][y][x+1][y] || (!key[x][y][x+1][y] && map[x+1][y]==3)))
	{
		//cout<<x<<' '<<y<<endl;
		if (map[x+1][y]==3)
		{
			key[x][y][x+1][y]=1;
			swap(map[x][y],map[x+1][y]);
			sum++;
			search(x+1,y);
			swap(map[x][y],map[x+1][y]);
			sum--;
			key[x][y][x+1][y]=0;
		}
		else
		{
			used[x][y][x+1][y]=1;
			swap(map[x][y],map[x+1][y]);
			sum++;
			search(x+1,y);
			swap(map[x][y],map[x+1][y]);
			sum--;
			used[x][y][x+1][y]=0;
	    }
	}
	if (x-1>=1 && map[x-1][y]!=0 && (!used[x][y][x-1][y] || (!key[x][y][x-1][y] && map[x-1][y]==3)))
	{
		//cout<<x<<' '<<y<<endl;
		if (map[x-1][y]==3)
		{
			key[x][y][x-1][y]=1;
			swap(map[x][y],map[x-1][y]);
			sum++;
			search(x-1,y);
			swap(map[x][y],map[x-1][y]);
			sum--;
			key[x][y][x-1][y]=0;
		}
		else
		{
			used[x][y][x-1][y]=1;
			swap(map[x][y],map[x-1][y]);
			sum++;
			search(x-1,y);
			swap(map[x][y],map[x-1][y]);
			sum--;
			used[x][y][x-1][y]=0;
		}
	}
	if (y+1<=m && map[x][y+1]!=0 && (!used[x][y][x][y+1] || (!key[x][y][x][y+1] && map[x][y+1]==3)))
	{
		//cout<<x<<' '<<y<<endl;
		if (map[x][y+1]==3)
		{
			key[x][y][x][y+1]=1;
			swap(map[x][y],map[x][y+1]);
			sum++;
			search(x,y+1);
			swap(map[x][y],map[x][y+1]);
			sum--;
			key[x][y][x][y+1]=0;
		}
		else
		{
			used[x][y][x][y+1]=1;
			swap(map[x][y],map[x][y+1]);
			sum++;
			search(x,y+1);
			swap(map[x][y],map[x][y+1]);
			sum--;
			used[x][y][x][y+1]=0;
		}
	}
	if (y-1>=1 && map[x][y-1]!=0 && (!used[x][y][x][y-1] || (!key[x][y][x][y-1] && map[x][y-1]==3)))
	{
		//cout<<x<<' '<<y<<endl;
		if (map[x][y-1]==3)
		{
			key[x][y][x][y-1]=1;
			swap(map[x][y],map[x][y-1]);
			sum++;
			search(x,y-1);
			swap(map[x][y],map[x][y-1]);
			sum--;
			key[x][y][x][y-1]=0;
		}
		else
		{
			used[x][y][x][y-1]=1;
			swap(map[x][y],map[x][y-1]);
			sum++;
			search(x,y-1);
			swap(map[x][y],map[x][y-1]);
			sum--;
			used[x][y][x][y-1]=0;
		}
	}
	return;
}

int main()
{
	int i,j,temp;
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	for (i=1;i<=q;i++)
	{
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		if (map[tx+1][ty]+map[tx-1][ty]+map[tx][ty+1]+map[tx][ty-1]<=1 && !(tx==ex && tx==ey && abs(tx-sx)+abs(ty-sy)<=1)) {printf("-1\n"); continue;}
		if (map[sx+1][sy]+map[sx-1][sy]+map[sx][sy+1]+map[sx][sy-1]<=0) {printf("-1\n"); continue;}
		if (map[ex+1][ey]+map[ex-1][ey]+map[ex][ey+1]+map[ex][ey-1]<=0) {printf("-1\n"); continue;}
		map[sx][sy]=3;
		minn=n*m*4+10; flag=0; sum=0;
		search(ex,ey);
		map[sx][sy]=1;
		if (flag) printf("%d\n",minn);
		else printf("-1\n");
	}
	return 0;
}
