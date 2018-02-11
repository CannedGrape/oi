#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
const int Maxn=100002;
int n,h[Maxn],pos[Maxn],L=0;
int f[Maxn][2];
int C0[Maxn],C1[Maxn];
bool cmp(int a,int b) {return h[a]<h[b];}
int get()
{
	int f=0,v=0;char ch;
	while (!isdigit(ch=getchar())) if (ch=='-') break;
	if (ch=='-') f=1;else v=ch-48;
	while (isdigit(ch=getchar())) v=v*10+ch-48;
	if (f) return -v;else return v;
}
void modify0(int x,int a)
{
	x=L-x+1;
	for (;x<=L;x+=x&-x) if (C0[x]<a) C0[x]=a;
}
void modify1(int x,int a)
{
	for (;x<=L;x+=x&-x) if (C1[x]<a) C1[x]=a;
}
int getmax0(int x)
{
	x=L-x+1;int ans=0;
	for (;x;x-=x&-x) if (ans<C0[x]) ans=C0[x];return ans;
}
int getmax1(int x)
{
	int ans=0;
	for (;x;x-=x&-x) if (ans<C1[x]) ans=C1[x];return ans;
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	n=get();
	for (int i=1;i<=n;i++) h[i]=get(),pos[i]=i;
	sort(pos+1,pos+n+1,cmp);
	int temp=h[pos[1]];h[pos[1]]=++L;
	for (int i=2;i<=n;i++) 
	{
		if (h[pos[i]]!=temp) temp=h[pos[i]],L++;
		h[pos[i]]=L;
	}
	int ans=0;
	for (int i=n;i>=1;i--)
	{
		f[i][0]=getmax0(h[i]+1)+1;
		f[i][1]=getmax1(h[i]-1)+1;
		modify0(h[i],f[i][1]);
		modify1(h[i],f[i][0]);
		if (ans<f[i][0]) ans=f[i][0];
		if (ans<f[i][1]) ans=f[i][1];
	}
	printf("%d\n",ans);
	return 0;
}
