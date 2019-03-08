#include<iostream>
using namespace std;
int n;
int h[100001];
int sum1=0;
int sum2=0;
void init()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",&h[i]);
}
void work()
{
  int i;
  i=1;
  while(i<n)
  {
    while(h[i]<=h[i+1])
      i++;
    sum1++;
    if(i!=n)
    {
      while(h[i]>=h[i+1])
        i++;
      sum1++;
    }
  }
  i=1;
  while(i<n)
  {
    while(h[i]>=h[i+1])
      i++;
    sum2++;
    if(i!=n)
    {
      while(h[i]<=h[i+1])
        i++;
      sum2++;
    }
  }
}
void out()
{
  cout<<max(sum1,sum2);
}
int main()
{
  freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
  init();
  work();
  out();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
