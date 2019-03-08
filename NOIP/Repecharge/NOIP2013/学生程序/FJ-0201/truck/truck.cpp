#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
#define F(i,j,k) for(int i=j;i<=k;i++)

inline int fastread(){
	int ans=0;
	char c;
	c=getchar();
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') {
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
int n,m;
int fa[10050];
int fa1[10050];
int find(int x){
	return fa[x]==x?x:find(fa[x]);
}
int find1(int x){
	return fa1[x]==x?x:find(fa1[x]);
}
struct edge{
	int t,w,next;
};
struct sedge{
	int t,f,w;
};
edge e[20050];
sedge se[500050];
int h[10050],tot,tot1;
void input(){
	tot=0;
	cin>>n>>m;
	F(i,1,n){
		fa[i]=i;
	}
	F(i,1,m){
		int f,t,w;
		f=fastread();
		t=fastread();
		w=fastread();
		tot++;
		se[tot].f=f;
		se[tot].t=t;
		se[tot].w=w;
		int p,q;
		q=find(f);
		p=find(t);
		if (q!=p){
			fa[p]=q;
		}
	}
}
bool b[1005];
bool cmp(sedge x,sedge y){
	return x.w>y.w;
} 
void work(){
	memset(h,-1,sizeof(h));
	int n1=0;
	F(i,1,n){
		if (fa[i]==i) n1++;
	}
	F(i,1,n){
		fa1[i]=i;
	}
	sort(se+1,se+tot+1,cmp);
	tot1=0;
	int k=0;
	F(i,1,tot){
		int p=find1(se[i].f);
		int q=find1(se[i].t);
		if (q!=p){
			fa1[p]=q;
			tot1++;
			e[tot1].next=h[se[i].f];
			e[tot1].w=se[i].w;
			e[tot1].t=se[i].t;
			h[se[i].f]=tot1;
			tot1++;
			e[tot1].next=h[se[i].t];
			e[tot1].w=se[i].w;
			e[tot1].t=se[i].f;
			h[se[i].t]=tot1;
			k++;
			if (k>=n-n1){
				break;
			}
		}
	}
}
int dfs(int u,int y){
	b[u]=1;
	if (u==y){
		return 0;
	}
	for (int i=h[u];i!=-1;i=e[i].next){
		if (b[e[i].t]) continue;
		int k=dfs(e[i].t,y);
		if (k<2000000000){
			return (k<e[i].w && k!=0)?k:e[i].w;
		}
	}
	return 2000000050;
}
int main(){
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	input();
	work();
	int p;
	cin>>p;
	while (p--){
		int x,y;
		x=fastread();
		y=fastread();
		if (find(x)!=find(y)) printf("-1\n");
		else{
			memset(b,0,sizeof(b));
			printf("%d\n",dfs(x,y));
		} 
	}
	return 0;
}
