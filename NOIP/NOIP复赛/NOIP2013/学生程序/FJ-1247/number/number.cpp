#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<stdlib.h>
using namespace std;
int a[1000000][3];
int sb(int x)
{
	int b,s;
	for(int i=0;i<=x;i++)
	for(int j=i;j<=x;j++)
	{
		b=0;
		for(int y=i;y<=j;y++)
		b=b+a[y][0];
		if(i==0||b>s)s=b;
	}
	return s;
}
int main()
{
	int n,t,b;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>n>>b;
    for(int i=0;i<n;i++){cin>>a[i][0];a[i][1]=sb(i);a[i][2]=a[i][1]+a[i][0];}
    a[0][2]=a[0][1];t=a[0][2];
	for(int i=1;i<n;i++)
	{
		if(a[i-1][1]+a[i-1][2]>t)t=a[i-1][2]+a[i-1][1];
		a[i][2]=t;
	}
	sort(a[2],a[2]+n);
	cout<<a[n-1][2]%b;
	fclose(stdin);
	fclose(stdout);
}
