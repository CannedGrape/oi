#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
const int Maxn = 10005,Maxm = 50005,INF = 0x3F3F3F3F;
struct Link {
  int u,v, f;
} Links[Maxm];
inline bool operator < (const Link &lhs, const Link &rhs) {
  return lhs.f > rhs.f; }
  
struct links{
  int vex, f;
  links *next;
}*first[Maxn], T[Maxn * 2];

int Linksize,fa[Maxn],Maxdep,dep[Maxn],f[Maxn][15],Min[Maxn][15],x,y;
bool p[Maxn];

void AddEdge(int u, int v, int f) {
  links *node = T + (++Linksize);
  node -> vex = v;
  node -> f = f;
  node -> next = first[u];
  first[u] = node;
}

int getfather(int k) {
  return (fa[k] == k ? k: (fa[k] = getfather(fa[k]))); }
   
void  dfs(int k ,int deep, int father) {
  p[k] = true; dep[k] = deep; f[k][0] = father; 
  Maxdep = std::max(Maxdep, dep[k]);
  for (links *e = first[k]; e; e = e -> next) 
    if (!p[e->vex]) {
	  Min[e->vex][0] = e -> f;
	  dfs(e -> vex, deep + 1, k);
   }
}
int query(int u, int v) {
  if (dep[u] < dep[v]) std::swap(u,v);
  int ans = INF,delta = dep[u] - dep[v];
  for (int i = 0; (1<<i) <= delta; ++i) 
    if ((1 << i)&delta) {
	  ans = std::min(ans, Min[u][i]);
	  u = f[u][i];
    }
  if (u == v) return ans;
  for (int i = 15; i >= 0; --i) 
    if ((1 << i) <= dep[v]) 
	  if (f[u][i] != f[v][i]) {
		u = f[u][i], v = f[v][i];
		ans = std::min(ans, Min[u][i]);
		ans = std::min(ans, Min[v][i]);
      }
  ans = std::min(ans,Min[u][0]);
  ans = std::min(ans,Min[v][0]);
  return ans;
}	 
int n,m,c;
int main() {
  freopen("truck.in","r",stdin); freopen("truck.out","w",stdout);
    scanf("%d%d", &n,&m);
	for (int i = 0; i < m; ++i) 
	  scanf("%d%d%d",&Links[i].u, &Links[i].v, &Links[i].f);
	  
	std::sort(Links,Links + m);
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 0; i < m; ++i) {
	  int u = getfather(Links[i].u), v = getfather(Links[i].v);
	  if (u != v) {
		AddEdge(Links[i].u, Links[i].v, Links[i].f);
		AddEdge(Links[i].v, Links[i].u, Links[i].f);
		fa[u] = v;
      }
   }
 
   Maxdep = 0;
   memset(p,0,sizeof(p));
   for (int i = 1; i <= n; ++i) 
   if (!p[i]) {Min[i][0] = INF;dfs(i,1,0);}
   
   for (int i = 1; (1 << i) <= Maxdep; ++i) 
     for (int j = 1; j <= n; ++j) 
       if ((1 << i) < dep[j]) {
		  int u = f[j][i-1];
		  f[j][i] = f[u][i-1];
	      Min[j][i] = std::min(Min[j][i-1], Min[u][i-1]);
	   }
	
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
	  scanf("%d%d", &x, &y);
	  int u = getfather(x), v = getfather(y);
	  if (u != v) {printf("-1\n"); continue;}
	  printf("%d\n",query(x,y));
	} 

  fclose(stdin); fclose(stdout);
}
	  
   
	   
