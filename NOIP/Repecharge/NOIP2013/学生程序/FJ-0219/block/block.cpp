#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int n;
long long total=0LL;
int temp[10005];
int h[100005];

int main()
{
	int i,j,maxn=0;
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		for (j=1;j<=h[i];j++)
		{
			if (temp[j]!=i-1 || temp[j]==0) total++;
			temp[j]=i;
	    }
	}
	cout<<total<<endl;
	return 0;
}
