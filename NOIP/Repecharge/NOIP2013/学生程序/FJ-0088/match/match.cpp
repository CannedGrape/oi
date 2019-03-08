#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct node
{
       int x,y;
       }match[100000];
struct te
{
       int i,zhizhen,sum;
       }temp[100000];
int mod=99999997;
int cmp(void const *c,void const *d)
{
    node *a=(node *)c;
    node *b=(node *)d;
    if(a->x>b->x)
    return 1;
    else 
    return -1;
}
int dmp(void const *c,void const *d)
{
    te *a=(te *)c;
    te *b=(te *)d;
    if(a->i>b->i)
    return 1;
    else 
    return -1;
}
int main()
{
      freopen("match.in","r",stdin);
      freopen("match.out","w",stdout);
      int i,j,n;
      scanf("%d",&n);
      for(i=0;i<n;i++)
      scanf("%d",&match[i].x);
      for(i=0;i<n;i++)
      scanf("%d",&match[i].y);
      qsort(match,n,sizeof(node),cmp);
      for(i=0;i<n;i++)
      {temp[i].i=match[i].y;temp[i].zhizhen=i;temp[i].sum=0;}
      qsort(temp,n,sizeof(te),dmp);
      for(i=0;i<n;i++)
      {
      temp[i].sum+=abs(i-temp[i].zhizhen);
      if(i>temp[i].zhizhen)
      for(j=i;j>=temp[i].zhizhen;j--)
      temp[j].sum-=temp[i].sum;
      }
      int ans=0;
      for(i=0;i<n;i++)
      ans=(ans+temp[i].sum%mod)%mod;
      printf("%d\n",ans);
      fclose(stdin);
      fclose(stdout);
      return 0;
}
