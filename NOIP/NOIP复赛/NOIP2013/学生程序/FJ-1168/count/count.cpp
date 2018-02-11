#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
using namespace std;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	long long n,x,y,ans=0;
	cin>>n>>x;
	for(long long i=1;i<=n;i++)
	{ y=i;
	  while(y!=0)
	     {if(y%10==x)
	      ans++;
	      y/=10;}			
		}
	cout<<ans<<endl;
	return 0;
}
