//rp++
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;
int  n,m,k,j,x;
int i;
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&x);
	if(n==0||n==5||n==10) 
	{
		cout<<x<<endl;
		return 0;
	}
	if(k<1000000)
	{
		j=10;
		for(i=2;i<=k;i++)
		{
			j=j*10;
			j=j%n;
		}
		j=j*m;
		j=j%n;
		j=j+x;
		j=j%n;
		cout<<j<<endl;
		return 0;
		
	}
	else
	{
		j=10 % n;
		if(j>1)
		{
		for(i=2;i<=k;i++)
		{
			j=j*j;
			j=j%n;
		}
	    }
		j=j*m;
		j=j%n;
		j=j+x;
		j=j%n;
		cout<<j<<endl;
		return 0;
	}
	return 0;
} 
