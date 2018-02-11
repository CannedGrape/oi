#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int n,ma,ans;
bool ok;
int a[100001];
int main()
{
 freopen("block.in","r",stdin);
 freopen("block.out","w",stdout);
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
   {scanf("%d",&a[i]);
	if(a[i]>ma) ma=a[i];}
 for(int j=1;j<=ma;j++)
     {ok=false;
	   if(a[n]>0)ans++;
	   for(int i=1;i<=n;i++)
	      if(a[i]>0)
		   {a[i]--;ok=true;}
		  else
		     {if(ok==true) ans++;
			   ok=false;}
	 }
 printf("%d\n",ans);
return 0;	
}