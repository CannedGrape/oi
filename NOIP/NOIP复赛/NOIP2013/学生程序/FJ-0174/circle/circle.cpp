#include <iostream>
#include <cstdio>
using namespace std;

long long n,m,x,k;
long long a[1000];

void solve()
{
	long long ans=1;
	int t=0;
	while (k)
	{
		a[++t]=k & 1;
		k>>=1;
	}
	for (int i=t;i;i--)
	{
		ans=ans*ans % n;
		if (a[i]) ans=ans*10 % n;
	}
	ans%=n;
	int step=ans * m %n;
	cout<<(x+step)%n<<endl;
}

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	cin>>n>>m>>k>>x;
	solve();
	return 0;
}


