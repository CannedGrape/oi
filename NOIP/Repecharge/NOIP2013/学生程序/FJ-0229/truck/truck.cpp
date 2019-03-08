#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int m,n,k,q,r,i,j,x,y,z,a[1001][1001]={0},b,e,num,sum=214743940,qq=0;
bool wp=0;
int dfs(int k)
{
	int i,r;
	if (k==e) {cout<<sum<<endl;qq=1;}
	else 
	{
		for(i=1;i<=n;i++)
		if(a[k][k+i]>0&&k+i<=n)
		{   
			if(sum>a[k][k+i])r=sum;sum=a[k][k+i];
			a[k][k+i]=-1;
			dfs(k+i);
			a[k][k+i]=sum;
			sum=r;
			}
			if(a[k][k-i]>=0&&k-i>=1)
		{
			if(sum>a[k][k-i])r=sum;sum=a[k][k-i];
			a[k][k-i]=-1;
			dfs(k-i);
			a[k][k-i]=sum;
			sum=r;
			}
		}
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{scanf("%d%d%d",&x,&y,&z);
	if(a[x][y]<=z)a[x][y]=z;
}
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>b>>e;qq=0;
		dfs(b);
		if (qq==0)cout<<"-1"<<endl;
		}	
		return 0;
}
