#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
using namespace std;
const int inf=1<<30;
struct Edge{int v;int z;int nex;};
Edge e[100010];
int tot=0,fir[10055],dis[10055];
int n,m;
queue<int> q;
void ad(int x,int y,int z)
{
	tot++;
	e[tot].v=y;e[tot].z=z;e[tot].nex=fir[x];fir[x]=tot;
}
bool spfa(int x,int y,int z)
{
	int t,v;
	for(int i=1;i<=n;i++) dis[i]=inf;
	while(!q.empty())q.pop();
	dis[x]=0;
	q.push(x);
	while(!q.empty())
	{
		t=q.front();q.pop();
		for(int i=fir[t];i;i=e[i].nex)
		{
			if(e[i].z<z) continue;
			v=e[i].v;
			if(dis[v]>dis[t]+e[i].z)
			{
				dis[v]=dis[t]+e[i].z;
				q.push(v);
			}
		}
	}
	if(dis[y]==inf) return 1;else return 0;
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	int x,y,z,mz=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		ad(x,y,z);
		ad(y,x,z);
		mz=max(z,mz);
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		int l=-1,r=mz,mid;
		while(r-l>1)
		{
			mid=r+l>>1;
			if(spfa(x,y,mid)==1) r=mid;else l=mid;
		}
		printf("%d\n",l);
	}
}
