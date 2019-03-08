#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>

using namespace std;

const int MAXN=100100;

int h[MAXN];
int n;
long long ans;

int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);

	int i,j,k;

	scanf("%d",&n);
	for (i=1; i<=n; i++)
	   scanf("%d",&h[i]);
	
	ans=0;
	h[0]=0;
	for (i=1; i<=n; i++)
	  if (h[i]>h[i-1])
		ans+=h[i]-h[i-1];
    
    printf("%lld\n",ans);
    
	return 0;
}
