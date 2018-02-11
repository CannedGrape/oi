#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>

using namespace std;

const int Maxn=100010;

int n,ans=0,qn=0;
int h[Maxn];
int q[Maxn];

int find(int x)
{
	int l=1,r=qn;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(q[mid]>x) l=mid+1;
		else r=mid;
	}
	return l;
}

int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	
	scanf(" %d",&n);
	for(int i=1;i<=n;i++) scanf(" %d",&h[i]);
	
	qn=1; q[1]=h[1]; ans+=h[1];
	for(int i=2;i<=n;i++)
	{
		if(h[i]<q[qn]) q[++qn]=h[i];
		else
		{
			int p=find(h[i]);
			ans+=(h[i]-q[qn]);
			if(q[p]>h[i]) qn=p+1; else qn=p;
			q[qn]=h[i];
		}
	}
	
	printf("%d\n",ans);
	
	//system("pause");
	return 0;
}

