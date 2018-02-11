#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
struct node
{
	int x,p,c;
	bool operator < (const node &no) const
	{
		return (x<no.x)||((x==no.x)&&(p<no.p));
	}
}a[200000],b[200000];
int i,j,k,l,x,y,m,n,jl[200000],t,s[200000];
long long ans;
void mergesort(int l,int r)
{
	if (l==r) return;
	if (r-l==1){if (jl[l]>jl[r]){t=jl[l];jl[l]=jl[r];jl[r]=t;ans++;}return;}
	int i,j,mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	i=l;j=mid+1;
	while ((i<=mid)&&(j<=r))
	{
		if (jl[i]<jl[j]){s[i+j-mid-1]=jl[i];i++;}
		else {s[i+j-mid-1]=jl[j];ans=ans+mid-i+1;j++;}
	}
	if (j<=r) while (j<=r){s[i+j-mid-1]=jl[j];j++;}
	else while (i<=mid){s[i+j-mid-1]=jl[i];i++;}
	for (i=l;i<=r;i++) jl[i]=s[i];
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;ans=0;
	for (i=1;i<=n;i++) {cin>>a[i].x;a[i].p=i;}
	for (i=1;i<=n;i++) {cin>>b[i].x;b[i].p=i;}
	sort(a+1,a+1+n);sort(b+1,b+1+n);
	for (i=1;i<=n;i++) a[i].c=b[i].p;
	for (i=1;i<=n;i++) jl[a[i].p]=a[i].c;
	if  (n<=2000)
	{
		for (i=2;i<=n;i++)
		{
			j=i;
			while ((j>1)&&(jl[j-1]>jl[j]))
			{
				t=jl[j];jl[j]=jl[j-1];jl[j-1]=t;
				j--;ans++;
			}
		}
		cout<<ans%99999997;
		return 0;
	}
	mergesort(1,n);
	cout<<ans%99999997<<endl;
}

