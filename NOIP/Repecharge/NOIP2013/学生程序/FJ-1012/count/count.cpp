#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,key,sum=0;
int count(int x)
{
  if(x==0)  return 0;
  if(x%10==key)  return count(x/10)+1;
  return count(x/10);
}
int main()
{
  freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  scanf("%d%d",&n,&key); 
  for(int i=1;i<=n;i++)  sum=sum+count(i);
  printf("%d\n",sum); 
  fclose(stdin);
  fclose(stdout);
  return 0;
}
