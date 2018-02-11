#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n,sz[100002],f[100002][3],ans;
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&sz[i]);
	for (int i=0;i<=n+1;i++)f[i][1]=0,f[i][2]=0;
	for (int i=1;i<=n;i++)f[i][1]=1,f[i][2]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i-1;j++)
		{
			if (((f[j][1]+1)%2==0)&&(sz[j]<sz[i]))f[i][1]=max(f[i][1],f[j][1]+1);
			if (((f[j][1]+1)%2==0)&&(sz[j]>sz[i]))f[i][2]=max(f[i][2],f[j][1]+1);
			if ((f[j][1]%2==0)&&(sz[j]>sz[i]))f[i][1]=max(f[i][1],f[j][1]+1);
			if (((f[j][2]+1)%2==0)&&(sz[j]>sz[i]))f[i][2]=max(f[i][2],f[j][2]+1);
			if (((f[j][2]+1)%2==0)&&(sz[j]<sz[i]))f[i][1]=max(f[i][1],f[j][2]+1);
			if ((f[j][2]%2==0)&&(sz[j]<sz[i]))f[i][2]=max(f[i][2],f[j][2]+1);
		}
	}
	ans=0;
	for (int i=1;i<=n;i++)ans=max(ans,max(f[i][1],f[i][2]));
	//for (int i=1;i<=n;i++)printf("%d ",f[i][1]);printf("\n");
	//for (int i=1;i<=n;i++)printf("%d ",f[i][2]);
	
	printf("%d\n",ans);
	return 0;
}
