#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
#define lowbit(i) i&-i
int n,ans;
int h[100005];
int f[100005][25];
int pos[100005][25];
int bit[100005];

int check(int x,int y)
{
	if (x==y) return x;
	int log,t;
	for (log=0;x+(1 << log)-1<=y;++log);
	--log;
	if (x+(1<<log)-1==y) return pos[x][log];
	t=check(x+(1<<log),y);
	if (f[x][log]<h[t])
	{
		return pos[x][log];
	}
	else return t;
}

void add(int x,int y)
{
	while (x<=n)
	{
		bit[x]+=y;
		x+=lowbit(x);
	}
}

int ask(int x)
{
	int ret=0;
	while (x>0)
	{
		ret+=bit[x];
		x-=lowbit(x);
	}
	return ret;
}

void build(int l,int r)
{
	//cout << l << " " << r << endl;
	int t1=check(l,r);
	int t2=h[t1]-ask(t1);
	ans+=t2;
	add(l,t2);
	add(r+1,-t2);
	//cout << l << r << t1 << endl;
	if (l<=t1-1) build(l,t1-1);
	if (t1+1<=r) build(t1+1,r);
}

int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	int i,j;
	for (i=1;i<=n;++i) 
	{
		scanf("%d",&h[i]);
		f[i][0]=h[i];
		pos[i][0]=i;
	}
	for (j=1;(1<<j)<=n;++j)
	{
		for (i=1;i<=n;++i) 
		{
			if (i+(1<<j)-1>n) break;
			if (f[i][j-1]<f[i+(1<<(j-1))][j-1])
			{
				f[i][j]=f[i][j-1];
				pos[i][j]=pos[i][j-1];
			}
			else
			{
				f[i][j]=f[i+(1<<(j-1))][j-1];
				pos[i][j]=pos[i+(1<<(j-1))][j-1];
			}
		}
	}
	build(1,n);
	printf("%d\n",ans);
	return 0;
}

