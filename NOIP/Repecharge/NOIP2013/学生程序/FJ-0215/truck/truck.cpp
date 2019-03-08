#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MaxN=10001;
const int MaxM=50001;

struct edge
{
	int l,r;
	int v;
};

bool cmp(edge a,edge b)
{
	return a.v>b.v;
}

int n,m,q,father[MaxN],fa[MaxN];
edge a[MaxM];

int find(int x)
{
	if (father[x]==x)
	{
		return x;
	}
	return father[x]=find(father[x]);
}

void build()
{
	for (int i=1;i<=n;i++)
	{
		father[i]=i;
	}
}

int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	build();
	for (int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].v);
		int x=find(a[i].l),y=find(a[i].r);
		//cout<<x<<' '<<y<<endl;
		if (x!=y)
		{
			father[x]=y;
		}
		/*for (int j=1;j<=n;j++)
		{
			cout<<father[j]<<' ';
		}*/
	}
	for (int i=1;i<=n;i++)
	{
		find(i);
	//	cout<<father[i]<<' ';
	}
	//cout<<endl;
	memcpy(fa,father,sizeof(fa));
	sort(a,a+m,cmp);
	scanf("%d",&q);
	for (int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if (fa[l]!=fa[r])
		{
			printf("-1\n");
			continue;
		}
		build();
		for (int i=0;i<m;i++)
		{
			int x=find(a[i].l),y=find(a[i].r);
			if (x!=y)
			{
				father[x]=y;
			}
			if (find(l)==find(r))
			{
				printf("%d\n",a[i].v);
				break;
			}
		}
	}
	//system("pause");
	return 0;
}
