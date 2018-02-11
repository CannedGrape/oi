#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int maxx(int i,int j)
{
	if (i>=j) return i;
	else return j;
}
int n,hi,m,k=0,l=0,r=0,a[110001],f[110001]={0},i,j,s1,s2;
int main()
{
    freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++) 
	{
		f[i]=maxx(f[i-1],f[i-1]+a[i]-a[i-1]);		
	
}
        cout<<f[n];
		return 0;
} 
