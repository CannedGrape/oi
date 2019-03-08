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
#define INF 999999999
using namespace std;

int ans=0,data[N],dp[2][N],i,j,k,m,n;

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for (i=1; i<=n; i++) cin >> data[i];
	memset(dp,128,sizeof(dp));
	dp[0][0]=0; data[0]=INF;
	for (i=1; i<=n; i++)
	  {
			for (k=0; k<i; k++)
			if (data[k]>data[i] && dp[0][k]>dp[1][i]) dp[1][i]=dp[0][k];
			dp[1][i]++;
			ans=max(ans,dp[1][i]);
			for (k=0; k<i; k++)
			if (data[k]<data[i] && dp[1][k]>dp[0][i]) dp[0][i]=dp[1][k];
			dp[0][i]++;
			ans=max(ans,dp[0][i]);
	  }
	memset(dp,128,sizeof(dp));
	dp[0][0]=0; data[0]=-INF;
	for (i=1; i<=n; i++)
	  {
			for (k=0; k<i; k++)
			if (data[k]<data[i] && dp[0][k]>dp[1][i]) dp[1][i]=dp[0][k];
			dp[1][i]++;
			ans=max(ans,dp[1][i]);
			for (k=0; k<i; k++)
			if (data[k]>data[i] && dp[1][k]>dp[0][i]) dp[0][i]=dp[1][k];
			dp[0][i]++;
			ans=max(ans,dp[0][i]);
	  }
	cout << ans << endl;
	return 0;
}
