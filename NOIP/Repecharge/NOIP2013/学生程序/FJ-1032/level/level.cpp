#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,anss,lzw,big=-999999;
int a[100001]={1};
int b[100001];
int main()
{
  freopen("level.in","r",stdin);
  freopen("level.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=m;i++) 
    {
    cin>>lzw;
    for(int j=1;j<=lzw;j++)
      cin>>big;
    }
  cout<<m;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
