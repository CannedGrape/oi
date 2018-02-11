#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=2147483647;
const int maxn=100007;
int n,m,i,j,q,tmp1,tmp2,tot,X,Y;
int x[maxn],y[maxn],z[maxn],fa[maxn],first[maxn],to[maxn],next[maxn],value[maxn],vis[maxn];
int f[maxn][30],minv[maxn][30],d[maxn];
struct edge{
	int x,y,z;
	bool operator<(const edge &X)const{
	  return z<X.z;	
	}
}a[maxn];
void add(int x,int y,int z){
	next[++tot]=first[x]; first[x]=tot; to[tot]=y; value[tot]=z;
}
int findpa(int x){
	return fa[x]==x?x:fa[x]=findpa(fa[x]);
}
int min(int a,int b){
	return a<b?a:b;
}
void dfs(int x){
	vis[x]=1;
	for(int i=first[x];i;i=next[i])
	if(!vis[to[i]]){
		f[to[i]][0]=x;
		minv[to[i]][0]=value[i];
		d[to[i]]=d[x]+1;
		dfs(to[i]);
	}
}
int query(int x,int y){
	int t,i,ans=INF;
	if(d[x]<d[y]){t=x; x=y; y=t;}
	for(i=25;i>=0;i--)
	  if(d[x]-(1<<i)>=d[y]){
			ans=min(ans,minv[x][i]);
			x=f[x][i];
	  }
	if(x==y)return ans;
	for(i=25;i>=0;i--)
	  if(f[x][i]!=-1&&f[x][i]!=f[y][i]){
			ans=min(ans,minv[x][i]);
			ans=min(ans,minv[y][i]);
			x=f[x][i]; y=f[y][i];
	  }
	ans=min(ans,minv[x][0]);
	ans=min(ans,minv[y][0]);
	return ans;
}
int main(){
  freopen("truck.in","r",stdin);
  freopen("truck.out","w",stdout);
  cin>>n>>m;
  for(i=1;i<=m;i++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		a[i].x=x[i]; a[i].y=y[i]; a[i].z=z[i];
  }
  for(i=1;i<=n;i++)fa[i]=i;
  sort(a+1,a+m+1);
  for(i=m;i>=1;i--){
		if((tmp1=findpa(a[i].x))!=(tmp2=findpa(a[i].y))){
			add(a[i].x,a[i].y,a[i].z);
			add(a[i].y,a[i].x,a[i].z);
			fa[tmp1]=tmp2;
		}
  }
  memset(f,-1,sizeof(f));
  for(i=1;i<=n;i++)if(!vis[i])dfs(i);
  for(j=1;j<=25;j++)
  for(i=1;i<=n;i++){
		if(f[i][j-1]==-1)continue;
		f[i][j]=f[f[i][j-1]][j-1];
		minv[i][j]=min(minv[i][j-1],minv[f[i][j-1]][j-1]);
  }
  cin>>q;
  for(i=1;i<=q;i++){
		scanf("%d%d",&X,&Y);
		if(findpa(X)!=findpa(Y)){printf("-1\n");continue;}
		printf("%d\n",query(X,Y));
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}

