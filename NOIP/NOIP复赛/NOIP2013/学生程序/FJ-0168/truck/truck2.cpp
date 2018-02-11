#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
int get()
{
	int f=0,v=0;char ch;
	while(!isdigit(ch=getchar()))if(ch=='-')break;
	if(ch=='-')f=1;else v=ch-'0';
	while(isdigit(ch=getchar()))v=v*10+ch-'0';
	if(f==1)return -v;else return v;
}
const int maxn=10003,maxm=100003;
int n,m,Link[maxn],pre[maxm],t[maxm],v[maxm],s[maxn];
bool vis[maxn];

bool check(int x,int y,int lim)
{
	int front=0,rear=1;
	memset(vis,0,sizeof(vis));
	s[front]=x;vis[x]=1;
	while(front!=rear)
	{
		int p=s[front];
		for(int i=Link[p];i;i=pre[i])
			if(v[i]>=lim&&!vis[t[i]])vis[t[i]]=1,s[rear++]=t[i];
		front++;
	}
	return vis[y];
}

int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck2.out","w",stdout);
	n=get(),m=get();
	for(int i=1,tot=0;i<=m;i++)
	{
		int x=get(),y=get(),z=get();
		pre[++tot]=Link[x]; Link[x]=tot; t[tot]=y; v[tot]=z;
		pre[++tot]=Link[y]; Link[y]=tot; t[tot]=x; v[tot]=z;
	}
	int Q=get();
	while(Q--)
	{
		int x=get(),y=get();
		int l=-1,r=200000;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(check(x,y,mid))l=mid;else r=mid-1;
		}
		if(l>100000||l<0)puts("-1");else printf("%d\n",l);
	}
	return 0;
}
