#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int l[1002],c[1002];
bool cc[1002];
int main()
{
	int n,m,Max=0;
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	scanf(" %d%d",&n,&m);
	l[1]=n;
	fill(c+1,c+n+1,1);
	for(int i=1,h,s=0,t=n+1;i<=m;i++)
	{
		fill(cc+1,cc+n+1,false);
		scanf(" %d",&h);
		for(int j=1,a;j<=h;j++)
		{
			scanf(" %d",&a);
			cc[a]=true;
			if(a>s) s=a;
			if(a<t) t=a;
		}
		for(int j=1;j<=n;j++)
		{
			if(!cc[j]) continue;
			for(int k=1;k<=n;k++)
			{
				if(cc[k]) continue;
				if(c[k]==c[j]){l[c[j]]--,c[j]++;break;}
			}
		}
	}
	for(int i=1;i<=n;i++)if(c[i]>Max)Max=c[i];
	cout<<Max<<endl;
	return 0;
}
