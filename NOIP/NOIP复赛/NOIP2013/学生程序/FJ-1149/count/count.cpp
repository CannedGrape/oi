#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m,ans=0;
int a[1000010];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int i,j;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{ a[i]=i;
	  while (a[i]/10!=0)
	  { if (a[i]%10==m) ans++;
	    a[i]/=10;
	  }
	  if (a[i]==m) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
