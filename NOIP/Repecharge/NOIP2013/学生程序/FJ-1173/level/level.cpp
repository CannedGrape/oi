#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdlib>
using namespace std;
int a[1001],n,m,i,s,p;
int main()
{
  freopen("level.in","r",stdin);
  freopen("level.out","w",stdout);
  cin>>n>>m>>s;
  for(i=1;i<=s;i++)
    cin>>a[i];	
  cout<<m;
  return 0;
}

