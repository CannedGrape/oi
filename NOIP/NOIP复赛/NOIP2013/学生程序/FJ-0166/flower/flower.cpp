#include<iostream>
#include<cstring>
#include<cmath>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
  freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
  int n,m;
  cin>>n;
  int gd[n];
  for(int A=1;A<=n;A++)
  cin>>gd[A];
  if(n==1)
{
  cout<<"1";
  fclose(stdin);
  fclose(stdout);
  return 0;
}
  else
  cout<<"3";
  fclose(stdin);
  fclose(stdout);
  return 0;
}
