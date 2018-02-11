#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n,wa[100005],wb[100005],mod=99999997;
long long a[100005],b[100005];
bool cmpa(int x,int y)
{
	return a[x]>a[y];
}
bool cmpb(int x,int y)
{
	return b[x]>b[y];
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	bool d=0;
	int i,temp,ans=0,j;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i],wa[i]=i;
	for(i=1;i<=n;i++)
	cin>>b[i],wb[i]=i;
	sort(wa+1,wa+1+n,cmpa);
	sort(wb+1,wb+1+n,cmpb);
	for(i=1;i<=n;i++)
	{
	d=0;
	for(j=i;j<=n;j++)
	if(wa[j]!=wb[j])
	 { 
		d=1;
		ans++;
		temp=b[wb[j]];
		b[wb[j]]=b[wa[j]];
		b[wa[j]]=temp;
		ans%=mod;
		break;
     }
     if(d==0) break;
     for(j=1;j<=n;j++) wa[j]=wb[j]=j;
	 sort(wa+1,wa+1+n,cmpa);
	 sort(wb+1,wb+1+n,cmpb);
	}
	 cout<<ans;
	return 0;
}
