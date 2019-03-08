#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
long long a[200000],i,j,k,l,x,y,m,n;
void dg(long long l,long long r)
{
	if (l==r){m=m+a[l];return;}
	long long i,k;y=10000000LL;
	for (i=l;i<=r;i++) y=min(y,a[i]);
	m=m+y;
	for (i=l;i<=r;i++) a[i]=a[i]-y;
	i=l;
	while (i<=r)
	{
		k=i;while ((a[k]!=0)&&(k<=r)) k++;
		if (k!=i) dg(i,k-1);
		i=k+1;
	}
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;m=0LL;
	for (i=1;i<=n;i++) 
		cin>>a[i];
	dg(1,n);
	cout<<m<<endl;
	return 0;
}
