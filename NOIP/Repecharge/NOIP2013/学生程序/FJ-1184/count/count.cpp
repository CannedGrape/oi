#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int n,x,ans=0,t;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
	  t=i;
	  while(t>0)
	  {
		if(t%10==x)
		  ans++;
		t/=10;
	  }
	}
	cout<<ans<<endl;
	return 0;
}
