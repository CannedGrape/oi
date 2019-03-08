#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[8];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,x,i,j,ans=0;
	cin>>n>>x;
	for(i=1;i<=7;i++)
	{
		a[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		a[1]++;
		for(j=1;j<=7;j++)
		{
			if(a[j]==10)
			{
				a[j]=0;
				a[j+1]++;
			}
		}
		for(j=1;j<=7;j++)
		{
			if(a[j]==x)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
