#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define MAXN 100010
using namespace std;
int n,a[MAXN],f[MAXN][22],mul[22],que[MAXN][3],head,tail;
int ans;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for (i=1;i<=n;++i)
		scanf("%d",&a[i]),f[i][0]=i;
	mul[0]=1;
	for (i=1;i<=20;++i) mul[i]=mul[i-1]<<1;
	for (i=1;mul[i]<=n;++i)
		for (j=1;j+mul[i]-1<=n;++j)
			if (a[f[j][i-1]]<=a[f[j+mul[i-1]][i-1]])
				f[j][i]=f[j][i-1];
			else
				f[j][i]=f[j+mul[i-1]][i-1];
	head=0;
	que[tail=1][0]=1; que[1][1]=n;
	while (head<tail)
	{
		int l=que[++head][0],r=que[head][1];
		for (i=1;l+mul[i]-1<=r;++i);
		--i;
		if (a[f[l][i]]<=a[f[r-mul[i]+1][i]])
			j=f[l][i];
		else
			j=f[r-mul[i]+1][i];
		ans+=a[j]-que[head][2];
		if (l<j)
			que[++tail][0]=l,que[tail][1]=j-1,que[tail][2]=a[j];
		if (j<r)
			que[++tail][0]=j+1,que[tail][1]=r,que[tail][2]=a[j];
	}
	cout<<ans;
	//system("pause");
	return 0;
}
