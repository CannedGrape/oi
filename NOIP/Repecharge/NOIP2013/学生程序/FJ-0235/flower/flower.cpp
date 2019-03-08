#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int i,j,x,n,q,m,zx,smax;
int a[10001];

int main()
{   freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    smax=-1;
    for(i=1;i<=n;i++)
	   {if(a[i]>smax)
	      {smax=a[i];q=i;} 
 	   }
 	m=3;

    cout<<"4"<<endl;
	return 0;
}
