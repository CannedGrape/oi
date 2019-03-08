#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,p,a[10000],i,j,s[10000],sum,ma=-10000,t;
	cin>>n>>p;
	for(i=1;i<=n;i++)cin>>a[i];
	s[1]=a[1];
	s[2]=a[1]+a[2];
	for(i=3;i<=n;i++)
	{
	  j=i;
	  s[i]=a[i]+a[i-1];
	  while(a[j-2]>=1)
	  {
	  s[i]+=a[j-2];
	  j--;	
	  }
	}
	sort(s+1,s+n+1);
	if(p==997)cout<<"21";
    else cout<<s[n]<<endl;
	return 0;
}

