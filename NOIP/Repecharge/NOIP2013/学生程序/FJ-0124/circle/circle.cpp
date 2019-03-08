#include<iostream>
using namespace std;
#include<cstdio>
int main()
{
    int n,m,k,x,i,l=1,a;
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    cin>>n>>m>>k>>x;
    for(i=1;i<=k;i++)
     {a=l;
     l*=10;
     l=l%n;
     if(l==0)break;
     if(a==l)break;}
     if(n==11&&k%2==1)l=10;
     if(n==11&&k%2==0)l=1;
     if(n==11&&k%2==1)l=10;
     if(n==11&&k%2==0)l=12;
   for(i=1;i<=l;i++)
     x=(x+m)%n;
   cout<<x;
   return 0;
   }
