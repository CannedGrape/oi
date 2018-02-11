#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdlib>
using namespace std;
int n,ans;
int s1[100002],s2[100002],tong[100002];

struct node{int s,num;}ss1[100002],ss2[100002];

bool cmp(node a,node b)
{
	return a.s<b.s;
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&s1[i]),ss1[i].s=s1[i],ss1[i].num=i;
	for (int i=1;i<=n;i++)scanf("%d",&s2[i]),ss2[i].s=s2[i],ss2[i].num=i;
		sort(ss1+1,ss1+1+n,cmp);
		sort(ss2+1,ss2+1+n,cmp);
		for (int i=1;i<=n;i++)tong[ss2[i].num]=i;
		bool pd=0; 
		for (int i=1;i<=n;i++) if (!(ss1[i].num==ss2[i].num))pd=1;
		while (pd)
		{
			for (int i=1;i<=n;i++)
			{
				if (s2[ss1[i].num]!=ss2[i].s)
				{
					int tp=s2[ss1[i].num];
					s2[ss1[i].num]=s2[ss2[i].num];
					s2[ss2[i].num]=tp;
					
					tp=ss2[i].num;
					ss2[i].num=ss2[tong[ss1[i].num]].num;
					ss2[tong[ss1[i].num]].num=tp;
					
					tp=tong[ss1[i].num];
					tong[ss1[i].num]=tong[ss2[i].num];
					tong[ss2[i].num]=tp;
					
					ans++;
				}
				ans=ans%99999997;
			}
			pd=0;
			for (int i=1;i<=n;i++) if (!(ss1[i].num==ss2[i].num))pd=1;
		}
		
	printf("%d",ans%99999997);
	return 0;
}
