#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct edge
{
	int x,y,z;
}map_1[100010],map_2[100010];
int s_tree[300010];
int low_bit(int i)
{
	return i&(-i);
}
int cmp(edge a,edge b)
{
	return a.y<b.y;
}
int cmp1(edge a,edge b)
{
	return a.x<b.x;
}
void up_date(int x,int value)
{
	int i;
	for (i=x;i<=n;i+=low_bit(i))
	{
		s_tree[i]+=value;
	}
	return;
}
int get_sum(int x)
{
	int sum=0;
	for (int i=x;i>=1;i-=low_bit(i))
	{
		sum+=s_tree[i];
	}
	return sum;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	memset(s_tree,0,sizeof(s_tree));
	for (i=1;i<=n;i++)
	{
		scanf("%d",&map_1[i].y);
		map_1[i].x=i;
	}
	sort(map_1+1,map_1+1+n,cmp);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&map_2[i].y);
		map_2[i].x=i;
	}
	sort(map_2+1,map_2+1+n,cmp);
	for (i=1;i<=n;i++)
	{
		map_1[i].z=map_2[i].x;
		map_2[i].z=map_1[i].x;
	}
	sort(map_1+1,map_1+1+n,cmp1);
	sort(map_2+1,map_2+1+n,cmp1);
	long long ans=0;
	long long t=0;
	for (i=n;i>=1;i--)
	{
		t=get_sum(map_1[i].z);
		if (i>map_1[i].z-t)
		{
			ans+=i-map_1[i].z+t;
			up_date(map_1[i].z,1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
