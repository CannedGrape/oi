#include <cstdio>
#include <algorithm>
using namespace std;
const int N=10001,M=50001,INF=1000000000;
struct inli{
	int x,y,z;
	inli(const int a=0,const int b=0,const int c=0):
		x(a),y(b),z(c){}
}line[M];
struct inli2{
	int next,data,lon;
	inli2(const int a=0,const int b=0,const int c=0):
		next(a),data(b),lon(c){}
}line2[N*2];
int n,m,q,bo[N],son[N],nl,fat[N],fatt[N][20],maxx[N][20],deep[N];
inline bool cmp(inli a,inli b){ return a.z>b.z; }
int getfat(int t){ return fat[t] ? fat[t]=getfat(fat[t]) : t; }
inline int min(int x,int y){ return x<y ? x : y; }
void makeline2(){
	sort(line+1,line+m+1,cmp);
	for (int i=1;i<=m;i++){
		int x=line[i].x,y=line[i].y,lon=line[i].z;
		int fx=getfat(x),fy=getfat(y);
		if (fx==fy) continue;
		fat[fx]=fy;
		line2[++nl]=inli2(son[x],y,lon),son[x]=nl;
		line2[++nl]=inli2(son[y],x,lon),son[y]=nl;
	}
}
void dfs(int t){
	bo[t]=1;
	for (int i=1;fatt[fatt[t][i-1]][i-1];i++){
		fatt[t][i]=fatt[fatt[t][i-1]][i-1];
		maxx[t][i]=min(maxx[t][i-1],maxx[fatt[t][i-1]][i-1]);
	}
	for (int i=son[t];i;i=line2[i].next)
	if (!bo[line2[i].data]){
		int ne=line2[i].data;
		fatt[ne][0]=t;
		maxx[ne][0]=line2[i].lon;
		deep[ne]=deep[t]+1;
		dfs(ne);
	}
}
void makefatt(){
	for (int i=1;i<=n;i++)
	if (!bo[i]){
		deep[i]=1;
		dfs(i);
	}
}
int getans(int x,int y){
	if (x==y) return INF;
	if (deep[x]<deep[y]) swap(x,y);
	if (deep[x]!=deep[y]){
		int i=0;
		for (;deep[fatt[x][i]]>=deep[y];++i);
		--i;
		return min(maxx[x][i],getans(fatt[x][i],y));
	}
	if (fatt[x][0]==fatt[y][0]) return min(maxx[x][0],maxx[y][0]);
	int i=0;
	for (;fatt[x][i]!=fatt[y][i];++i);
	--i;
	return min(min(maxx[x][i],maxx[y][i]),getans(fatt[x][i],fatt[y][i]));
}
int main(){
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y,z;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		line[i]=inli(x,y,z);
	}
	makeline2();
	makefatt();
	scanf("%d",&q);
	for (int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		int fx=getfat(x),fy=getfat(y);
		if (fx!=fy) puts("-1");
		else printf("%d\n",getans(x,y));
	}
	fclose(stdin);
	fclose(stdout);
}
