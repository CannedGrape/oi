#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int h[100100];
int n;
int f[1002][1002][2];
int ans=0;
void Init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&h[i]);
}
int zmax(int a,int b,int c)
{
	a=max(a,b);
	return max(a,c);
}
void slove()
{	memset(f,0,sizeof(0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=1000;j++) f[i][j][0]=f[i-1][j][0],f[i][j][1]=f[i-1][j][1];
		f[i][h[i]][1]=max(f[i][h[i]][1],1);
		for(int j=1;j<h[i];j++)f[i][h[i]][0]=max(f[i][h[i]][0],f[i-1][j][1]+1);
		for(int j=h[i]+1;j<=1000;j++)f[i][h[i]][1]=max(f[i][h[i]][1],f[i-1][j][0]+1);
	}
	for(int j=1;j<=1001;j++)ans=zmax(ans,f[n][j][1],f[n][j][0]);
	cout<<ans<<endl;
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	Init();
	slove();
	return 0;
}
