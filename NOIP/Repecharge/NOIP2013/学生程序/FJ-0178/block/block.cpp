#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 100002;
int h[N],s[N],n,l=0,k=0,ans=0;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;)
	{
		scanf("%d",&h[i]);
		if (i>1 && h[i]==h[i-1]) n--; else i++;
	}
	for (int i=2;i<n;i++)
	if (h[i]<h[i-1] && h[i]<h[i+1])
	{
		int Max=0;
		for (int j=l+1;j<i;j++) Max=max(Max,h[j]);
		k++; l=i; ans+=Max-h[i];
	}
	int Max=0;
	for (int j=l+1;j<=n;j++) Max=max(Max,h[j]);
	ans+=Max;
	cout << ans << endl;
	return 0;
}

