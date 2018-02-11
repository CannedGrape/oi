#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[100001],i,j,ans=0,ma=0;
bool dog1(int m)
{
   for(i=2;i<=m;i+=2)
     if(i==m){if(a[i]>=a[i-1]) return 0;
     } else if(a[i]>=a[i+1]||a[i]>=a[i-1]) return 0;
     return 1;
}
bool dog2(int m)
{
for(i=2;i<=m;i+=2)
    if(i==m){if(a[i]<=a[i-1]) return 0;} else if(a[i]<=a[i+1]||a[i]<=a[i-1]) return 0;
 return 1;}
void simon(int m)
{
	if(m<=1){if(ma<m)ma=m;return;
	}
	int i,j,temp;
	if (dog1(m)==1||dog2(m)==1)
	{if(ma<m)ma=m;
	}
   else
   {
    	for(i=1;i<=n;i++)
		{
		   temp=a[i];for(j=i;j<n;j++) a[j]=a[j+1];a[n]=temp;
		   simon(m-1);
		   temp=a[n];for(j=n;j>=i;j--) a[j]=a[j-1];
		   a[i]=temp;
		}	
}
}
int main()
{
	 freopen("flower.in","r",stdin);
	   freopen("flower.out","w",stdout);
     cin>>n;ans=n;
       for(i=1;i<=n;i++)
         {cin>>a[i];}
         simon(ans);
         cout<<ma;
         return 0;
}
