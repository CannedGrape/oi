#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int a[100010],b[100010];
int temp1[100010],temp2[100010];
int mer[100010];
int n;
long long sum=0;

bool compare1(int x,int y)
{
	if (a[x]<a[y]) return 1;
	return 0;
}

bool compare2(int x,int y)
{
	if (b[x]<b[y]) return 1;
	return 0;
}

void merge(int l,int r)
{
	if (l>=r) return;
	int mid=(l+r)/2,i,j,t;
	merge(l,mid); merge(mid+1,r);
	i=l; j=mid+1; t=l-1;
	while (i<=mid && j<=r)
	{
		if (temp1[i]<=temp1[j])
		{
			mer[++t]=temp1[i];
			i++;
		}
		else
		{
			mer[++t]=temp1[j];
			j++;
			sum+=(mid+1-i);
			sum%=99999997;
		}
	}
	while (i<=mid) {mer[++t]=temp1[i]; i++;}
	while (j<=r) {mer[++t]=temp1[j]; j++;}
	for (i=l;i<=r;i++) temp1[i]=mer[i];
	return;
}

int main()
{
	int i,j;
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n;i++) scanf("%d",&b[i]);
    for (i=1;i<=n;i++) {temp2[i]=i; temp1[i]=i;}
    sort(temp2+1,temp2+1+n,compare2);
	sort(temp1+1,temp1+1+n,compare1);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (temp1[i]==temp2[j]) break;
		}
		temp1[i]=j;
	}
	merge(1,n);
	printf("%LLd\n",sum);
	return 0;
}
