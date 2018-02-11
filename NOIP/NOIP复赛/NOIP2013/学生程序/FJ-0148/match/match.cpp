#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{ 
   int n,a[100001],b[100001],a1[100001],b1[100001],i,t;
   freopen("match.in","r",stdin);
   freopen("match.out","w",stdout);
   cin>>n;
   for(i=1;i<=n;i++)   {cin>>a[i];a1[i]=a[i];}
   for(i=1;i<=n;i++)   {cin>>b[i];b1[i]=b[i];}     
   sort(a+1,a+n+1);
   sort(b+1,b+n+1);
   for(i=1;i<=n;i++)
      {
         if(a[i]!=b[i]) t++;
      }
   cout<<t%2+1<<endl;
   return 0;
}
