#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[1001]={0},b,i,sum=0;
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=4*m+1;i++)
	    {
		 cin>>b;
		 a[b]++;
		}
	sort(a,a+n);
	for (int i=n;i>=1;i--)
	    if (a[i]!=a[i+1])
	       sum++;
	printf("%d\n",sum/2);
	return 0;
}
