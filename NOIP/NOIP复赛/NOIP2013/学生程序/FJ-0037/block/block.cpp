#include<stdio.h>
#include<iostream>
using namespace std;
int n;
int h[100001];
long long sum;
void init()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",&h[i]);
}
void work()
{
  sum=sum+h[1];
  for(int i=1;i<n;i++)
  {
    if(h[i+1]>h[i])
      sum=sum+h[i+1]-h[i];
  }
}
int main()
{
  freopen("block.in","r",stdin);
  freopen("block.out","w",stdout);
  init();
  work();
  cout<<sum;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
