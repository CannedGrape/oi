#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	long long n,ans=0;
	int x;
	cin>>n>>x;
	for(long long i=1;i<=n;i*=10)
	{
		ans+=n/(i*10)*i;
		if(n%(i*10)>=x*i)
		{
			if(n%(i*10)>=(x+1)*i-1)
				ans+=i;
			else
				ans+=n%(i*10)-x*i+1;
		}
	}
	cout<<ans;
	//system("pause");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
