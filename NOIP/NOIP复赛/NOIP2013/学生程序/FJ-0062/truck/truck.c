#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int n,i,m,fa[10010],q,cn,j,flag,max;
struct p
{
	int z;
	int x;
	int y;
}pa[50010];
int cmp(const void * a,const void * b)
{
	struct p e=*(struct p *)a;
	struct p r=*(struct p *)b;
	if(e.z<r.z)return 1;
	else return -1;
}
int find(int x)
{
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	int xx,yy,st,en;
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&pa[i].x,&pa[i].y,&pa[i].z);
	}
	qsort(pa+1,m,sizeof(struct p),cmp);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		flag=0;
		for(j=1;j<=n;j++)
			fa[j]=j;
		scanf("%d%d",&st,&en);
		for(j=1;j<=m;j++)
		{
			xx=find(pa[j].x);yy=find(pa[j].y);
			if(xx!=yy)
				fa[xx]=yy;
			max=pa[j].z;
			if(find(st)==find(en))
			{
				printf("%d\n",max);
				flag=1;
				break;
			}		
		}
		if(flag==0)printf("-1\n");	
	}
	return 0;
}	
		
		
		
