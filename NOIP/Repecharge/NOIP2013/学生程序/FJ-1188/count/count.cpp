#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
  short x;
  int n,i,m,cs=0;
  freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  cin>>n>>x;
  for(i=1;i<=n;i++)
  {
    m=i;
    while(m!=0){if(m%10==x)cs++;m/=10;}
  }
  cout<<cs<<endl;
  return 0;
}

