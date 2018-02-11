#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int inf=1000005;
const int maxn=100000;
int n,ans,h[maxn],f[maxn][2],tr1[inf],tr2[inf];
void add1(int k,int t)
{
	for (;k<=inf;k+=k&-k) tr1[k]=max(tr1[k],t);
}
void add2(int k,int t)
{
	for (;k<=inf;k+=k&-k) tr2[k]=max(tr2[k],t);
}
int getmax1(int k)
{
	int ans=-1;
	for (;k;k-=k&-k) ans=max(ans,tr1[k]);
	return ans;
}
int getmax2(int k)
{
	int ans=0;
	for (;k;k-=k&-k) ans=max(ans,tr2[k]);
	return ans;
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&h[i]),h[i]++;
	memset(tr1,-1,sizeof(tr1)); memset(tr2,-1,sizeof(tr2)); memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		f[i][0]=getmax1(h[i]-1)+1; f[i][1]=getmax2(inf-h[i])+1;
		add1(h[i],f[i][1]); add2(inf-h[i]+1,f[i][0]); ans=max(max(f[i][0],f[i][1]),ans);
	}
	memset(tr1,-1,sizeof(tr1)); memset(tr2,-1,sizeof(tr2)); memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		f[i][0]=getmax1(inf-h[i])+1; f[i][1]=getmax2(h[i]-1)+1;
		add1(inf-h[i]+1,f[i][1]); add2(h[i],f[i][0]); ans=max(max(f[i][0],f[i][1]),ans);
	}
	printf("%d\n",ans);
	return 0;
}

