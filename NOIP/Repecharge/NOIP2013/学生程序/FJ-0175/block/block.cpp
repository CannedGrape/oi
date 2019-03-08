#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=100005;
int n,ans,s[maxn];
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n); s[0]=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		if (s[i]-s[i-1]>0) ans+=s[i]-s[i-1];
	}
	printf("%d\n",ans);
	return 0;
}

