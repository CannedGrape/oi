#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int n,i,j,m,b[100001],a[100002],s;
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	if (n==1)
	{
		printf("1\n");
		return 0;
	}
	for (i=1;i<=n;i++) scanf("%d",&b[i]);
	i=1;m=0;b[n+1]=-1;
	while (i<=n)
	{
		m++;a[m]=b[i];
		j=i+1;while (b[j]==b[i]) j++;i=j;
	}
	s=2;
	for (i=2;i<m;i++)
	{
		if ((a[i]>a[i-1])&&(a[i]>=a[i+1])) s++;
		if ((a[i]<a[i-1])&&(a[i]<=a[i+1])) s++;
	}
	printf("%d\n",s);
	return 0;
}
