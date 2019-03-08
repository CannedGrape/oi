#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int n ,h[100001],i,m=2147483647,ans=0,ma=0;
void simon(int l)
{
	if(l>ma) {cout<<ans;return;}
	  int i,j,k;
	  for(i=1;i<=n;i++)
	  {if(h[i]!=0&&h[i-1]==0)ans++;
		}
		for(i=1;i<=n;i++)
		 if(h[i]!=0) h[i]--;
		simon(l+1);
}
int main()
{
   
   freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
   cin>>n;
   h[0]=0;
    for(i=1;i<=n;i++)
        {cin>>h[i];
      if(m>h[i])  m=h[i]; 
	  if(ma<h[i]) ma=h[i]; }    
         ans=m;
        for(i=1;i<=n;i++)
         h[i]=h[i]-m;
         simon(1);
        return 0;
}
