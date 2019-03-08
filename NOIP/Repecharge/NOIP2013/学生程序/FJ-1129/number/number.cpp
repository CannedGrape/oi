#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,a[1000010],p,ans,s[1000010],b[1000010];
bool f[1000010];
int work(int k)
{
	int tmp,x,j,i;
	tmp=0;
	k--;
	for(i=0;i<=k;i++)
	{
	   if(f[i]==1) 
	   {
		  j=i+1;x=0;
		  while (j<=k && x+s[j]>x) x+=s[j],j++;
		  if(x>tmp) tmp=x;
	   }
	}
	return tmp;
}
void sc()
{
	int i,maxx;
	maxx=a[1]+b[1];
	for(i=2;i<=n;i++)
	{
		b[i]=maxx;
		if(b[i]+a[i]>maxx) maxx=b[i]+a[i];
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i;
	scanf("%d%d",&n,&p);
	f[0]=1;
	for(i=1;i<=n;i++) 
	{
		f[i]=0;
		scanf("%d",&s[i]);
		if(s[i]<0) f[i]=1;
    }
    a[1]=s[1];
    for(i=2;i<=n;i++) a[i]=s[i]+work(i);
    b[1]=a[1];
    sc();
	ans=b[1];
    for(i=2;i<=n;i++) if(b[i]>ans) ans=b[i];
    cout<<ans%p<<endl;
	return 0;
}