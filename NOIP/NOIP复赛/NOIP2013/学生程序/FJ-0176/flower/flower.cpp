#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N=100010,M=1000010;

class Ta{
	int n,c[M];
public:
	void Init(int _n){n=_n;}
	void Modify(int i,int a){
		for (;i<=n;i+=i&-i) c[i]=max(c[i],a);
	}
	int Max(int i){int mx=0;
		for (;i;i-=i&-i) mx=max(mx,c[i]);
		return mx;
	}
}t0,t1;

int n,f[N][2],ans;

int main(){
	int i,a;
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);t0.Init(M-1),t1.Init(M-1);
	for (i=1;i<=n;i++){
		scanf("%d",&a);
		f[i][0]=t1.Max(M-a-2)+1;
		f[i][1]=t0.Max(a+1)+1;
		t1.Modify(M-a-1,f[i][1]);
		t0.Modify(a+2,f[i][0]);
		ans=max(ans,max(f[i][0],f[i][1]));
	}
	printf("%d\n",ans);
	return 0;
}
