#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxN=50010,maxM=50010;
struct node
{
	int to,w;
	node *next;
}edge[maxN+maxN]={},*last[maxN]={},*tot=edge;
struct a
{
	ll time;
	int pos;
}waiting[maxN]={};
struct cmp
{
	inline const bool operator()(const a &x,const a &y)
	{
		return (x.time>y.time)|((x.time==y.time)&(x.pos<y.pos));
	}
};
int indeg[maxN]={},army[maxM]={},Q[maxN]={0,1},father[maxN]={},up_cost[maxN]={};
bool covered[maxN]={},visit[maxN]={false,true};
int totl=0,leaves[maxN]={};
int totw=0,pw=0;
inline void addedge(const int &x,const int &y,const int &w)
{
	++tot;
	tot->to=y;
	tot->w=w;
	tot->next=last[x];
	last[x]=tot;
	return;
}
inline void del_leaf(const int &x)
{
	leaves[x]=leaves[totl];
	leaves[totl]=0;
	--totl;
	return;
}
inline const bool check(const int &N)
{
	for(register int i=1;i<=totl;++i)
	    if(!covered[leaves[i]])
	        return false;
	    else
	    {
	        del_leaf(i);
	        --i;
		}
	return true;
}
inline void covering(const int &root)
{
	register int head=0,tail=1,u,v;
    Q[1]=root;
	covered[root]=true;
	while(head<tail)
	{
		++head;
		u=Q[head];
		if(u!=1)
		    for(register node *p=last[u];p;p=p->next)
	    	{
		    	v=p->to;
			    if(v!=father[u] && !covered[v])
	    		{
		    		covered[v]=true;
			    	++tail;
				    Q[tail]=v;
    			}
	    	}
	}
	return;
}
int main()
{
	freopen("blockade.in","r",stdin);
	freopen("blockade.out","w",stdout);
	register int N,M,head=0,tail=1,cnt_edge=0;
	scanf("%d",&N);
	for(register int i=1;i<=N-1;++i)
	{
		register int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
		++indeg[u];
		++indeg[v];
	}
	for(register int i=2;i<=N;++i)
	    if(indeg[i]==1)
	    {
			++totl;
			leaves[totl]=i;
		}
	scanf("%d",&M);
	for(register int i=1;i<=M;++i)
	{
		register int u;
		scanf("%d",&u);
		army[i]=u;
		covered[u]=true;
	}
	while(head<tail)
	{
		register int u,v;
		++head;
		u=Q[head];
		for(node *p=last[u];p;p=p->next)
		{
			v=p->to;
			if(!visit[v])
			{
				visit[v]=true;
				if(u==1)
				    ++cnt_edge;
				father[v]=u;
				up_cost[v]=p->w;
				covered[v]|=covered[u];
				++tail;
				Q[tail]=v;
			}
		}
	}
	if(cnt_edge>M)
	    printf("-1\n");
	else
	{
		register ll ans=0;
		register a t;
        priority_queue<a,vector<a>,cmp> heap;
		for(register int i=1;i<=M;++i)
		{
			t.time=up_cost[army[i]];
			t.pos=army[i];
			heap.push(t);
		}
		while(!check(N) && !heap.empty())
		{
			t=heap.top();
			heap.pop();
			ans=max(ans,t.time);
			t.pos=father[t.pos];
			t.time+=up_cost[father[t.pos]];
			if(t.pos==1)
			{
				++totw;
				waiting[totw]=t;
			}
			else
			{
			    heap.push(t);
			    covering(t.pos);
			}
		}
		while(!check(N))
		{
			register int v,tmax=0,k=-1;
			for(register node *p=last[1];p;p=p->next)
			{
				v=p->to;
				if(!covered[v] && tmax<p->w)
				{
					tmax=p->w;
					k=p->to;
				}
			}
			covered[k]=true;
			covering(k);
			++pw;
			ans=max(ans,waiting[pw].time+tmax);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
