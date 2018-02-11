#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
const int xy[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
int a[35][35],f[32][32][32][32],d[32][32];
int dis[32][32][32][32];
bool visit[32][32];
int n,m,q,ex,ey,sx,sy,tx,ty;
struct arr {
	int x,y,bx,by;
	arr(int _x = 0,int _y = 0,int _bx = 0,int _by = 0):
		x(_x),y(_y),bx(_bx),by(_by) {}
};
struct ar{
	int x,y;
	ar(int _x = 0,int _y = 0):x(_x),y(_y) {};
};
std::queue<ar> T;
std::queue<arr> Q;
std::queue<arr> QQ;
void BFS() {
	memset(f,255,sizeof(f));
	memset(d,63,sizeof(d));
	d[sx][sy] = 0; f[sx][sy][ex][ey] = 0;
	Q.push(arr(sx,sy,ex,ey));
	while (Q.size()) {
		int x = Q.front().x,y = Q.front().y,
			bx = Q.front().bx,by = Q.front().by;
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int xx = bx + xy[i][0],yy = by + xy[i][1];
			if (xx == x && yy == y && f[bx][by][x][y] == -1) {
				f[bx][by][x][y] = f[x][y][bx][by] + 1;
				Q.push(arr(bx,by,x,y));
				d[bx][by] = std::min(d[bx][by],f[bx][by][x][y]);
			}
			else if (a[xx][yy] != 0 && f[x][y][xx][yy] == -1) {
					f[x][y][xx][yy] = f[x][y][bx][by] + 1;
					Q.push(arr(x,y,xx,yy));
			}
		}
	}
}
void bfs() {
	memset(d,63,sizeof(d));
	d[sx][sy] = 0; f[sx][sy][ex][ey] = 0;
	Q.push(arr(sx,sy,ex,ey));
	while (Q.size()) {
		int x = Q.front().x,y = Q.front().y,
			bx = Q.front().bx,by = Q.front().by;
		QQ.push(Q.front());
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int xx = x + xy[i][0],yy = y + xy[i][1];
			if (xx == bx && yy == by) {
				if (f[xx][yy][x][y] == -1) {
					f[xx][yy][x][y] = f[x][y][bx][by] + 1;
					Q.push(arr(bx,by,x,y));
					d[bx][by] = std::min(d[bx][by],f[bx][by][x][y]);
				}
			}
			else if (a[xx][yy] != 0 && f[x][y][xx][yy] == -1 && 
					dis[bx][by][xx][yy] != -1) {
				f[x][y][xx][yy] = f[x][y][bx][by] + dis[bx][by][xx][yy];
				Q.push(arr(x,y,xx,yy));
			}
		}
	}
	while (QQ.size()) {
		int x = Q.front().x,y = Q.front().y,
			bx = Q.front().bx,by = Q.front().by;
		f[x][y][bx][by] = -1;
		QQ.pop();
	}
}	
void flood(int sx,int sy) {
	memset(visit,0,sizeof(visit));
	T.push(ar(sx,sy));
	dis[sx][sy][sx][sy] = 0; visit[sx][sy] = true;
	while (T.size()) {
		int x = T.front().x,y = T.front().y; T.pop();
		for (int i = 0; i < 4; ++i) {
			int xx = x + xy[i][0],yy = y + xy[i][1];
			if (a[xx][yy] != 0 && !visit[xx][yy]) {
				T.push(ar(xx,yy)); visit[xx][yy] = true;
				dis[sx][sy][xx][yy] = dis[sx][sy][x][y] + 1;
			}
		}
	}
}
int main() {
	freopen("puzzle.in","r",stdin); freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	memset(f,255,sizeof(f));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d",&a[i][j]);
	memset(dis,255,sizeof(dis));

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i][j] != 0) flood(i,j);
	if (q <= 10) {
		for (int i = 1; i <= q; ++i) {
			scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
			BFS();
			if (d[tx][ty] >= 1000000) printf("-1\n");
			else printf("%d\n",d[tx][ty]);
		}
	}
	else {
		for (int i = 1; i <= q; ++i) {
			scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
			bfs();
			if (d[tx][ty] >= 1000000) printf("-1\n");
			else printf("%d\n",d[tx][ty]);
		}
	}	
	fclose(stdin); fclose(stdout);
}
