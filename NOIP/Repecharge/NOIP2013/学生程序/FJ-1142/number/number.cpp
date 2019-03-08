#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
int s[1002][1002],n;
bool cmp(const xpy a1,const xpy a2)
{
	return (a1.fs<a2.fs);
}
struct xpy{
	int sz,tz,fs;
}a[1000002];
int dp()
{
	s[1][1]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
	if (j<=i) s[i][j]=s[j][i];
	if (j==i+1 && i>1) s[i][j]=s[i-1][j]-a[i-1].sz;
	}
	else s[i][j]=s[i][j-1]+a[j].sz;
	for (int i=1;i<=n;i++) sort(s[i]+1,s[i]+n+1);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int p,v=-1000000000;
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].sz);
	dp();
	for (int i=1;i<=n;i++) a[i].tz=s[i][n];
	for (int i=1;i<=n;i++) {
	for (int j=1;j<=n;i++) if ((a[j].sz+a[j].tz)>v) v=a[j].sz+a[j].tz;a[i].fs=v,v=-1000000000;}
	sort(a+1,a+n+1,cmp);
	printf("%d",a[n].fs%p);
	return 0;
}
