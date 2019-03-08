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

int a[100001],n,ans;

int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	a[0]=0; ans=0;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		if (a[i]>a[i-1]) ans=ans+a[i]-a[i-1];
	}
	cout << ans << endl;
	return 0;
}
