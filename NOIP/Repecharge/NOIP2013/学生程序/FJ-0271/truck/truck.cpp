#include <cstdio>
#include <algorithm>
#include <map>
const int N = 10000 + 9;
bool is_root[N];
std::map<std::pair<int,int>,int>Map;
int n,m,f[N],ec,tmp[N],q,depth[N],fa[N],val[N],son[N];
struct Edge{int x,y,z;}edg[50000 + 9];
inline bool cmp(const Edge &a,const Edge &b){return a.z > b.z;}
struct Tree_edge{int link,next;}es[N];
int getf(int x)
{
	for (tmp[0] = 0; x != f[x]; x = f[x]) tmp[++tmp[0]] = x;
	for (int i = 1; i <= tmp[0]; ++i) f[tmp[i]] = x;
	return x;
}
inline void addedge(const int x,const int y)
{
	es[++ec].next = son[x];
	son[x] = ec;
	es[ec].link = y;
}
void dfs(const int u)
{
	for (int i = son[u]; i; i = es[i].next) {
		depth[es[i].link] = depth[u] + 1;
		dfs(es[i].link);
	}
}
int main()
{
	freopen("truck.in","r",stdin); freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; ++i) scanf("%d%d%d",&edg[i].x,&edg[i].y,&edg[i].z);
	std::sort(edg + 1,edg + 1 + m,cmp);
	for (int i = 1; i <= n; ++i) f[i] = i,is_root[i] = true;
	for (int i = 1; i <= m; ++i) {
		int fx = getf(edg[i].x),fy = getf(edg[i].y);
		//printf("%d %d\n",fx,fy);
		if (fx == fy) continue;
		f[fx] = fy;
		fa[fx] = fy;
		val[fx] = edg[i].z;
		is_root[fx] = false;
		addedge(fy,fx);
	}
	for (int i = 1; i <= n; ++i) {
		getf(i);
		if (is_root[i]) addedge(n + 1,i);
	}
	dfs(n + 1);
	scanf("%d",&q);
	for (int i = 1,s,t; i <= q; ++i) {
		scanf("%d%d",&s,&t);
		if (f[s] != f[t]) {puts("-1");continue;}
		if (depth[s] < depth[t] || depth[s] == depth[t] && s > t) std::swap(s,t);
		int tmp = Map[std::make_pair(s,t)];
		if (tmp) {printf("%d\n",tmp);continue;}
		int _s = s,_t = t,ans = 0x7fffffff;
		while (depth[s] != depth[t]) {
			if (ans > val[s]) ans = val[s];
			s = fa[s];
		}
		while (s != t) {
			if (ans > val[s]) ans = val[s];
			if (ans > val[t]) ans = val[t];
			s = fa[s]; t = fa[t];
		}
		Map[std::make_pair(_s,_t)] = ans;
		printf("%d\n",ans);
	}
	fclose(stdin); fclose(stdout);
}
