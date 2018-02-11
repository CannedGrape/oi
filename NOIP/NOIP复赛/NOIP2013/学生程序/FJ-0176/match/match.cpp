#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#define LL long long
using namespace std;
const int N=100010,Mod=99999997;

class TA{
	int n,c[N];
public:
	void Init(int _n){n=_n;}
	void Add(int i){
		for (;i<=n;i+=i&-i) c[i]++;
	}
	int Sum(int i){int sum=0;
		for (;i;i-=i&-i) sum+=c[i];
		return sum;
	}
}ta;

struct Data{
	int a,i;
	bool operator <(const Data &d)const{
		return a<d.a;
	}
}d1[N],d2[N];

int n,f[N],t;LL ans;

int main(){int i;
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);ta.Init(n);
	for (i=1;i<=n;i++) scanf("%d",&d1[i].a),d1[i].i=i;
	for (i=1;i<=n;i++) scanf("%d",&d2[i].a),d2[i].i=i;
	sort(d1+1,d1+1+n);sort(d2+1,d2+1+n);
	for(i=1;i<=n;i++) f[d2[i].i]=d1[i].i;
	for (i=1;i<=n;i++){
		ans+=(LL)(i-ta.Sum(f[i])-1);
		ta.Add(f[i]);
	}ans%=Mod;t=(int)ans;
	printf("%d\n",t);
	return 0;
}
