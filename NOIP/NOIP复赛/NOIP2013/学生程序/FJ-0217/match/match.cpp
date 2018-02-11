#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>

using namespace  std;

const int MAXN=100100;
const int MOD=99999997;

typedef long long I64;
struct node
{
	int p;
	I64 w;
};

I64 a[MAXN],b[MAXN],ansa[MAXN],ansb[MAXN];
node tmpa[MAXN],tmpb[MAXN];
int n,total;

bool cmp(node x,node y)
{
	return x.w<y.w;
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	int i,j,k;
	
	scanf("%d",&n);
	for (i=1; i<=n ; i++) 
	{
		scanf("%lld",&a[i]);
		tmpa[i].w=a[i];
		tmpa[i].p=i;
	}
	for (i=1; i<=n ; i++) 
	{
		scanf("%lld",&b[i]);
		tmpb[i].w=b[i];
		tmpb[i].p=i;
	}
	
	sort(tmpa+1,tmpa+n+1,cmp);
	sort(tmpb+1,tmpb+n+1,cmp);
	
	for (i=1; i<=n; i++)
	{
		ansa[tmpa[i].p]=tmpb[i].p;
		ansb[tmpb[i].p]=tmpa[i].p;
	}
	
	total=0;
    for (i=1; i<=n; i++)
	{
		total=(total+ansa[i]-i) % MOD;
		for (j=ansa[i]; j>=i+1; j--)
		{
			ansb[j]=ansb[j-1];
		    ansa[ansb[j]]++;
		}
		ansa[i]=i;
	}
	printf("%d\n",total);
	
	return 0;
}
