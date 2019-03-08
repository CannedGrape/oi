#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,p;
long long s[1000010],f[1000010],h[1000010],xxx=100000000000000000,ans;

int main()
{
  int i,a;
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  scanf("%d%d",&n,&p);
  f[0]=-xxx;h[0]=-xxx;ans=-xxx;
  for(i=1;i<=n;i++) 
  {
	scanf("%lld",&s[i]);
	f[i]=max(f[i-1]+s[i],s[i]);
  }
  for(i=1;i<=n;i++) f[i]=max(f[i],f[i-1]);
  h[1]=f[1];h[2]=h[1]+f[1];
  for(i=3;i<=n;i++) h[i]=max(h[i-1],h[i-1]+f[i-1]);
  for(i=1;i<=n;i++) ans=max(ans,h[i]);
  cout<<ans%p<<endl;
  return 0;
}
