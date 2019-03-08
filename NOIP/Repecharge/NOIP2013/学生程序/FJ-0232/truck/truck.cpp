#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define F(i,j,k) for(i=j;i<=k;i++)
using namespace std;
int a[2001][2001],x,y,z,q,i,j,k,l,n,m;
int minn(int a,int b)
{
	if(a>b)return b;
	return a;
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	cin>>n>>m;
	F(i,0,n+1)
	  F(j,0,n+1)a[i][j]=0;
	F(i,1,m)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
		a[y][x]=z;
	}
	F(i,1,n)
		F(j,1,n)
			F(k,1,n)
			if(minn(a[i][k],a[k][j])>a[i][j])a[i][j]=minn(a[i][k],a[k][j]);
	scanf("%d",&q);
	F(i,1,q)
	{
		scanf("%d%d",&x,&y);
		if(a[x][y]!=0)
		cout<<a[x][y]<<endl;
		else cout<<-1<<endl; 
	}
	return 0;
}
