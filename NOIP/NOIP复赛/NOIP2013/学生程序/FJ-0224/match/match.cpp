#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
using namespace std;
const long long p=99999997;
struct zn{int num;int x;};
zn a[100009],b[100009];
bool cmp(zn a,zn b){return a.x<b.x;}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].x),a[i].num=i;
	for(int i=1;i<=n;i++)scanf("%d",&b[i].x),b[i].num=i;
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(b[i].num==a[i].num) continue;
		if(b[i].num<a[i].num)
		{
		for(int j=1;j<=n;j++)
		if(b[j].num>b[i].num&&b[j].num<=a[i].num) b[j].num--;
		ans=(ans+a[i].num-b[i].num)%p;
		b[i].num=a[i].num;
		}
		else
		{
		for(int j=1;j<=n;j++)
		if(b[j].num<b[i].num&&b[j].num>=a[i].num) b[j].num++;
		ans=(ans+b[i].num-a[i].num)%p;
		b[i].num=a[i].num;
		}
	}
	cout<<ans<<endl;
}
