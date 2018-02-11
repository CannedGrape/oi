#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int i,n,x,s1=0;
int pd(int s,int k)
{
  int sum=0;
  while(s>0){if(k==(s%10))sum++;s/=10;}
  return sum;
}
int main()
{
  freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  cin>>n>>x;
  for(i=1;i<=n;i++)
    s1+=pd(i,x);
  cout<<s1<<endl;
  return 0;
}
