#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
const int N=10010,M=50010,J=30,Inf=2000000001;

int n,m,fa[N];

struct Line{
	int a,b,v;
	bool operator <(const Line &l)const{
		return v>l.v;
	}
}li[M];

class Graph{
	int n,m;
	struct Line{
		int l,next,v;
		void New(int _l,int _next,int _v){l=_l,next=_next,v=_v;}
	}li[M*2];
	struct Point{
		int first,fa[J],l[J],deep;
	}po[N];
	void Dfs(int fa,int k){int i,j;
		po[k].fa[0]=fa;
//		printf("%d %d %d\n",fa,k,po[k].l[0]);
		for (i=1;po[k].fa[i-1] && i<J;i++){
			po[k].fa[i]=po[po[k].fa[i-1]].fa[i-1];
			po[k].l[i]=min(po[k].l[i-1],po[po[k].fa[i-1]].l[i-1]);
		//	printf("%d %d %d",k,i,po[k].l[i]);
		}
		for (i=po[k].first;i;i=li[i].next)
			if((j=li[i].l)!=fa)
				po[j].deep=po[k].deep+1,po[j].l[0]=li[i].v,Dfs(k,j);
	}
public:
	void Add(int a,int b,int v){
		li[++m].New(b,po[a].first,v),po[a].first=m;
		li[++m].New(a,po[b].first,v),po[b].first=m;
	}
	void Init(int _n){n=_n;
		for (int i=1;i<=n;i++){
			if (!po[i].fa[0])
				po[i].deep=1,po[i].l[0]=Inf,Dfs(0,i);
		}
	}
	int Get_ans(int a,int b){int i=J-1,ans=Inf;
		if (po[a].deep<po[b].deep) swap(a,b);
		while (!po[a].fa[i] && i) i--;
		while (po[a].deep!=po[b].deep){
			while (po[po[a].fa[i]].deep<po[b].deep) i--;
			ans=min(ans,po[a].l[i]);a=po[a].fa[i];
		}i=J-1;
		while (a!=b){
			while (po[a].fa[i]==po[b].fa[i] && i) i--;
			ans=min(ans,po[a].l[i]),ans=min(ans,po[b].l[i]);
			a=po[a].fa[i],b=po[b].fa[i];
		}
		return ans;
	}
}gh;

int Get_fa(int i){
	if (i!=fa[i]) fa[i]=Get_fa(fa[i]);
	return fa[i];
}

void Kul(){int i,a,b,f,fb;
	for (i=1;i<=m;i++){
		a=li[i].a,b=li[i].b;
		f=Get_fa(a),fb=Get_fa(b);
		if (f!=fb){
			fa[f]=fb;gh.Add(a,b,li[i].v);
		}
	}
}
int main(){int i,q,a,b;
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) fa[i]=i;
	for (i=1;i<=m;i++)
		scanf("%d%d%d",&li[i].a,&li[i].b,&li[i].v);
	sort(li+1,li+1+m);
	Kul();
	gh.Init(n);
	scanf("%d",&q);
	while (q--){
		scanf("%d%d",&a,&b);
		if (Get_fa(a)!=Get_fa(b)) printf("-1\n");
		else printf("%d\n",gh.Get_ans(a,b));
	}
	return 0;
}
