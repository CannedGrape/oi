#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int h=0,last=0,ans=0;
	for (int i=1; i<=n; i++)
	{
		cin >> h;
		if (h>last) ans+=h-last;
		last=h;
	}
	cout << ans << endl;
	return 0;
}
