#include<iostream>
#include<cstdio>
using namespace std;
int s,x,ans;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	
	cin >> s >> x;
	for(int i=1;i<=s;i++)
	{
	  int ii=i;
	  while(ii!=0)
	  {
		if(ii%10==x) ans++;
		ii/=10;
	  }
	}
	cout << ans << endl;
	return 0;
}
