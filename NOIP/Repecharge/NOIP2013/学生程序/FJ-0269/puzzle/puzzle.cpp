#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int xy[4][2] = {{0,-1},{-1,0},{1,0},{0,1}};
struct node
{
	int x,y,x2,y2,t;
}q[10000],st,ed,sp;
int d1[32][32][32][32],d2[32][32][32][32],f[32][32][32][32],map[32][32];
bool p[32][32],instack[32][32][32][32];
int n,m,Q;
/*void prepare(int x0,int y0)
{
	bool instack[32][32];
	memset(p,0,sizeof(p));
	memset(instack,0,sizeof(instack));
	d1[x0][y0][x0][y0] = 0,d2[x0][y0][x0][y0] = 1 << 30;
	int h = 0,t = 1;
	q[1].x = x0,q[1].y = y0;
	p[x0][y0] = true;
	while (h < t)
	{
		node u = q[++h];
		instack[u.x][u.y] = false;
		for (int i = 0;i < 4;i ++)
		{
			int xx = u.x  + xy[i][0],yy = u.y + xy[i][1];
			if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
			if (map[xx][yy] == 0) continue;
			int tmp1 = d1[x0][y0][u.x][u.y] + 1;
			int tmp2;
			if (tmp1 < d1[x0][y0][xx][yy])
				tmp2 = d2[x0][y0][u.x][u.y] + 1;
			else tmp2 = d1[x0][y0][u.x][u.y] + 1;
			if (d1[x0][y0][xx][yy] <= tmp1 && d2[x0][y0][xx][yy] <= tmp2) continue;
			d2[x0][y0][xx][yy] = min(d2[x0][y0][xx][yy],tmp2);
			d1[x0][y0][xx][yy] = min(d1[x0][y0][xx][yy],tmp1);
			if (!instack[xx][yy])
			{
				p[xx][yy] = true;
				q[++t].x = xx;
				q[t].y = yy;
				instack[xx][yy] = true;
			}
		}
	}
}*/
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d %d %d",&n,&m,&Q);
	for (int i = 1;i <= n;i ++)
		for (int j = 1;j <= m;j ++)
			scanf("%d",&map[i][j]);
	/*memset(d1,0x3f,sizeof(d1));
	memset(d2,0x3f,sizeof(d2));
	for (int i = 1;i <= n;i ++)
		for (int j = 1;j <= m;j ++)
			if (map[i][j])
				prepare(i,j);
	for (int i = 1;i <= n;i ++)
		for (int j = 1;j <= m;j ++)
			for (int k = 1;k <= n;k ++)
				for (int l = 1;l <= m;l ++)
					printf("%d %d %d %d %d %d\n",i,j,k,l,d1[i][j][k][l],d2[i][j][k][l]);*/
	for (int i = 1;i <= Q;i ++)
	{
		scanf("%d%d%d%d%d%d",&sp.x,&sp.y,&st.x,&st.y,&ed.x,&ed.y);
		memset(instack,0,sizeof(instack));
		memset(f,0x3f,sizeof(f));
		/*int h = 0,t = 0;
		for (int j = 0;j < 4;j ++)
		{
			int xx = st.x  + xy[j][0],yy = st.y + xy[j][1];
			if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
			if (map[xx][yy] == 0) continue;
			int newd;
			if (d1[sp.x][sp.y][xx][yy] == d1[sp.x][sp.y][st.x][st.y] + d1[st.x][st.y][xx][yy])
				newd = d2[sp.x][sp.y][xx][yy];
			else newd = d1[sp.x][sp.y][xx][yy];
			if (newd > 500000000) continue;
			q[++t].x = xx;
			q[t].y = yy;
			q[t].t = j;
			f[xx][yy][j] = newd;
			instack[xx][yy][j] = true;
		}
		while (h < t)
		{
			node u = q[++h];
			for (int j = 0;j < 4;j ++)
			{
				if (j == u.t) continue;
				int xx = u.x  + xy[j][0],yy = u.y + xy[j][1];
				if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
				if (map[xx][yy] == 0) continue;
				
				if (f[u.x][u.y][j] <= d2[u.x + xy[u.t][0]][u.y + xy[u.t][1]][xx][yy] + f[u.x][u.y][u.t]) continue;
				f[u.x][u.y][j] = d2[u.x + xy[u.t][0]][u.y + xy[u.t][1]][xx][yy] + f[u.x][u.y][u.t];
				if (instack[u.x][u.y][j]) continue;
				q[++t].x = u.x;
				q[t].y = u.y;
				q[t].t = j;
			}
			int xx = u.x + xy[u.t][0],yy = u.y + xy[u.t][1];
			if (f[xx][yy][3 - u.t] <= f[u.x][u.y][u.t] + 1) continue;
			f[xx][yy][3 - u.t] = f[u.x][u.y][u.t] + 1;
			if (instack[u.x][u.y][3 - u.t]) continue;
			q[++t].x = xx;
			q[t].y = yy;
			q[t].t = 3 - u.t;	
		}*/
		int h = 0,t = 1;
		q[1].x = st.x,q[1].y = st.y,q[1].x2 = sp.x,q[1].y2 = sp.y;
		f[st.x][st.y][sp.x][sp.y] = 0;
		instack[st.x][st.y][sp.x][sp.y] = true;
		while (h < t)
		{
			node u = q[++h];
			instack[u.x][u.y][u.x2][u.y2] = true;
			for (int j = 0;j < 4;j ++)
			{
				int xx = u.x2  + xy[j][0],yy = u.y2 + xy[j][1];
				if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
				if (map[xx][yy] == 0) continue;
				if (xx == u.x && yy == u.y)
				{
					if (f[u.x2][u.y2][u.x][u.y] <= f[u.x][u.y][u.x2][u.y2]+ 1) continue;
					f[u.x2][u.y2][u.x][u.y] = f[u.x][u.y][u.x2][u.y2] + 1;
					if (!instack[u.x2][u.y2][u.x][u.y])
					{
						q[++t].x = u.x2;
						q[t].y = u.y2;
						q[t].x2 = u.x;
						q[t].y2 = u.y;
						instack[u.x2][u.y2][u.x][u.y] = true;
					}
				}else {
					if (f[u.x][u.y][xx][yy] <= f[u.x][u.y][u.x2][u.y2] + 1) continue;
					f[u.x][u.y][xx][yy] = f[u.x][u.y][u.x2][u.y2] + 1;
					if (!instack[u.x][u.y][xx][yy])
					{
						q[++t].x = u.x;
						q[t].y = u.y;
						q[t].x2 = xx;
						q[t].y2 = yy;
						instack[u.x][u.y][xx][yy] = true;
					}
				}
			}
		}	
		int ans = 1 << 30;
		for (int i = 1;i <= 32;i ++)
			for (int j = 1;j <= 32;j ++)
				ans = min(ans,f[ed.x][ed.y][i][j]);
		if (ans <= 500000000) printf("%d\n",ans);
			else printf("%d\n",-1);
	}
	fclose(stdin);fclose(stdout);
}