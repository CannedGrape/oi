#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=10010,maxm=50020,inf=2111111111;
struct Edge{
    int x,y,l;
    Edge(int _x=0,int _y=0,int _l=0){x=_x,y=_y,l=_l;}
    bool operator <(const Edge&rhs) const{
	    return l>rhs.l;
	} 
}E[maxm];
struct Dot{
    int t,v;
};
int fst[maxn],lin[maxm*3],next[maxm*3],tot,cost[maxm*3];
int n,m,q,fa[maxn];
bool vis[maxn],use[maxn];

int get(){
    int f=0,v=0; char ch;
    while (!isdigit(ch=getchar())) if (ch=='-') break;
    if (ch=='-') f=1; else v=ch-48;
    while (isdigit(ch=getchar())) v=v*10+ch-48;
    if (f) return -v; else return v;
}
int getfa(int x){
    if (x!=fa[x]) fa[x]=getfa(fa[x]);
    return fa[x];
}
void add(int x,int y,int c){
    next[++tot]=fst[x]; lin[tot]=y; fst[x]=tot; cost[tot]=c;
}
void init(){
    n=get(); m=get();
    for (int i=1;i<=m;i++){
	    int a=get(),b=get(),c=get();
	    E[i]=Edge(a,b,c);
	}
	sort(E+1,E+1+m);
	for (int i=1;i<=n;i++) fa[i]=i;
	int sum=n;
	for (int i=1;i<=m;i++){
	    int fx=getfa(E[i].x),fy=getfa(E[i].y);
	    if (fx!=fy){
		    fa[fx]=fy;
		    use[E[i].x]=1; use[E[i].y]=1;
		    add(E[i].x,E[i].y,E[i].l);
		    add(E[i].y,E[i].x,E[i].l);
		    sum--;
		}
		if (sum==1) break;
	}
}
queue<Dot>Q;
void work(){
    q=get();
    for (int i=1;i<=q;i++){
	    int a=get(),b=get();
	    if (use[a]==0||use[b]==0){printf("-1\n");continue;}
	    int cnt=0,ans=0;
	    for (int i=1;i<=n;i++) vis[i]=0;
	    Q.push((Dot){a,inf});
	    while (!Q.empty()){
		    Dot u=Q.front(); Q.pop(); cnt++;
		    for (int i=fst[u.t];i;i=next[i]){
			    int v=lin[i];
			    if (v==b){
					ans=min(u.v,cost[i]);
				    while (!Q.empty()) Q.pop();
				    break;
				}
				if (!vis[v]){
					vis[v]=1;
				    Q.push((Dot){v,min(cost[i],u.v)});
				}
			}
		}
		if (cnt>1){add(a,b,ans); add(b,a,ans);}
		printf("%d\n",ans);
	}
}
int main(){
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout); 
    init();
    work();
    return 0;
}
