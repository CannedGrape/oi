#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n;
int a[100001];
bool b[100001];
long long sum;
struct node
{
  int a;
  int zz;
}s1[100001],s2[100001],s3[100001];
void init()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",&s1[i].a);
  for(int i=1;i<=n;i++)
    scanf("%d",&s2[i].a);
  for(int i=1;i<=n;i++)
  {
    s1[i].zz=i; 
    s2[i].zz=i;
  }
}
bool cmp(node a,node b)
{
  return a.a<b.a;
}
void work()
{
  sort(s1+1,s1+1+n,cmp);
  sort(s2+1,s2+1+n,cmp);
  for(int i=1;i<=n;i++)
  {
    s3[s1[i].zz].a=i;
    s3[s2[i].zz].zz=i;
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(s3[i].a==s3[j].zz)
      {
        if(j+a[j]>i)
        {
          int k_=j+a[j]-1;
          for(int k=i;k<=k_;k++)
            a[k]++;
          sum=sum+(j-i+a[j]);
        }
        else
        {
          int k_=j+a[j]+1;
          for(int k=i;k>=k_;k--)
            a[k]--;
          sum=sum+(i-j-a[j]);
        }
        sum=sum%99999997;
        break;
      }
    }
  }  
}
int main()
{
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  init();
  work();
  cout<<sum;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
