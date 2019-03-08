#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define MAXN 100010
#define MAXH 4000010
using namespace std;
int t=0;
struct node
{
	int l,r,m;
};
node tf[MAXH]={},tg[MAXH]={};
int d[MAXN]={},f[MAXN]={},g[MAXN]={};
int build(int l, int r, int p)
{
	tf[p].l=l; tf[p].r=r; tf[p].m=0;
	tg[p].l=l; tg[p].r=r; tg[p].m=0;
	if (l==r) return 0;
	int mid=(l+r)/2;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	return 0;
}
int getf(int p, int l, int r)
{
	if (l>r) return 0;
	if ((tf[p].l==l)&&(tf[p].r==r)) return tf[p].m;
	int mid=(tf[p].l+tf[p].r)/2;
	if (r<=mid) return getf(p*2,l,r);
	if (l>mid) return getf(p*2+1,l,r);
	return max(getf(p*2,l,mid),getf(p*2+1,mid+1,r));
}
int getg(int p, int l, int r)
{
	if (l>r) return 0;
	if ((tg[p].l==l)&&(tg[p].r==r)) return tg[p].m;
	int mid=(tg[p].l+tg[p].r)/2;
	if (r<=mid) return getg(p*2,l,r);
	if (l>mid) return getg(p*2+1,l,r);
	return max(getg(p*2,l,mid),getg(p*2+1,mid+1,r));
}
int mtf(int p, int x, int a)
{
	if (tf[p].l==tf[p].r) {tf[p].m=max(tf[p].m,a); return tf[p].m;}
	int mid=(tf[p].l+tf[p].r)/2;
	if (x<=mid) tf[p].m=max(tf[p].m,mtf(p*2,x,a));
	if (x>mid) tf[p].m=max(tf[p].m,mtf(p*2+1,x,a));
	return tf[p].m;
}
int mtg(int p, int x, int a)
{
	if (tg[p].l==tg[p].r) {tg[p].m=max(tg[p].m,a); return tg[p].m;}
	int mid=(tg[p].l+tg[p].r)/2;
	if (x<=mid) tg[p].m=max(tg[p].m,mtg(p*2,x,a));
	if (x>mid) tg[p].m=max(tg[p].m,mtg(p*2+1,x,a));
	return tg[p].m;
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,ans=0;
	cin >> n;
	for (int i=1; i<=n; i++) {cin >> d[i]; t=max(t,d[i]);}
	build(0,t,1);
	for (int i=1; i<=n; i++)
	{
		f[i]=max(1,getg(1,0,d[i]-1)+1);
		g[i]=max(1,getf(1,d[i]+1,t)+1);
		mtf(1,d[i],f[i]);
		mtg(1,d[i],g[i]);
		ans=max(ans,f[i]);
		ans=max(ans,g[i]);
	}
	cout << ans << endl;
	return 0;
}
/*
5
5 3 2 1 2
*/
