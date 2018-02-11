#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
int a[100005],ans;
bool flag[100005];
int main()
{
freopen("block.in","r",stdin);
freopen("block.out","w",stdout);
	int n;
	cin>>n;
	int i,j,k,minn=100000000;
	for(i=1;i<=n;i++) scanf("%d",&a[i]),minn=min(minn,a[i]);
	ans+=minn;
	for(i=1;i<=n;i++) a[i]-=minn;
	for(i=1;i<=n;i=k)
	{
	    int j=i+1;
	    while(a[j-1]<a[j]) j++;
	    int t=j-1;
		k=j;
	    while(a[k-1]>a[k]) k++;
	    ans+=a[t];
	}
	cout<<ans<<"\n";
return 0;
}
