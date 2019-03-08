#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,p,a[2000003],s[2000003],i,j,maxx,l,ans;
long long f;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%I64d%I64d",&n,&p);
	for(i=1;i<=n;i++){scanf("%I64d",&f);a[i]=f%p;}
	s[1]=a[1];
	for(i=2;i<=n;i++)
	 {
	 a[i]=max(a[i]+a[i-1],a[i]);ans=-2147483647;
	 for(j=1;j<i;j++)
		ans=max(ans,s[j]+a[j]);
	 s[i]=ans;
	 s[i]%=p;
	 }
	 for(i=1;i<=n;i++)ans=max(ans,s[i]);
	 printf("%I64d\n",ans%p);
	return 0;
}

