#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
bool a,b;
int n,m;
int h[100001];

int main()
{int i,j;
 freopen("flower.in","r",stdin);
 freopen("flower.out","w",stdout);
 cin>>n;
 for(i=1;i<=n;i++) cin>>h[i];
 for(i=1;i<=n/2;i++)
   {if(h[2*i]>h[2*i-1]) a=1;
     else a=0;}
 for(i=1;i<n/2;i++)
   {if(h[2*i]>h[2*i+1]) b=1;
     else b=0;}
 if(a==1 && b==1) m=1;
 cout<<m;
 return 0;
}
