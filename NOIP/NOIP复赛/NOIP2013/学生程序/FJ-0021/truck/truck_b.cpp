#include <cstdio>
#include <algorithm>
using namespace std;
const int MaxM = 100;
const int MaxN = 50;
struct node{
	int u,v,z;node* next;
} Ed[MaxM * 2], *P[MaxM];int cnt = 0;
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
int y;
int dfs(int x, int minCost){
	// fprintf(stderr,"%d %d ->\n",x,minCost);
	int rst = -1;
	if (x == y){
		//fprintf(stderr,"%d\n", minCost);
		return minCost;
	}
	vst[x] = true;
	for (node *d = P[x]; d != NULL; d = d->next){
		if (!vst[d->v]){
			rst = max(rst,dfs(d->v, min(minCost, d->z)));
		}
	}
	vst[x] = false;
	return rst;
}
int main(){
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; i++){
		int u,v,z;
		scanf("%d%d%d",&u,&v,&z);
		insert(u,v,z);
	}
	int q;
	scanf("%d",&q);
	for (int i = 0; i < q; i++){
		int x;
		scanf("%d%d",&x,&y);
		printf("%d\n",dfs(x, 0x7fffffff));
	}
}
