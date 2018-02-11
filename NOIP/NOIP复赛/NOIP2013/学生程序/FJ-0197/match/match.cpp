#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define N 100004
#define Mod 99999997
using namespace std;
struct dd
{
    int l,r;
}num[N];
int a[N],b[N],a1[N],b1[N],n;
long long ans=0;
void init()
{
	scanf("%d",&n);
	int t;
	for (int i=1;i<=n;i++)  {scanf("%d",&a[i]);a1[i]=a[i];}
	for (int i=1;i<=n;i++)  {scanf("%d",&b[i]);b1[i]=b[i];}
}
void work()
{
	sort(a1+1,a1+1+n);
	sort(b1+1,b1+1+n);
	int tp1;
	for (int i=1;i<=n;i++)
	{
		tp1=a1[i];num[a1[i]].l=b1[i];
	    while (a1[i]==a1[i+1]&&i+1<=n)  i++;
	    num[a1[i]].r=b1[i];
	}
	int x=1,y=n;
	while (x<y)
	{
		int i=x,j=y;
	    for (;b[i]<num[a[x]].l||b[i]>num[a[x]].r;i++);
	    ans+=abs(i-x);
	    for (int i1=i;i1>x;i1--)  b[i1]=b[i1-1];
	    for (;b[j]<num[a[y]].l||b[j]>num[a[y]].r;j--);
	    ans+=abs(j-y);
	    for (int j1=j;j1<y;j1++)  b[j1]=b[j1+1];
		x++;y--;
	}
	printf("%lld",ans%Mod);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	init();
	work();
	//system("pause");
	return 0;
}
