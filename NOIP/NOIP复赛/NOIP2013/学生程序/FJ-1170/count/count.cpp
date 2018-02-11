#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int a,b,i,j,e,jl;
int main()
{
  freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  cin>>a>>b;
  for(i=1;i<=a;i++)
   {
    j=i;
    while(j!=0)
	 {
		if(j%10==b)jl++;
		j/=10;
	 }
   }
   cout<<jl<<endl;
}
