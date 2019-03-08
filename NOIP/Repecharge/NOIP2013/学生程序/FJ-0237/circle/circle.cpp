#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{int i,j,ans=0,yy;
 int n,m,k,x;
 freopen("circle.in","r",stdin);
 freopen("circle.out","w",stdout);
 cin>>n>>m>>k>>x;
 yy=m*10;
 if(k=1) {yy=yy%n;}
 else
  {for(i=1;i<=k;i++)
    {yy=yy%n;
     yy=yy*10;}}
 ans=x+yy;
 if(ans>=n) {ans=ans-n;}
 cout<<ans;
 return 0;
}
