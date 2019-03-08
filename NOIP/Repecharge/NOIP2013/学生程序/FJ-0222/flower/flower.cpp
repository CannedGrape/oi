#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <string.h>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

using namespace std;

long long f[100001][2],a[100001],ans,n;//0代表方案A山峰，1代表方案B盆地； 

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	ans=0;
	for (int i=1; i<=n; i++) 
	{
		cin >> a[i];
		f[i][0]=1; f[i][1]=1;
		for (int j=i-1; j>=1; j--)
		{
			if (a[i]>a[j]) f[i][0]=max(f[i][0],f[j][1]+1);
			if (a[i]<a[j]) f[i][1]=max(f[i][1],f[j][0]+1);
		}
		ans=max(ans,max(f[i][0],f[i][1]));
	}
	cout << ans << endl;
	return 0;
}
