#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long s,k,n,p,i,j,a[1000000][3],m1=0,m2;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>p;
	for(i=0;i<n;i++)
	{
		a[i][1]=-99999;
		a[i][2]=-99999;
		a[i][3]=-99999;
	}
	for(i=0;i<n;i++)cin>>a[i][0];
	a[0][2]=a[0][0];
	a[0][1]=a[0][0];
	m2=a[0][0];
	m1=a[0][0];
	for(i=1;i<n;i++)
	{
	for(j=1;j<=i;j++)
	{
	for(k=j;k<=i;k++)
	{m1+=a[k][0];if(m1>a[i][2]) a[i][2]=m1;}m1=0;}
	for(s=0;s<i;s++) 
	if(a[s][1]+a[s][2]>m2)
	{
		m2=a[s][1]+a[s][2];
		a[i][2]=a[s][1]+a[s][2];
	}
	m1=0;
    }
    cout<<m2%p;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
