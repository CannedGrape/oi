#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
void swap(long & sa,long & sb)
{long sc=sa;sa=sb;sb=sc;}
void abs(long & sd)
{if(sd<0) sd=0-sd;}
int main()
{
  freopen ("match.in","r",stdin);
  freopen ("match.out","w",stdout);
  long n,i,j,k;
  long long s=0;
  cin>>n;
  long  c[100000],a[100000],b[100000],d[100000];
  for(i=1;i<=n;i++)
  {cin>>a[i];c[i]=a[i];}
  for(i=1;i<=n;i++)
  {cin>>b[i];d[i]=b[i];}
  for(i=1;i<=n;i++)
  {
     for(j=2;j<=n;j++)
       {if(a[i]>a[j])
        swap(a[i],a[j]);
       if(b[i]>b[j])
        swap(b[i],b[j]);}
  }
  for(i=1;i<=n;i++)
  {
     for(j=1;j<=n;j++)
      {
       if(a[i]==c[j])
         {for(k=1;k<=n;k++)
           if(b[k]==d[j])
             s=s+abs(i-k);
         }
      }
  }
  s=s/2;
  s=s%99999997;
  cout<<s;
  fclose(stdin);
  fclose(stdout);
  //system("pause");
  return 0;
}
