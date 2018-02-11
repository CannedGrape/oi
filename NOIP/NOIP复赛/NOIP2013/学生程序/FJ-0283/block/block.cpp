#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>
using namespace std;
int n,ans,MAX,a[100001];
int main(){
  freopen("block.in","r",stdin);
  freopen("block.out","w",stdout);
   scanf("%d",&n);
   ans=999999;
   for (int i=1; i<=n; i++)
    {
	  scanf("%d",&a[i]);
	  if (a[i]<ans) ans=a[i];
	  if (a[i]>MAX) MAX=a[i];
	}
   if (n<=1000)	
     {
	   int k=ans+1;
	   while (k<=MAX)
	   {
	   int i=1;
	   while (a[i]<k&&i<=n) i++;
	   while (i<=n)
	     {
	      if (a[i]>=k)  {i++; if (i>n) ans++;}
		  else {
		        while (a[i]<k&&i<=n) i++; 
			    ans++;
			   }
		 }
	    k++; 
	   }
	   printf("%d",ans);  
	 }	  
  fclose(stdin); fclose(stdout);
}

