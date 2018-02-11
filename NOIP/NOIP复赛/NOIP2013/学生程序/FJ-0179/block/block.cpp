#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#define N 110000
using namespace std;

bool bo;
int data[N],i,j,ans,n,MAX=-1;

int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for (i=1; i<=n; i++) 
	{	
		cin >> data[i]; 
		MAX=max(MAX,data[i]);
	}
	data[0]=data[n+1]=-1;
	ans=0;
	for (i=1; i<=MAX; i++)
	{
		bo=false;
		for (j=1; j<=n+1; j++)
		{
			if (!bo && data[j]>=i) bo=true; else
			if (bo && data[j]<i)
			{
				bo=false;
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
