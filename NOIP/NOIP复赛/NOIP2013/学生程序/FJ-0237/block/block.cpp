#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[100001];
int n,i,j,t=0,h;

int zz(int x,int y)
{int i;
 for(i=x+1;i<=y-1;i++) 
   {a[i]--;}
 t++;
}
int main()
{freopen("block.in","r",stdin);
 freopen("block.out","w",stdout);
 cin>>n;
 for(i=0;i<=n+1;i++) a[i]=0;
 for(i=1;i<=n;i++)
   {cin>>a[i];
    if(a[i]>h) h=i;}
 while(a[h]!=0)
 {for(i=0;i<n;i++)
   if(a[i]==0 && a[i+1]!=0)
    {for(j=i+2;j<=n+1;j++)
	   {if(a[j]==0 && a[j-1]!=0) {
	    zz(i,j);
	    while(a[j+1]==0 && j+1<n) j++;
	    i=j;
		}}
    }
 }
 cout<<t;
 return 0;
}
