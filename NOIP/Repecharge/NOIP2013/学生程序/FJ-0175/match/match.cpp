#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=100005;
const int P=99999997;
struct dot{int x,loc;}a[maxn],b[maxn];
int n,ans,c[maxn],tmp[maxn];
bool cmp2(const dot &x,const dot &y)
{
	return x.x<y.x;
}
void solve(int l,int r)
{
	if (l==r) return;
	int mid=(l+r)/2,num,tot=l,i,j;
	solve(l,mid); solve(mid+1,r);
	num=mid-l+1;
	for (i=l,j=mid+1;i<=mid && j<=r;)
		if (c[i]<c[j]) num--,tmp[tot++]=c[i],i++;
		else ans=(ans+num)%P,tmp[tot++]=c[j],j++;
	while (i<=mid) tmp[tot++]=c[i],i++;
	while (j<=r) tmp[tot++]=c[j],j++;
	for (i=l;i<=r;i++) c[i]=tmp[i];
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].x),a[i].loc=i;
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;i++) scanf("%d",&b[i].x),b[i].loc=i;
	sort(b+1,b+1+n,cmp2);
	for (int i=1;i<=n;i++) c[b[i].loc]=a[i].loc;
	solve(1,n);
	printf("%d\n",ans);
	return 0;
}

