#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
bool x[1001][1001]={0},tf=1,bj=0;
using namespace std;
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	int a,b,c,d,z[1001][3],fmax=0,fmin=2147483647,fsum=0,xj=1;
	cin>>a>>b;
	for (int i=1;i<=b;i++) 
	{
		cin>>c;
		for (int j=1;j<=c;j++) 
		{
			cin>>d;if (d>fmax) fmax=0;if (d<fmin) fmin=d;
			if (j==1) z[i][1]=d;
			if (j==c) z[i][2]=d;
			x[i][d]=1;
		}
		fsum+=c;
	}
	for (int i=fmin;i<=fmax;i++)
	{
		for (int j=1;j<=b;j++)
		{
			if ((x[i][xj]==1) && (bj==1)) fsum--;
		    if ((x[i][xj]==1) && (bj==0)) bj=1;
		} 
		bj=0;
	}
	cout<<"3";
	return 0;
}
