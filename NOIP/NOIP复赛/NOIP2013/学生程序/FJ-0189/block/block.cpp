#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <cstdlib>
using namespace std;
int a[100001],f[100001][31];
int low(int a,int b)
{
	if(a<b) return a;
	else return b;
}
long long ans=0;
void fenzhi(int l,int r,int s)
{
	if(l>r) return ;
	if(l==r) 
	{
	ans=ans+a[l]-s;
	return ;
	}
	int min1=l;
	for(int i=l+1;i<=r;i++)
	 if(a[i]<a[min1]) min1=i;
	 ans=ans+a[min1]-s;
	fenzhi(l,min1-1,a[min1]);
	fenzhi(min1+1,r,a[min1]);
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
    fenzhi(1,n,0);
    cout<<ans<<endl;
    return 0;
}
