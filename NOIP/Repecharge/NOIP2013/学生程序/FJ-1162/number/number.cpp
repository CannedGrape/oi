#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int n,p;
int a[100002];
int f[100002];
int pp[100002];
int maxn=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[1]=a[1];
	for (int i=2;i<=n;i++) f[i]=max(a[i],a[i]+f[i-1]);
	pp[1]=f[1],pp[2]=pp[1]+f[1];
	maxn=max(pp[1]+f[1],pp[2]+f[2]);
	for (int i=3;i<=n;i++) pp[i]=maxn,maxn=max(maxn,pp[i]+f[i]);
	printf("%d\n",pp[n]%p);
	return 0;
}
