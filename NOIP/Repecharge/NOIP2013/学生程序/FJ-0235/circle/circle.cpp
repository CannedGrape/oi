#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int i,j,n,m,k,x,q,w,p,s;
int a[1000001],b[1000001];
int main()
{   freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    cin>>n>>m>>k>>x;
    for(i=0;i<n;i++)
       a[i]=i;
    i=1;
    while(q!=1)
       { q=1+i*(m-1);
         if(q>n)  q=q-n;
		 b[i]=q-1;
		 i++;
	   }
    i--;
    p=1;
    for(j=1;j<=k;j++)
       p=p*10;
    if(p<=i)
      { w=b[p]+x;
        if(w>n)  w=w-n;
        cout<<w;
	  }
	else
       { 
         s=p%i;
         w=b[s]+x;
         cout<<w;
   	   }

    return 0;
}
