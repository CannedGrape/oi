#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
long n,a[100010],gao[100010],di[100010];
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%ld%ld",&n,&a[1]);
	memset(gao,0,sizeof(gao));
	memset(di,0,sizeof(di));
	gao[1]=1;
	di[1]=1;
	long ans=0;
	for(int i=2;i<=n;i++)
	{
		scanf("%ld",&a[i]);
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]>a[j])gao[i]=max(gao[i],di[j]);
			if(a[i]<a[j])di[i]=max(di[i],gao[j]);
		}
		gao[i]++;
		di[i]++;
		ans=max(ans,max(gao[i],di[i]));
	}
	cout<<ans;
	return 0;
}

