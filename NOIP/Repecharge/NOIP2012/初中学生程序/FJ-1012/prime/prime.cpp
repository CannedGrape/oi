#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
long long p;
int ans;
bool pd;
int s;
int main()
{  freopen("prime.in","r",stdin);
   freopen("prime.out","w",stdout);
   int n;
   long long i,j;
   cin>>p;
   n=1;
   while (n<=p)
   {  if (n*n<=p)
      {  s=n;
         n++;}
      else
        break;}
   ans=0;
   pd=true;
   for (i=n;i<=p/2;i++)
   {  if (p%i==0)
      {  for (j=2;j<i;j++)
         {  if (i%j==0)
              pd=false;}
         if (pd==true&&i>ans)
           ans=i;}
   }
   cout<<ans<<endl;
   fclose(stdin);
   fclose(stdout);
return 0;
}
