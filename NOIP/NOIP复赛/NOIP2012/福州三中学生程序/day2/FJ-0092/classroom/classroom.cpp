#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxint=~0U>>1;
struct node
{
	int min;
	node(const int &data=maxint):
		min(data)
		{}
}tree[1<<22]={};
int K=1;
inline const node operator+(const node &x,const node &y)
{
	register node s;
	s.min=min(x.min,y.min);
	return s;
}
inline const bool operator==(const node &x,const node &y)
{
	return x.min==y.min;
}
inline const int Min(const int &l,const int &r)
{
	register int ans=maxint;
	for(register int s=l+K-1,t=r+K+1;s^t^1;s>>=1,t>>=1)
	{
		if(~s&1)
		    ans=min(ans,tree[s^1].min);
		if(t&1)
		    ans=min(ans,tree[t^1].min);
	}
	return ans;
}
inline void update_tree(const int &pos)
{
	register node t;
	for(register int p=(pos+K)>>1;p;p>>=1)
	{
		t=tree[p];
	    tree[p]=tree[p+p]+tree[p+p+1];
	    if(t==tree[p])
	        return;
	}
	return;
}
int main()
{
	freopen("classroom.in","r",stdin);
	freopen("classroom.out","w",stdout);
	register int N,M;
	register bool flag=true;
	scanf("%d%d",&N,&M);
	while(K<N+N+3)
	    K=K+K;
	for(register int i=1;i<=N;++i)
	{
		register int a;
	    scanf("%d",&a);
	    tree[i+K]=node(a);
	}
	for(register int i=1;i<=N;i+=2)
	    update_tree(i);
	update_tree(N);
	for(register int i=1;i<=M;++i)
	{
		register int d,s,t;
		scanf("%d%d%d",&d,&s,&t);
		if(Min(s,t)<d)
		{
			flag=false;
			printf("-1\n%d\n",i);
			break;
		}
		else
		{
			for(register int j=s;j<=t;++j)
            	tree[j+K].min-=d;
            for(register int j=s;j<=t;j+=2)
			    update_tree(j);
			update_tree(t);
		}
	}
	if(flag)
	    printf("0\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
