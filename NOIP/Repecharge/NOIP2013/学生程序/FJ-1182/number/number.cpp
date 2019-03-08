#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,a[10000],b[10000],c[10000],p,amax=-100000,bmax=-100000,i,j;
	cin>>n>>p;
	for(i=0;i<n;i++)
	    cin>>a[i];
	for(i=0;i<n;i++)
	    for(j=0;j<=i;j++)
			if(a[j]>0) b[i]+=a[j];
			else b[j]=a[j];
	c[0]=b[0];
	for(i=1;i<n;i++)
	{ 
	    for(j=0;j<i;j++)
	        amax=max(b[j]+c[j],amax);
	    c[i]=amax;
	    amax=-100000;
    }
    for(i=0;i<n;i++)
		bmax=max(c[i],bmax);
	cout<<bmax%p<<endl;
	return 0; 
} 
