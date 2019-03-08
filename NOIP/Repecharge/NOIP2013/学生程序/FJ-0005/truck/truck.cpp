#include<cstdio>
#include<algorithm>
#define MaxN 10000
#define MaxM 100000

struct my_edge{
	int u,v,c;
	my_edge(int u=0,int v=0,int c=0):u(u),v(v),c(c){}
	
	bool operator <(const my_edge &rsh)const{
		return c>rsh.c;
	}
} e[MaxM+5];

int far[MaxN+5];
int fus_find(int x){
	return x^far[x]?far[x]=fus_find(far[x]):x;
}

int esiz,eprv[MaxM+5],elst[MaxN+5],etar[MaxM+5],ecst[MaxM+5];
void insert(int u,int v,int c){
	eprv[++esiz]=elst[u],elst[u]=esiz,etar[esiz]=v,ecst[esiz]=c,
	eprv[++esiz]=elst[v],elst[v]=esiz,etar[esiz]=u,ecst[esiz]=c;
}

int qh,qt,tcol,q[MaxN+5],col[MaxN+5],dep[MaxN+5],pth[MaxN+5][16],cst[MaxN+5][16];
void flood_fill(int x){
	for(col[q[qh=qt=1]=x]=++tcol,dep[x]=1,pth[x][0]=0,cst[x][0]=0;qh<=qt;++qh)
		for(int nx=q[qh],i=elst[nx],tx;i;i=eprv[i]) if (!col[tx=etar[i]]) col[q[++qt]=tx]=tcol,dep[tx]=dep[nx]+1,pth[tx][0]=nx,cst[tx][0]=ecst[i];
	for(int i=1;i<=qt;++i)
		for(int nx=q[i],d=1;d<16;++d) pth[nx][d]=pth[pth[nx][d-1]][d-1],cst[nx][d]=std::min(cst[nx][d-1],cst[pth[nx][d-1]][d-1]);
}

int lca_query(int u,int v){
	int res=100000;
	if (dep[u]>dep[v]) std::swap(u,v);
	for(int d=15;~d;--d) if (dep[pth[v][d]]>=dep[u]) res=std::min(cst[v][d],res),v=pth[v][d];
	if (u==v) return res;
	for(int d=15;~d;--d) if (pth[u][d]^pth[v][d]) res=std::min(std::min(cst[u][d],cst[v][d]),res),u=pth[u][d],v=pth[v][d];
	return std::min(std::min(cst[u][0],cst[v][0]),res);
}

int n,m,qs;
int main(){
	freopen("truck.in","r",stdin),freopen("truck.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1,x,y,z;i<=m;++i) scanf("%d %d %d",&x,&y,&z),e[i]=my_edge(x,y,z);
	std::sort(e+1,e+m+1);
	for(int i=1;i<=n;++i) far[i]=i;
	for(int i=1,x,y;i<=m;++i) if ((x=fus_find(e[i].u))^(y=fus_find(e[i].v))) insert(e[i].u,e[i].v,e[i].c),far[x]=y;
	for(int i=1;i<=n;++i) if (!col[i]) flood_fill(i);
	scanf("%d",&qs);
	for(int x,y;qs--;) scanf("%d %d",&x,&y),printf(col[x]^col[y]?"-1\n":"%d\n",lca_query(x,y));
	return 0;
}
