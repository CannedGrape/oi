#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
int n,m,a[101],k,ans;
void flower(int i)
{
	for(int j=a[i];j>=1;j--)
	{
		if(k+j<=m)
		{
			k+=j;
			if(k==m)
			{
				ans++;
				ans%=1000007;
			}
			else
				if(i+1<=n)
					flower(i+1);
			k-=j;
		}
	}
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	flower(1);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
