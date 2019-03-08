#include"stdio.h"
#include"stdlib.h"
#define lowbit(x) (x&(-x))
int n,i,j,c[100010],pp[100010],tem;
long long ans=0;
struct p
{
	int x;
	int poi;
}s1[100010],s2[100010];
int cmp(const void * a,const void * b)
{
	struct p q=*(struct p *)a,w=*(struct p *)b;
	if(q.x>w.x)return 1;
	else return -1;
}
void add(int v)
{
	while(v<=n)
	{
		c[v]++;
		v+=lowbit(v);
	}
	return ;
}
int sum(int v)
{
	int tot=0;
	while(v>0)
	{
		tot+=c[v];
		v-=lowbit(v);
	}
	return tot;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s1[i].x);
		s1[i].poi=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s2[i].x);
		s2[i].poi=i;
	}
	qsort(s1+1,n,sizeof(struct p),cmp);
	qsort(s2+1,n,sizeof(struct p),cmp);
	for(i=1;i<=n;i++)
		pp[s1[i].poi]=i;
	for(i=n;i>=1;i--)
	{
		tem=pp[s2[i].poi];
		ans+=(long long)sum(tem-1);
		add(tem);
	}
	printf("%lld\n",ans%99999997);
	return 0;
}
	
