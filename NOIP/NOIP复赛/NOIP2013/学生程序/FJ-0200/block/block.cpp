#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[100005];
int get()
{
	int res=0,v=0;char ch;
	while (!isdigit(ch=getchar())) if (ch=='-')break;
	if (ch=='-') v=1;else res=ch-48;
	while (isdigit(ch=getchar())) res=res*10+ch-48;
	if (v) return -res;return res;
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
	  a[i]=get();
	  if (a[i]>a[i-1]) ans+=a[i]-a[i-1];
	}
	printf("%d\n",ans);
	return 0;
}
