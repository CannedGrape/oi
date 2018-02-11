#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAXN 31	
#define MAXL 1000000
using namespace std;
int fx[4]={-1,0,1,0},fy[4]={0,1,0,-1};
struct node
{
	int ex,ey,sx,sy,g;
};
node list[MAXL];
int a[MAXN][MAXN]={};
int b[MAXN][MAXN][MAXN][MAXN]={};
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,q;
	cin >> n >> m >> q;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) 
			cin >> a[i][j];
	for (int i=1; i<=q; i++)
	{
		int tx,ty;
		cin >> list[1].ex >> list[1].ey >> list[1].sx >> list[1].sy >> tx >> ty;
		if ((a[list[1].ex][list[1].ey]==0)||(a[list[1].sx][list[1].sy]==0)||(a[tx][ty]==0))
			{cout << -1 << endl; continue;}
		memset(b,0,sizeof(b));
		int h=0,t=1,flag=0;
		list[1].g=0;
		while (h<t)
		{
			h++;
			for (int i=0; i<=3; i++)
			{
				int x=list[h].ex+fx[i],y=list[h].ey+fy[i];
				//cout << list[h].ex << " " << list[h].ey << " " << x << " " << y << "^^^^^^^^" << endl;
				if ((x<1)||(x>n)||(y<1)||(y>m)||(a[x][y]==0)) continue;
				int xx,yy;
				if ((x==list[h].sx)&&(y==list[h].sy))
					{xx=list[h].ex; yy=list[h].ey;} else
					{xx=list[h].sx; yy=list[h].sy;}
				if (b[x][y][xx][yy]) continue;
				t++;
				list[t].ex=x; list[t].ey=y;
				list[t].sx=xx; list[t].sy=yy;
				list[t].g=list[h].g+1;
				b[x][y][xx][yy]=1;
				//cout << x << " " << y << " " << xx << " " << yy << endl;
				if ((xx==tx)&&(yy==ty))
					{cout << list[t].g << endl; flag=1; break;}
			}
			if (flag) break;
		}
		if (!flag) cout << -1 << endl;
	}
	return 0;
}
/*
3 4 2
0 1 1 1
0 1 1 0
0 1 0 0
3 2 1 2 2 2
1 2 2 2 3 2

*/
