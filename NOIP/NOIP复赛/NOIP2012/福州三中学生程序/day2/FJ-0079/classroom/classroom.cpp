#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <cstring>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define down(i,b,a) for(int i=(b);i>=(a);i--)
#define fe(e,x) for(edge *e = (x)->first;e;e = e->next)
#define mk(a,b) make_pair((a),(b))
const int maxh = 20,maxm = 1<<maxh,maxn = 1000000,geps = 1,inf = 0x3fffffff;
struct linetree{
	int zkw[maxm<<1],delta[maxm<<1];
	void init(){
		rep(i,1,(maxm<<1)-1) zkw[i] = inf;
		memset(delta,0,sizeof delta);
	}void pushpoint(int ind,int x){
		for(ind+=maxm;ind;ind>>=1) zkw[ind] = min(zkw[ind],x);
	}void update(int ind){zkw[ind] = min(zkw[ind+ind],zkw[ind+ind+1]) + delta[ind];}
	void pushinterval(int l,int r,int x){
		for(l+=maxm-1,r+=maxm+1;l^r^1;l>>=1,r>>=1){
			if(~l&1) delta[l^1] += x,zkw[l^1] += x;
			if(r&1) delta[r^1] += x,zkw[r^1] += x;
			update(l>>1),update(r>>1);
		}for(l>>=1;l;l>>=1) update(l);
	}int getmin(int l,int r){
		int lmin = inf,rmin = inf;
		for(l+=maxm-1,r+=maxm+1;l^r^1;l>>=1,r>>=1){
			if(~l&1) lmin = min(lmin,zkw[l^1]);
			if(r&1) rmin = min(rmin,zkw[r^1]);
			lmin += delta[l>>1],rmin += delta[r>>1];
		}for(lmin = min(lmin,rmin),l>>=1;l;l>>=1) lmin += delta[l];
		return lmin;
	}
}T;
int n,m;
void Init(){
	scanf("%d%d",&n,&m);
	int d;T.init();
	rep(i,1,n){
		scanf("%d",&d);
		T.pushpoint(i,d);
	}
}
void solve(){
	int d,s,t;
	rep(i,1,m){
		scanf("%d%d%d",&d,&s,&t);
		int minclass = T.getmin(s,t);
		if(minclass < d){
			printf("-1\n%d\n",i);
			return;
		}T.pushinterval(s,t,-d);
	}printf("0\n");
}
int main(){
	freopen("classroom.in","r",stdin);
	freopen("classroom.out","w",stdout);

	Init();
	solve();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
