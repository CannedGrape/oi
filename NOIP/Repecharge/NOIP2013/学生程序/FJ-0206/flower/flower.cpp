#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <ctime>
using namespace std;
const int Maxn=100010,Inf=99999999;
int N,A[Maxn],f[Maxn],g[Maxn];
int cnt;

struct Tnode
{
	int num,pos;
 	bool operator<(const Tnode &rhs) const {return (num>rhs.num);}
   
}T[Maxn];

void work()
{
	priority_queue<Tnode> Heap1;
	priority_queue<Tnode> Heap2;
	for (int i=1;i<=N;i++)
		{
			f[i]=g[i]=1;
			while (Heap1.size())	
			{
				int u=Heap1.top().pos,v=Heap1.top().num;
				if (v>=A[i]) break;
				T[++cnt].num=v; T[cnt].pos=u; f[i]=max(f[i],g[u]+1); Heap1.pop();
			}
			for (int j=1;j<=cnt;j++) Heap1.push((Tnode){T[j].num,T[j].pos}); Heap1.push((Tnode){A[i],i});
			
			cnt=0;
			while  (Heap2.size())
			{
				int u=Heap2.top().pos,v=-Heap2.top().num+Inf;
				if (A[u]<=A[i]) break;
				T[++cnt].num=v; T[cnt].pos=u; g[i]=max(g[i],f[u]+1); Heap2.pop();	
			}
			for (int j=1;j<=cnt;j++) Heap2.push((Tnode){Inf-T[j].num,T[j].pos}); Heap2.push((Tnode){Inf-A[i],i});
		}
	printf("%d\n",max(f[N],g[N]));
}

int main()
{
	freopen("flower.in","r",stdin);	freopen("flower.out","w",stdout);
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf(" %d",&A[i]);
	
	if (N<=1000)
	{
		for (int i=1;i<=N;i++)
			{
				f[i]=g[i]=1;
				for (int j=1;j<i;j++)
				{
					if (A[j]<A[i]) f[i]=max(f[i],g[j]+1);
					if (A[j]>A[i]) g[i]=max(g[i],f[j]+1);
				}
			}
		printf("%d\n",max(f[N],g[N]));
	}
	else work();
	
	return 0;
}
