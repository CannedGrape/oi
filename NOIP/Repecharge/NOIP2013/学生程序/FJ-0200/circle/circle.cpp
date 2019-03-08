#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
int n,m,K,X;
LL POW(LL x,int b,int mod)
{
  LL res=1;
  while (b)
  {
	if (b&1) res=res%LL(mod)*LL(x)%mod;
	x=LL(x)%LL(mod)*x%mod;
	b/=2;
  }
  return res;
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&K,&X);
	LL a=LL(m)%LL(n)*POW(LL(10),K,n)%LL(n);
	a=(a+X)%n;
	cout<<a<<endl;
	return 0;
}

