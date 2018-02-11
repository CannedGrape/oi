#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n,m;
int s;
int r[1000001][3];
int t[1000001][3];
int ans;
int main()
{  freopen("treasure.in","r",stdin);
   freopen("treasure.out","w",stdout);
   int i,j,p,q;
   cin>>n>>m;
   for (i=0;i<n*m;i++)
   {  for (j=1;j<=2;j++)
        cin>>r[i][j];}
   cin>>s;
   p=1;
   q=s;
   ans=0;
   while (p<=n)
   {  s=r[p*q][2];
      ans+=r[p*q][2];
      ans%=20123;
      while (s>0)
      {  if (q==m-1)
           q=0;
         else
           q++;
         if (r[p*q][1]==0)
           q++;
         else
           s--;
      }
      p++;}
   cout<<ans<<endl;
   fclose(stdin);
   fclose(stdout);
return 0;
}
