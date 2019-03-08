#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 100001, o=99999997;
struct node { int h,p; } a[N],b[N];
int n,pa[N],pb[N],ct=0;
bool cmp(node a, node b) {return a.h < b.h; }
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) a[i].p=b[i].p=i;
	for (int i=1;i<=n;i++) scanf("%d",&a[i].h);
	for (int i=1;i<=n;i++) scanf("%d",&b[i].h);
	sort(a+1,a+n+1,cmp); sort(b+1,b+n+1,cmp);
	for (int i=1;i<=n;i++) pa[a[i].p]=i,pb[b[i].p]=i;
	for (int i=1;i<n;i++)
	 for (int j=i+1;j<=n;j++)
	  if ((pa[i]>pa[j])^(pb[i]>pb[j]))
	  {
			ct++;
			if (ct>o) ct=1;
	  }
	cout << ct << endl;
	return 0;
}
