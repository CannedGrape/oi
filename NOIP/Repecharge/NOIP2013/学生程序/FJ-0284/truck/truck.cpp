#include<cstdio>
#include<algorithm>
struct pp{int x,y,N;}q[30010];
bool cmp(const pp&X,const pp&Y) { return X.x<Y.x; };
int g[10000000],las[100010],wei[10010],too[100010],lim[100010];
int che[10010],low[10010],ans[30010],n,m,t=0,a,b,c,l,top,tai,d;

void solve(int a){
	top=0,tai=0;
	for (int i=1; i<=n; i++) low[i]=-1,che[i]=0;
	for (int i=wei[a]; i; i=las[i])
		if (low[too[i]]<lim[i]) {
			low[too[i]]=lim[i] ;
			if (!che[too[i]]) {
				che[too[i]] = 1;
				g[++tai]=too[i];
			} 
		}
	while (++top<=tai){
		int s=g[top];
		for (int i=wei[s]; i; i=las[i]) {
			d=std::min(lim[i],low[s]);
			if (low[too[i]]<d){
				low[too[i]]=d;
				if (!che[too[i]]) {
					che[too[i]] = 1;
					g[++tai]=too[i];
				}
			}
		}	che[s]=0;
	}
} 
int main(){
	freopen("truck.in" ,"r",stdin );
	freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1; i<=m; i++) {
		scanf("%d%d%d",&a,&b,&c);
		las[++t]=wei[a]; wei[a]=t; too[t]=b; lim[t]=c;
		las[++t]=wei[b]; wei[b]=t; too[t]=a; lim[t]=c;
	}   scanf("%d",&l);
	for (int z=1; z<=l; z++) scanf("%d%d",&q[z].x,&q[z].y);
	for (int z=1; z<=l; z++) q[z].N=z;
	std::sort(q+1,q+1+l,cmp); 
	for (int z=1; z<=l; z++) {
		if (q[z].x!=q[z-1].x) solve(q[z].x);
		ans[q[z].N]=low[q[z].y];
	}
	for (int z=1; z<=l; z++) printf("%d\n",ans[z]);
	fclose(stdin );
	fclose(stdout);
}
