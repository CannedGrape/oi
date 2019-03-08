#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
int a[100005],ans;
int main()
{
freopen("flower.in","r",stdin);
freopen("flower.out","w",stdout);
	int n;
	bool flag=false;
	cin>>n;
	int i,j,k,minn=100000000;
	for(i=1;i<=n;i++) 
	{
     	scanf("%d",&a[i]);
     	if(a[i]!=a[i-1]) flag=true;
    }
	int re;
    if(flag) re=1;
	else re=0;
	for(i=1;i<=n;i=k)
	{
	    int j=i+1;
	    while(a[j-1]<=a[j]) j++;
		k=j,re++;
	    while(a[k-1]>=a[k]) k++;
	    
	}
	ans=max(ans,re);
	if(flag) re=1;
	else re=0;
	for(i=1;i<=n;i=j)
	{
	    int k=i+1;
		while(a[k-1]>=a[k]) k++;
		j=k,re++;
	    while(a[j-1]<=a[j]) j++;
	}
	ans=max(ans,re);
    if(n==1) cout<<1;
	else cout<<ans<<"\n";
return 0;
}
