#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
long long k,n,m,x;
long long jl,ans;
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	cin>>n>>m>>k>>x;
	jl=10;ans=1;
	while (k>0)
	{
		if (k%2==1) ans=ans*jl%n;
		k=k/2;jl=jl*jl%n;
	}
	ans=(ans*m)%n;
	ans=(ans+x)%n;
	cout<<ans<<endl;
	return 0;
}
