#include<cstdio>
#include<algorithm>
#define MaxN 100000
#define Mod 99999997

struct my_node{
	int x,p;
	my_node(int x=0,int p=0):x(x),p(p){}
	
	bool operator <(const my_node &rsh)const{
		return x<rsh.x;
	}
} a[MaxN+5],b[MaxN+5];

int n,ans;
int main(){
	freopen("match.in","r",stdin),freopen("match.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i) scanf("%d",&x),a[i]=my_node(x,i);
	for(int i=1,x;i<=n;++i) scanf("%d",&x),b[i]=my_node(x,i);
	std::sort(a+1,a+n+1),std::sort(b+1,b+n+1); 
	for(int i=1;i<=n;++i) ans=(ans+std::abs(a[i].p-b[i].p))%Mod;
	printf("%d\n",ans>>1);
	return 0;
}
