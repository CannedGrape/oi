#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,a[maxn],b[maxn],c[maxn],ord[maxn],ans;
int get()
{
	int res=0,v=0;char ch;
	while (!isdigit(ch=getchar())) if (ch=='-') break;
	if (ch=='-') v=1;else res=ch-48;
	while (isdigit(ch=getchar())) res=res*10+ch-48;
	if (v) return -res;return res;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	int i,j;
	for (i=1;i<=n;i++) a[i]=get(),c[i]=a[i];
	for (i=1;i<=n;i++) b[i]=get();
	sort(c+1,c+1+n);
	for (i=1;i<=n;i++) a[i]=lower_bound(c+1,c+1+n,a[i])-c;
	for (i=1;i<=n;i++) c[i]=b[i];
	sort(c+1,c+1+n);
	for (i=1;i<=n;i++) b[i]=lower_bound(c+1,c+1+n,b[i])-c;
	for (i=1;i<=n;i++) ord[b[i]]=i;
	for (i=1;i<=n;i++)
	{
	  if (a[i]==b[i]) continue;
	  ans+=ord[a[i]]-i;
	  for (j=ord[a[i]];j>i;j--) b[j]=b[j-1],ord[b[j]]++;
	  b[i]=a[i];
	}
	printf("%d\n",ans);
	return 0;
}
