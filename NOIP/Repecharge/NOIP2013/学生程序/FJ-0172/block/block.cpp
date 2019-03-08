#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
const int Maxn=100002;
int n,h[Maxn];
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf(" %d",&n);h[0]=0;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		ans+=max(0,h[i]-h[i-1]);
	}
	printf("%d\n",ans);
	return 0;
}
