#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct edge
{
	int x,y,value;
}map[50010],question[30010];
int n,m,q;
int father[10010];
int cmp(edge a,edge b)
{
	return a.value>b.value;
}
int find_father(int c)
{
	if(father[father[c]]==father[c])
	{
		return father[c];
	}
	else
	{
		father[c]=find_father(father[c]);
		return father[c];
	}
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	int i,j,k;
	memset(map,0,sizeof(map));
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&map[i].x,&map[i].y,&map[i].value);
	}
	sort(map+1,map+1+m,cmp);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&question[i].x,&question[i].y);
		question[i].value=-1;
	}
	for(i=1;i<=n;i++)
	{
		father[i]=i;
	}
	int fa_a,fa_b;
	int fa_c,fa_d;
	for(i=1;i<=m;i++)
	{
		fa_a=find_father(map[i].x);
		fa_b=find_father(map[i].y);
		if (fa_a!=fa_b)
		{
			father[fa_a]=fa_b;
			for(j=1;j<=q;j++)
			{
				if(question[j].value==-1)
				{
					fa_c=find_father(question[j].x);
					fa_d=find_father(question[j].y);
					if (fa_c==fa_d)
					{
						question[j].value=map[i].value;
					}
				}
			}
		}
	}
	for(i=1;i<=q;i++)
	{
		printf("%d\n",question[i].value);
	}
	return 0;
}

