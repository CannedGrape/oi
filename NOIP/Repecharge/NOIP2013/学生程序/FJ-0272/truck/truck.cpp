#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 20000
#define M 60000
struct P{
	int x,y,z;
}a[M];
bool cmp(const P&X,const P&Y){
	return X.z>Y.z;
}
int lim[N][30],f[N][30],n,m,root[N];
int next[M],d[M],last[M],to[M],w[M],T,Q;
bool vis[N];
std::queue<int> q;
void Min(int &x,int y){
	if(y<x) x=y;
}
void addedge(int x,int y,int z){
	next[++T]=last[x]; last[x]=T; to[T]=y; w[T]=z;
	next[++T]=last[y]; last[y]=T; to[T]=x; w[T]=z;
}
int find(int now){
	return root[now]==now ? now : root[now]=find(root[now]);
}
void kruskal(){
	for(int i=1;i<=n;i++) root[i]=i;
	std::sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		int fx=find(a[i].x);
		int fy=find(a[i].y);
		if(fx==fy) continue ;
		root[fx]=fy;
		addedge(a[i].x,a[i].y,a[i].z);
	}
}
void BFS(int now){
	q.push(now);
	vis[now]=1;
	d[now]=1;
	while(!q.empty()){
		now=q.front();
		q.pop();
		for(int i=last[now];i;i=next[i])
		if(!vis[to[i]]){
			q.push(to[i]);
			vis[to[i]]=1;
			d[to[i]]=d[now]+1;
			f[to[i]][0]=now;
			lim[to[i]][0]=w[i];
			for(int j=0;f[f[to[i]][j]][j];j++){
				f[to[i]][j+1]=f[f[to[i]][j]][j];
			    lim[to[i]][j+1]=std::min(lim[to[i]][j],lim[f[to[i]][j]][j]);
			}
		}
	}
}
int lca(int x,int y){
	if(d[y]>d[x]) std::swap(x,y);
	int ans=9999999;
	int t=d[x]-d[y],k=0;
	while(t){
		if(t&1){
			Min(ans,lim[x][k]);
			x=f[x][k];
		}
		t/=2;
		++k; 
	}
	k=0;
	while(x!=y){
		if(f[x][k]!=f[y][k]||(k==0&&f[x][k]==f[y][k])){
			Min(ans,lim[x][k]);
			Min(ans,lim[y][k]);
			x=f[x][k];
			y=f[y][k];
			++k;
		} --k;
	}
	return ans;
}
int main(){
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	kruskal();
    for(int i=1;i<=n;i++)
    	if(!vis[i])
    		BFS(i);
	scanf("%d",&Q);
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(find(x)!=find(y)) 
			printf("-1\n");
		else printf("%d\n",lca(x,y));
	}
	return 0;
}
