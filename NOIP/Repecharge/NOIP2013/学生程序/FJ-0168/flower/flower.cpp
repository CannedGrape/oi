#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
int get()
{
	int f=0,v=0;char ch;
	while(!isdigit(ch=getchar()))if(ch=='-')break;
	if(ch=='-')f=1;else v=ch-'0';
	while(isdigit(ch=getchar()))v=v*10+ch-'0';
	if(f==1)return -v;else return v;
}
const int maxn=100003,maxv=1000010;
int f[maxn],g[maxn],c1[maxv],c2[maxv],n,a[maxn],lim;

int ask1(int x)
{
	int res=0;
	for(;x;x-=x&-x)res=max(res,c1[x]);
	return res;
}
int ask2(int x)
{
	int res=0;
	for(x=lim-x+1;x;x-=x&-x)res=max(res,c2[x]);
	return res;
}
void add1(int x,int v)
{
	for(;x<=lim;x+=x&-x)c1[x]=max(c1[x],v);
}
void add2(int x,int v)
{
	for(x=lim-x+1;x<=lim;x+=x&-x)c2[x]=max(c2[x],v);
}

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]++,lim=max(a[i],lim);
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=ask1(a[i]-1)+1;
		g[i]=ask2(a[i]+1)+1;
		ans=max(ans,max(f[i],g[i]));
		add2(a[i],f[i]);add1(a[i],g[i]);
	}
	printf("%d\n",ans);
	return 0;
}
