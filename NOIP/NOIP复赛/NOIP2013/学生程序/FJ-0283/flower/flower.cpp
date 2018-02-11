#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>
using namespace std;
int f[100001][3],n,a[100001],ans;
int main(){
  freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
   scanf("%d",&n);
   for (int i=1; i<=n; i++)
   {
		scanf("%d",&a[i]);
  f[i][1]=1; f[i][2]=1;
   }
/*  for (int i=1; i<=n; i++)
   for (int j=i+1; j<=n; j++)
    for (int k=i+1; k<=j-1; k++)
     {
	   if (f[i][k][1]%2==1)
	   {
	    if (a[k]<a[j]) f[i][j][1]=max(f[i][j][1],f[i][k][1]+1);
	     else f[i][j][2]=max(f[i][j][2],f[i][k][1]+1);
	   }  
	  else 
       if (a[k]<a[j]) f[i][j][1]=max(f[i][j][1],f[i][k][2]+1); 
	 //==========================================
	 if (f[i][k][2]%2==1) 
	 {
	   if (a[k]<a[j]) f[i][j][1]=max(f[i][j][1],f[i][k][2]+1);
	   else f[i][j][2]=max(f[i][j][2],f[i][k][2]+1);
	 }  
	else 
       if (a[k]>a[j]) f[i][j][2]=max(f[i][j][2],f[i][k][1]+1);  
	 }
   for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    //  printf("%d %d %d %d\n",i,j,f[i][j][1],f[i][j][2]);
	 ans=max(ans,max(f[i][j][1],f[i][j][2]));*/
	 
	for (int i=1; i<=n; i++) 
	 for (int j=1; j<=i-1; j++)
	  {
        if (f[j][1]%2==1)
        {
         if ((a[i]<a[j])||(f[j][1]%3==0)) f[i][1]=max(f[i][1],f[j][1]+1);
	    }
	    else if (a[i]>a[j]) f[i][1]=max(f[i][1],f[j][1]+1);
	 
	    if (f[j][2]%2==1)
        {
          if ((a[i]>a[j])||(f[j][2]%3==0)) f[i][2]=max(f[i][2],f[j][2]+1);
	    }
	    else if (a[i]<a[j]) f[i][2]=max(f[i][2],f[j][2]+1);       
	  }   
  for (int i=1; i<=n; i++)	  
   ans=max(ans,max(f[i][1],f[i][2])); 
   printf("%d",ans);	
  fclose(stdin); fclose(stdout);
}

