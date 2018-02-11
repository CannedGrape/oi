#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int edge[100005],pre[100005],first[100005],w[100005],dis[100005];
int q[100005];
int ord[100005];
bool cmp(int a,int b){return w[a]>w[b];}
int n,m,num,p;
void add_edge(int a,int b,int c)
{
	edge[++num]=b;
	pre[num]=first[a];
	first[a]=num;
	w[num]=c;
	
	edge[++num]=a;
	pre[num]=first[b];
	first[b]=num;
	w[num]=c;
}
int bfs(int a,int b)
{
	if(!first[b]) return -1;
	int i,j,head=1,tail=2;
	memset(dis,0,sizeof(dis));
	q[1]=a;
	while(head<tail)
	{
		int v=q[head++];
		for(i=first[v];i;i=pre[i])
		{
			if(!dis[i] || dis[v]+1<dis[i])
		    {
				dis[i]=dis[v]+1;
				q[tail++]=edge[i];
			}
		}
	}
	int minn=100000000;
	for(i=first[a];i;i=pre[i]) 
	{
     	minn=min(minn,w[edge[i]]);
		if(edge[i]==b) break;
    }
return minn;
}
int main()
{
freopen("truck.in","r",stdin);
freopen("truck.out","w",stdout)
	cin>>n>>m;
	int i,j;
	for(i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add_edge(a,b,c);
	}
	sort(ord+1,ord+1+n,cmp);
	cin>>p;
	for(i=1;i<=p;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
	    printf("%d\n",bfs(a,b));
	}
return 0;
}
