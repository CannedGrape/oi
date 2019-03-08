#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int i,j,k,m,n,a[101001],b[100101],c[101001],d[101001];
long l=0;
int swapp(int i,int j)
{
	int s;
	s=i;i=j;j=s;
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++){scanf("%d",&a[i]);c[i]=a[i];}
	for(i=1;i<=n;i++){scanf("%d",&b[i]);d[i]=b[i];}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++)
	{
		l=l+(a[i]-b[i])*(a[i]-b[i])
		}
		
}
