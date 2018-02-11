#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
using namespace std;
int n,p,s[10000][10000],a[10000]={0},f[10000]={0},t[10000]={0},ans;
bool o=false;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>p;
	scanf("%d",&a[1]);
	t[1]=a[1];
	f[1]=a[1];
	ans=f[1];
	for(int i=2;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
	   { t[i]=t[i-1]+a[i];
	   f[i]=max(f[i-1],f[i-1]+t[i-1]);
	   if(f[i]>ans)
	      {if(f[i]>0)ans=f[i]%p;
	       else ans=-(abs(f[i]%p));
		  }
	   }
	cout<<ans<<endl;
	return 0;
}
