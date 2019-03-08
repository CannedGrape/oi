#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m,i,ans=0,x,y;
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		x=i;
		while(x>0)
		{
			y=x%10;
			if(y==m) ans++;
			x/=10;
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
