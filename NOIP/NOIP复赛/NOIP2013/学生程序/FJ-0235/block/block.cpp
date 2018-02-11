#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int i,j,n,p,q,ans=0,smin,w,zx;
int a[100001];
int qwe(int x,int y)
{   
	if(w==0)   return ans ;
	else
    {
	 if(x<=y) 
   	  {smin=100000007;
	   for(i=x;i<=y;i++)
        {if(a[i]<smin)
           {smin=a[i];
		    q=i;}
	    }
      ans=ans+smin;
      for(j=x;j<=y;j++)
        {a[j]=a[j]-smin;
		 w=w-smin;}
	 
      qwe(x,q-1);
      qwe(q+1,y);
	}
	}
       
}
int main()
{   freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
	w=0;
    cin>>n;
    for(i=1;i<=n;i++)
       {cin>>a[i];w=w+a[i];}
    zx=qwe(1,n);
    cout<<zx<<endl;
	return 0;
}
