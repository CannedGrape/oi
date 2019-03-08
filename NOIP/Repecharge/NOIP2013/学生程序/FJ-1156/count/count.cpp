#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n=0,m=0,ans=0;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		int h=i;
		while(h>0)
		{
		  if(h%10==m)ans++;
		  h/=10;
		}
	}
	cout << ans << endl;
	return 0;
}
