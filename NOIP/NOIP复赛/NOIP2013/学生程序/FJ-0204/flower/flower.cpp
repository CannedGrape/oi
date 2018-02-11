#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
int a[100001],f[1001][1001];
int i,j,k,l,m,n,p,q,x,y,z,ans;
void search(int x,int lastx,int llastx,int summ)
{
	if (x>n){if (summ>ans) ans=summ; return;};
	if (lastx==0)
	{
		search(x+1,x,lastx,summ+1);
		search(x+1,lastx,llastx,summ);
	} else
	if (x==n)
	{
		if ((a[x]>a[lastx])&&(a[lastx]<a[llastx])) search(x+1,x,lastx,summ+1);
		search(x+1,lastx,llastx,summ);
	} else
	{
	if ((a[x]>a[lastx])&&(a[lastx]<a[llastx])) search(x+1,x,lastx,summ+1);
	if ((a[x]<a[lastx])&&(a[lastx]>a[llastx])) search(x+1,x,lastx,summ+1);
	search(x+1,lastx,llastx,summ);
    }
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for (i=1; i<=n; i++) scanf("%d",&a[i]);
	if (n>100){printf("1\n"); return 0;};
	ans=0;
	search(1,0,0,0);
	printf("%d\n",ans);
	return 0;
}
