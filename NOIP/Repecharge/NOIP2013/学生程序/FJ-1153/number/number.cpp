#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
__int64 n,p,a[1000001],b[1000001],c[1000001],sum,maxn;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> n >> p;
	for(int o=1;o<=n;o++) cin >> a[o];
	for(int o=1;o<=n;o++) b[o]=c[o]=-100000001;
	b[1]=a[1];
	for(int i=2;i<=n;i++)
	  for(int j=1;j<=i;j++)
	    for(int k=1;k<=i-j+1;k++)
	    {
	      for(int l=1;l<=j;l++)
	        sum+=a[k+l-1];
	      b[i]=max(b[i],sum);
	      sum=0;
	    }
	c[1]=maxn=b[1];
	for(int i=2;i<=n;i++)
	  for(int j=1;j<i;j++)
	    c[i]=max(c[i],b[j]+c[j]);
	cout << maxn%p << endl;
	return 0;
}
