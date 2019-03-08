#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m,ans=0;
bool a[1011][1011]={0};
int f[1011]={0},mina[1011],maxa[1011];
int main()
{
	freopen("level.in","r",stdin);
        freopen("level.out","w",stdout);
	int i,j,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&y);
		for(j=1;j<=y;j++) 
		{
			scanf("%d",&x);
			if(j==1) mina[i]=x;
			if(j==y) maxa[i]=x;
			a[i][j]=1;
			f[j]=1;
		}
	}
	ans=m;
	printf("%d\n",ans);
	return 0;
}