#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define down(i,b,a) for(int i=(b);i>=(a);i--)
#define fe(e,x) for(edge *e = (x)->first;e;e = e->next)
#define mk(a,b) make_pair((a),(b))
const int maxn = 50000,maxlog = 15,geps = 1,inf = 0x3fffffff;//NeedChange
struct point;struct edge;
struct point{
	point():first(0),vst(false),order(0){rep(i,0,maxlog) p[i] = 0,path[i] = 0;}
	edge *first;
	point *p[maxlog+geps];ll path[maxlog+geps];
	bool vst;int order;
	void getfather(){
		rep(i,1,maxlog-1) if(p[i-1]) p[i] = p[i-1]->p[i-1],path[i] = path[i-1] + p[i-1]->path[i-1];
	}
}points[maxn+geps];
struct edge{
	edge *next;
	point *to;
	int w;
}edges[maxn*2+geps];int edgenum = 0;
void addedge(int _x,int _y,int w){
	point *x = points+_x,*y = points+_y;edge *e = edges+(edgenum++);
	e->w = w,e->to = y,e->next = x->first,x->first = e;
}
void getvst(point *x){
	if(x->vst) return;
	x->vst = true;bool flag = false;
	fe(e,x) if(e->to->p[0] == x) x->vst &= e->to->vst,flag = true;
	x->vst &= flag;
}
struct army{
	point *start;
	point *ed;
	ll artime;
}armies[maxn+geps];
bool timecmp(army* a,army *b){return a->artime<b->artime||(a->artime==b->artime && a->start->order>b->start->order);}
int n,m;ll totedge = 0;
point *myque[maxn+geps];
point *nb[maxn+geps];int cnb = 0;
int self[maxn+geps];
bool pathcmp(point *x,point *y){return x->path[0] < y->path[0];}
void bfs(){
	int qhead = 1,qtail = 0;
	myque[++qtail] = points+1;points[1].vst = true;
	while(qhead<=qtail){
		point *now = myque[qhead++];now->getfather();
		fe(e,now) if(!e->to->vst)
			myque[++qtail] = e->to,e->to->p[0] = now,e->to->path[0] = e->w,e->to->vst = true;
	}point *fp = myque[1];
	fe(e,fp) nb[++cnb] = e->to;
	sort(nb+1,nb+cnb+1,pathcmp);
	rep(i,1,cnb) nb[i]->order = i;
	rep(i,2,n){
		point *now = myque[i];
		fe(e,now) if(e->to->p[0] == now) e->to->order = now->order;
	}
}
void Init(){
	scanf("%d",&n);
	int x,y,w;
	rep(i,1,n-1){
		scanf("%d%d%d",&x,&y,&w);totedge += w;
		addedge(x,y,w),addedge(y,x,w);
	}scanf("%d",&m);
	rep(i,1,m){
		scanf("%d",&x);
		armies[i].start = points+x;
	}bfs();
}
ll climb(point *st,ll tot,point *&ed){
	ll ret = 0;
	down(i,maxlog,0) if(st->p[i] && ret + st->path[i] <= tot)
		ret += st->path[i],st = st->p[i];
	ed = st;return ret;
}
army *arrive[maxn+geps];
bool check(ll tottime){
	rep(i,1,n) points[i].vst = false;
	rep(i,1,m){
		armies[i].artime = climb(armies[i].start,tottime,armies[i].ed);
		if(armies[i].ed != myque[1])
			armies[i].ed->vst = true;
	}
	down(i,n,1) getvst(myque[i]);
	if(myque[1]->vst) return true;
	int artop = 0;
	rep(i,1,cnb) self[i] = 0;
	rep(i,1,m) if(armies[i].ed == myque[1])
		arrive[++artop] = armies+i;
	sort(arrive+1,arrive+artop+1,timecmp);
	rep(i,1,cnb) if(!nb[i]->vst){
		if(artop < self[i])
			continue;
		while(artop>0 && arrive[artop]->start->order!=i && arrive[artop]->artime+nb[i]->path[0] > tottime)
			self[arrive[artop--]->start->order] = i;
		if(!artop) return false;
		else artop--;
	}return true;
}
void solve(){
	ll l = 0,r = totedge;
	for(ll mid = (l+r)>>1;l<=r;mid = (l+r)>>1)
		check(mid)?r=mid-1:l=mid+1;
	printf("%lld\n",l);
}
int main(){
	freopen("blockade.in","r",stdin);
	freopen("blockade.out","w",stdout);

	Init();
	solve();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
