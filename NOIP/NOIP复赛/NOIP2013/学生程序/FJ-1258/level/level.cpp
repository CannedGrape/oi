#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a,b[500000]={0},c[500000]={0},e=0;
long p,p1;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	int max[500000]={0},max1,max2=0,max3=0;
	cin>>a>>p;
	for(int i=0;i<a;i++)
	{
		cin>>b[i];
	}
	for(int i1=0;i1<a;i1++)
	{for(int i=0;i<a;i++)
	{
	    for(int j=i-1;j<=0;j--)
	    {
			e=b[j]+e;
			if(max[i]<e)
			max1=e;
		}
		if(max[i]>max3)max3=max[i];
	}
	c[i1]=e;
	e=0;
    }
	b[0]=c[0];
	for(int i=0;i<a;i++)b[i]=0;
	for(int i1=0;i1<a;i1++)
    {
	    for(int i=0;i<a;i++)p1+=c[i];
    	b[i1]=p1;
        p1=0;
    }
    for(int i=0;i<a;i++)
    {
    	if(b[i]>max2)max2=b[i];
    }
    cout<<max2%p;
    fclose(stdin);
	fclose(stdout);
}
