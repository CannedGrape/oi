#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <deque>
#include <ctime>
using namespace std;
typedef long long LL;
const int Maxn=100010;
int N,M,maxx,flag[Maxn],cnt=0;
int next[Maxn],first[Maxn],toward[Maxn],Len[Maxn],tot=0;

int Get()
{
	int f=0,v=0; char ch;
	while (!isdigit(ch=getchar())) if (ch=='-') break;
	if (ch=='-') f=1; else v=ch-48;
	while (isdigit(ch=getchar())) v=v*10+ch-48;
	if (f==1) return -v; else return v;
}

void addlink(int x,int y,int z)
{
	next[++tot]=first[x]; first[x]=tot; toward[tot]=y; Len[tot]=z;
	next[++tot]=first[y]; first[y]=tot; toward[tot]=x; Len[tot]=z;
}

void init()
{
	N=Get(); M=Get();
	maxx=0; int a,b,c;
	for (int i=1;i<=M;i++) a=Get(),b=Get(),c=Get(),maxx=max(c,maxx),addlink(a,b,c);
}

bool check(int x,int S,int T)
{
	deque<int> Q; Q.push_front(S); flag[S]=cnt;
	while (!Q.empty())
	{
		int u=Q.front(); Q.pop_front();
		for (int p=first[u];p;p=next[p])
		{
			if (Len[p]<x) continue;
			int v=toward[p];
			if (flag[v]!=cnt) flag[v]=cnt,Q.push_back(v);
			if (v==T) return 1;
		}	
	}
	return 0;
}

void erfen(int a,int b)
{
	int l=-1,r=maxx;
	while (l<r)
	{
		cnt++;
		int mid=(l+r+1)>>1;
		if (check(mid,a,b)) l=mid;
		else r=mid-1;
	}	
	printf("%d\n",l);
}

void work()
{
	int Q=Get(),a,b;
	while (Q--)
	{
		a=Get();b=Get();
		erfen(a,b);	
	}	
}

int main()
{
	freopen("truck.in","r",stdin); freopen("truck.out","w",stdout);
	init();
	work();
	return 0;
}
