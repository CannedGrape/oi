#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <set>
#include <string>
#include <cstring>
#include <string.h>
#include <map>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define down(i,b,a) for(int i=(b);i>=(a);i--)
#define fe(e,x) for(edge *e = (x)->first;e;e = e->next)
#define mk(a,b) make_pair((a),(b))
typedef long long ll;typedef map<ll,int> MAP;typedef MAP::iterator it;
const int maxn = 100000,maxlog = 17,geps = 10,inf = 0x3fffffff;//Need Change
struct node{
	node(){memset(p,0,sizeof p);memset(Adist,0,sizeof Adist),memset(Bdist,0,sizeof Bdist);}
	node *p[maxlog];
	ll Adist[maxlog],Bdist[maxlog];
	int col;
	void getfather(){
		for(int i = 1;i<maxlog && p[i-1];i++)
			p[i] = p[i-1]->p[i-1],Adist[i] = Adist[i-1] + p[i-1]->Adist[i-1],Bdist[i] = Bdist[i-1] + p[i-1]->Bdist[i-1];
	}
}Anodes[maxn+geps],Bnodes[maxn+geps];
int n;ll h[maxn+geps];
MAP f;
inline ll myabs(ll x){
	return x<0?-x:x;
}
pair<int,int> near[4];
void getnearby(int i,int &a,int &b){
	rep(j,0,3) near[j] = mk(inf,-inf);
	it out = f.upper_bound(h[i]);int top = 0;
	it sav = out;
	for(int j=1;j<=2 && out!=f.end();j++) near[top++] = mk(myabs(h[i]-out->first),out->first),out++;
	out = sav,out--;
	for(int j=1;j<=2 && out!=f.begin();j++) near[top++] = mk(myabs(h[i]-out->first),out->first),out--;
	sort(near,near+4);
	b = f[near[0].second],a = f[near[1].second];
}
void Init(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%lld",h+i);
	f[-inf] = 0;
	down(i,n,1){
		 int a,b;
		 getnearby(i,a,b);
		 if(a!=0) Anodes[i].p[0] = Bnodes+a,Anodes[i].Adist[0] = myabs(h[i]-h[a]);
		 if(b!=0) Bnodes[i].p[0] = Anodes+b,Bnodes[i].Bdist[0] = myabs(h[i]-h[b]);
		 f[h[i]] = i;
		Anodes[i].getfather();Bnodes[i].getfather();
	}
}
void calclen(int i,ll x,ll &Alen,ll &Blen){
	node *now = Anodes+i;Alen = Blen = 0;
	for(int j = maxlog-1;j>=0;j--) if(now->p[j] && Alen+Blen+now->Adist[j]+now->Bdist[j] <= x){
		Alen += now->Adist[j],Blen += now->Bdist[j];now = now->p[j];
	}
}
void solve(){
	int s;ll x;
	scanf("%lld",&x);
	ll up = inf,down = 1,nowh = -inf,Alen,Blen;int nowans = 0;
	rep(i,1,n){
		calclen(i,x,Alen,Blen);
		if(Blen == 0) Alen = inf,Blen = 1;
		if(Alen*down-Blen*up<0 || (Alen*down-Blen*up==0 && h[i] > nowh)) up = Alen,down = Blen,nowh = h[i],nowans = i;
	}printf("%d\n",nowans);
	int m;scanf("%d",&m);
	rep(i,1,m){
		scanf("%d%lld",&s,&x);
		calclen(s,x,Alen,Blen);
		printf("%lld %lld\n",Alen,Blen);
	}
}
int main(){
	freopen("drive.in","r",stdin);
	freopen("drive.out","w",stdout);
	
	Init();
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


