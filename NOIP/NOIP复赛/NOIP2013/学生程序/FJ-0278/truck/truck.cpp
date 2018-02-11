#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
const int maxn = 10005,maxdeep = 15;
struct edge {
	int v,w,no; edge* next;
} *from[maxn];
struct Graph {
	edge ES[100005],*tot[maxn];
	int EC;
	void add(int u,int v,int w,int no) {
		ES[++EC].v = v; ES[EC].w = w; ES[EC].no = no;
		ES[EC].next = tot[u]; tot[u] = ES + EC;
	} 
} ori,ne;
struct arr {
	int v,w;
	arr(int _v,int _w):v(_v),w(_w) {}
};
bool operator<(const arr& lhs,const arr& rhs) {
	return lhs.w < rhs.w;
}
std::queue<int> Q;
std::priority_queue<arr> T;
int n,m,q,size;
int dis[maxn],color[maxn],E[100005][3];
int dep[maxn],fa[maxn][16],d[maxn][16];
bool visit[maxn];
void work(int st) {
	dis[st] = 100005;
	T.push(arr(st,dis[st]));
	while (T.size()) {
		int x = T.top().v,w = T.top().w; T.pop();
		if (dis[x] != w || visit[x]) continue;
		visit[x] = true;
		for (edge* e = ori.tot[x]; e; e = e->next)
			if (e->w > dis[e->v] && !visit[e->v]) {
				dis[e->v] = e->w;
				from[e->v] = e;
				T.push(arr(e->v,dis[e->v]));
			} 	
	}
}
void bfs(int st) {
	++size; Q.push(st); visit[st] = true;
	while (Q.size()) {
		int x = Q.front(); Q.pop();
		color[x] = size;
		for (edge* e = ori.tot[x]; e; e = e->next)
			if (!visit[e->v]) {
				Q.push(e->v);
				visit[e->v] = true;
			}
	}
} 
void BFS(int st) {
	Q.push(st); dep[st] = 0; visit[st] = true; 
	d[st][0] = 100005;
	while (Q.size()) {
		int x = Q.front(); Q.pop();
		for (edge* e = ne.tot[x]; e; e = e->next)
			if (!visit[e->v]) {
				dep[e->v] = dep[x] + 1;
				d[e->v][0] = e->w; fa[e->v][0] = x;
				Q.push(e->v); visit[e->v] = true;
			}
	}
}	
void lca_prepare() {
	for (int k = 1; k <= maxdeep; ++k)
		for (int i = 1; i <= n; ++i)
			if (dep[i] >= (1 << k)) {
				int ff = fa[i][k - 1];
				d[i][k] = std::min(d[i][k - 1],d[ff][k - 1]);
				fa[i][k] = fa[ff][k - 1];
			}
}
void prepare() {
	for (int i = 1; i <= n; ++i)
		if (!visit[i]) bfs(i);

	memset(visit,0,sizeof(visit));
	for (int i = 1; i <= n; ++i)
		if (!visit[i]) work(i); 
	for (int i = 1; i <= n; ++i)
		if (from[i]) {
			int no = from[i]->no;
			//printf("%d %d %d\n",E[no][0],E[no][1],E[no][2]);
			ne.add(E[no][0],E[no][1],E[no][2],i);
			ne.add(E[no][1],E[no][0],E[no][2],i);
		}

	memset(visit,0,sizeof(visit));
	for (int i = 1; i <= n; ++i)
		if (!visit[i]) BFS(i);
	lca_prepare();
}
int Query(int x,int y) {
	int ans = 100005;
	if (dep[x] != dep[y]) {
		if (dep[y] < dep[x]) std::swap(x,y);
		for (int k = maxdeep; k >= 0; --k)
			if (dep[y] - dep[x] >= (1 << k)) {
				ans = std::min(ans,d[y][k]);
				y = fa[y][k];
			}
	}
	if (x == y) return ans;
	for (int k = maxdeep; k >= 0; --k)
		if (fa[x][k] != fa[y][k]) {
			ans = std::min(ans,std::min(d[x][k],d[y][k]));
			x = fa[x][k],y = fa[y][k];
		}
	ans = std::min(ans,std::min(d[x][0],d[y][0]));
	return ans;
}
int main() {
	freopen("truck.in","r",stdin); freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; ++i) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		E[i][0] = x; E[i][1] = y; E[i][2] = z;
		ori.add(x,y,z,i); ori.add(y,x,z,i);
	}
	memset(dis,255,sizeof(dis));
	prepare();
	scanf("%d",&q);
	for (int i = 1; i <= q; ++i) {
		int x,y;
		scanf("%d%d",&x,&y);
		if (color[x] != color[y]) printf("-1\n");
		else printf("%d\n",Query(x,y));
	}
	fclose(stdin); fclose(stdout);
}
