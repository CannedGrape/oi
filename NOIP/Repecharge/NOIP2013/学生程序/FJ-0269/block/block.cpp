#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110000],f[110000];
int n,ans;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	int t = 1;
	f[t] = a[1];
	ans = 1;
	for (int i = 2;i <= n;i ++)
	{
		while (t && f[t] > a[i]) t --;
		if (t == 0 || f[t] < a[i])
		{
			f[++t] = a[i];
			ans ++;
		}
	}
	cout << ans;
	fclose(stdin);fclose(stdout);
}