#include <cstdio>
#include <algorithm>
using namespace std;
const int MaxM = 50000 + 500;
const int MaxN = 10000 + 111;
struct node{
	int u,v,z;node* next;
}E[MaxM], Ed[MaxM * 2], *P[MaxM];int cnt = 0;
int n,m;
bool cmp(const node &e1, const node &e2){
	return e1.z > e2.z;
}
int fa[MaxN];
int getFather(int x){
	if (fa[x] == x)
		return x;
	return fa[x] = getFather(fa[x]);
}
void insert(int u, int v, int z){
	Ed[cnt].u = u;
	Ed[cnt].v = v;
	Ed[cnt].z = z;
	Ed[cnt].next = P[u];
	P[u] = Ed+cnt;
	cnt++;
	Ed[cnt].u = v;
	Ed[cnt].v = u;
	Ed[cnt].z = z;
	Ed[cnt].next = P[v];
	P[v] = Ed+cnt;
	cnt++;
}
bool vst[MaxN];
int head, tail, Q[MaxN * 2], deep[MaxN], fma[MaxN][16], md[MaxN][16], log2[MaxN];
void bfs(){ 
	// maybe can be solve by union? who cares~
	for (int i = 1; i <= n; i++){
		if (!vst[i]){
			head = tail = 0;deep[i] = 0;
			Q[tail++] = i;vst[i] = true;
			while (head < tail){
				int cur = Q[head++];
				for (int k = 1; k <= log2[deep[cur]]; k++){
					fma[cur][k] = fma[fma[cur][k-1]][k-1];
					md[cur][k] = min(md[cur][k-1],md[fma[cur][k-1]][k-1]);
				}
				for (node * d = P[cur]; d != NULL; d = d->next){
					if (!vst[d->v]){
						deep[d->v] = deep[d->u] + 1;
						fma[d->v][0] = d->u;
						md[d->v][0] = d->z;
						Q[tail++] = d->v;
						vst[d->v] = true;
					}
				}
			}
		}
	}
}
int solve(int x, int y){
	if (deep[x] < deep[y])
		swap(x,y);
	int ret = 0x7fffffff;
	while (deep[x] > deep[y]){
		int k = log2[deep[x] - deep[y]];
		ret = min(ret, md[x][k]);
		x = fma[x][k];
	}
	if (x == y)
		return ret;
	for (int k = log2[deep[x]]; k >= 0; k--){
		if (fma[x][k] != fma[y][k]){
			ret = min(ret, md[x][k]);
			ret = min(ret, md[y][k]);
			x = fma[x][k];
			y = fma[y][k];
		}
	}
	ret = min(ret, md[x][0]);
	ret = min(ret, md[y][0]);	
	return ret;
}
int main(){
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i = 1, j = 0; i < MaxN; i++){
		log2[i] = j;
		if (i == (1 << (j-1) + 1))
			j++;
	}
	
	for (int i = 0; i < m; i++){
		int u,v,z;
		scanf("%d%d%d",&u,&v,&z);
		E[i].u = u, E[i].v = v, E[i].z = z;
	}
	sort(E, E + m, cmp);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 0; i < m; i++){
		int fu = getFather(E[i].u), fv = getFather(E[i].v);
		if (fu != fv){
			insert(E[i].u, E[i].v, E[i].z);
			fa[fu] = fv;
		}
	}
	for (int i = 0; i <= n; i++){
		for (int j = 0; j < 16; j++)
			md[i][j] = 0x3fffffff;
	}
	bfs();
	int q;
	scanf("%d",&q);
	for (int i = 0; i < q; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (getFather(x) != getFather(y)){
			puts("-1");
			continue;
		}
		int ans = solve(x,y);
		printf("%d\n",ans);
	}
}
