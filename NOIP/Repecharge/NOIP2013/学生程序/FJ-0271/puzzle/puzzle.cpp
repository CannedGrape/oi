#include <cstdio>
#include <queue>
#include <cstring>
const int N = 30 + 9,dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m,ex,ey,sx,sy,tx,ty,Time,a[N][N];
std::queue<int> q1,q2;
int vis1[N*N*N*N],vis2[N*N*N*N],d1[N*N*N*N],d2[N*N*N*N],vis[N][N];
inline void unpack(int num,int &x1,int &y1,int &x2,int &y2)
{
	y2 = num % 30 + 1;
	num /= 30;
	x2 = num % 30 + 1;
	num /= 30;
	y1 = num % 30 + 1;
	num /= 30;
	x1 = num % 30 + 1;
}
inline int info(int x1,int y1,int x2,int y2){return (((x1 - 1)*30 + (y1 - 1))*30 + (x2 - 1))*30 + (y2 - 1);}
void dfs(const int _x,const int _y)
{
	if (vis[_x][_y] == Time) return;
	vis[_x][_y] = Time;
	for (int i = 0; i < 4; ++i) {
		const int x = _x + dir[i][0],y = _y + dir[i][1];
		if (!a[x][y]) continue;
		dfs(x,y);
	}
}
bool dfs1(const int _x,const int _y)
{
	if (vis[_x][_y] == Time) return false;
	if (vis[_x][_y] == Time - 1) return true;
	vis[_x][_y] = Time;
	for (int i = 0; i < 4; ++i) {
		const int x = _x + dir[i][0],y = _y + dir[i][1];
		if (!a[x][y]) continue;
		if (dfs1(x,y)) return true;
	}
	return false;
}
bool check()
{
	++Time;
	dfs(tx,ty);
	++Time;
	if (!dfs1(sx,sy)) return false;
	return true;
}
int bfs1()
{
	if (!check()) return -1;
	++Time;
	while (!q1.empty()) q1.pop();
	while (!q2.empty()) q2.pop();
	d1[info(ex,ey,sx,sy)] = 0;
	vis1[info(ex,ey,sx,sy)] = Time;
	//printf("%d\n",info(ex,ey,sx,sy));
	//int a1,a2,a3,a4;
	//unpack(info(30,30,30,30),a1,a2,a3,a4);
	//printf("%d %d %d %d\n",a1,a2,a3,a4);
	for (int i = 0; i < 4; ++i) {
		const int x = tx + dir[i][0],y = ty + dir[i][1];
		if (!a[x][y]) continue;
		q2.push(info(x,y,tx,ty));
		d2[info(x,y,tx,ty)] = 0;
		vis2[info(x,y,tx,ty)] = Time;
	}
	for (q1.push(info(ex,ey,sx,sy)); !q1.empty() && !q2.empty(); ) {
		int u = q1.front(); q1.pop();
		int spx,spy,blx,bly,nblx,nbly;
		unpack(u,spx,spy,blx,bly);
		for (int i = 0; i < 4; ++i) {
			const int x = spx + dir[i][0],y = spy + dir[i][1];
			if (!a[x][y]) continue;
			if (x == blx && y == bly) nblx = spx,nbly = spy;
			else nblx = blx,nbly = bly;
			//if (nblx == tx && nbly == ty) return d1[u] + 1;
			int tmp = info(x,y,nblx,nbly);
			if (vis1[tmp] == Time) continue;
			d1[tmp] = d1[u] + 1;
			vis1[tmp] = Time;
			if (vis2[tmp] == Time) 
				return d2[tmp] + d1[tmp];
			q1.push(tmp);
		}
		u = q2.front(); q2.pop();
		unpack(u,spx,spy,blx,bly);
		for (int i = 0; i < 4; ++i) {
			const int x = spx + dir[i][0],y = spy + dir[i][1];
			if (!a[x][y]) continue;
			if (x == blx && y == bly) nblx = spx,nbly = spy;
			else nblx = blx,nbly = bly;
			//if (nblx == tx && nbly == ty) return d1[u] + 1;
			int tmp = info(x,y,nblx,nbly);
			if (vis2[tmp] == Time) continue;
			vis2[tmp] = Time;
			d2[tmp] = d2[u] + 1;
			if (vis1[tmp] == Time) return d2[tmp] + d1[tmp];
			q2.push(tmp);
		}
	}
	return -1;
}
/*
int bfs()
{
	static std::queue<int> q;
	static int vis[N*N*N*N],d[N*N*N*N];
	++Time;
	while (!q.empty()) q.pop();
	d[info(ex,ey,sx,sy)] = 0;
	vis[info(ex,ey,sx,sy)] = Time;
	//printf("%d\n",info(ex,ey,sx,sy));
	//int a1,a2,a3,a4;
	//unpack(info(30,30,30,30),a1,a2,a3,a4);
	//printf("%d %d %d %d\n",a1,a2,a3,a4);
	for (q.push(info(ex,ey,sx,sy)); !q.empty(); ) {
		const int u = q.front(); q.pop();
		int spx,spy,blx,bly,nblx,nbly;
		unpack(u,spx,spy,blx,bly);
		for (int i = 0; i < 4; ++i) {
			const int x = spx + dir[i][0],y = spy + dir[i][1];
			if (!a[x][y]) continue;
			if (x == blx && y == bly) nblx = spx,nbly = spy;
			else nblx = blx,nbly = bly;
			if (nblx == tx && nbly == ty) return d[u] + 1;
			int tmp = info(x,y,nblx,nbly);
			if (vis[tmp] == Time) continue;
			vis[tmp] = Time;
			d[tmp] = d[u] + 1;
			q.push(tmp);
		}
	}
	return -1;
}
*/
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	int Q;
	scanf("%d%d%d",&n,&m,&Q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) scanf("%d",&a[i][j]);
	while (Q--) {
		scanf("%d %d %d %d %d %d\n",&ex,&ey,&sx,&sy,&tx,&ty);
		if (sx == tx && sy == ty) puts("0");
		else if (!a[tx][ty]) puts("-1");
		else printf("%d\n",bfs1());
	}
	fclose(stdin); fclose(stdout);
}
