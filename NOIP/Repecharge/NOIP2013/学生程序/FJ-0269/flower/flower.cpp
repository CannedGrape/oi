#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int a[120000],f[120000][5];
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i ++)
		for (int j = 0;j < 5;j ++)
			f[i][j] = - (1 <<  29);
	for (int i = 1;i <= n;i ++)
		f[i][0] = f[i][1] = 1;
	int ans = 1;
	for (int i = 1;i <= n;i ++)
	{
		for (int j = 1;j < i;j ++)
		{
			if (a[j] > a[i])
				f[i][0] = max(f[i][0],f[j][3] + 1);
			if (a[j] < a[i])
				f[i][1] = max(f[i][1],f[j][2] + 1);
			if (a[j] > a[i])
				f[i][2] = max(f[i][2],max(f[j][0],f[j][1]) + 1);
			if (a[j] < a[i])
				f[i][3] = max(f[i][3],max(f[j][0],f[j][1]) + 1);
				
			ans = max(ans,f[i][0]);
			ans = max(ans,f[i][1]);
			ans = max(ans,f[i][2]);
			ans = max(ans,f[i][3]);
		}
	}
	cout << ans;
	fclose(stdin);fclose(stdout);
}