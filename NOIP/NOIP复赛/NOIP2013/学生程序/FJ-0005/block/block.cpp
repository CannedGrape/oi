#include<cstdio>
#include<algorithm>

struct my_node{
	int l,r,h;
	my_node(int l=0,int r=0,int h=0):l(l),r(r),h(h){}
} q[100005];

struct my_rmq{
	int x,p;
	my_rmq(int x=0,int p=0):x(x),p(p){}
	
	bool operator <(const my_rmq &rsh)const{
		return x<rsh.x;
	}
} f[100005][18];

int n,qh,qt,h2s[100005];
long long ans;
int main(){
	freopen("block.in","r",stdin),freopen("block.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i) scanf("%d",&x),f[i][0]=my_rmq(x,i);
	for(int d=1;1<<d<=n;++d)
		for(int i=1;i+(1<<d)-1<=n;++i) f[i][d]=std::min(f[i][d-1],f[i+(1<<d-1)][d-1]);
	for(int d=0,i=1;i<=n;++i) h2s[i]=i&(1<<d)?d:++d;
	for(q[qh=qt=1]=my_node(1,n,0);qh<=qt;++qh){
		my_node u=q[qh];
		my_rmq t=std::min(f[u.l][h2s[u.r-u.l+1]],f[u.r-(1<<h2s[u.r-u.l+1])+1][h2s[u.r-u.l+1]]);
		ans+=t.x-u.h;
		if (u.l<t.p) q[++qt]=my_node(u.l,t.p-1,t.x);
		if (t.p<u.r) q[++qt]=my_node(t.p+1,u.r,t.x);
	}
	printf("%lld\n",ans);
	return 0;	
}
