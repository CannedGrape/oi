#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

int n,m,a[101];

int flower(int i,int j,int x[])
{
  int f=0,k;
  if(j==m)
  {
    return 1;
  }
  else
  {
    x[i]++;
    if(i==0)
    {
      i=1;
    }
    for(k=i;k<=n;k++)
    {
	  if(x[k]<a[k])
	  {
        f=f+flower(k,j+1,x);
	  }
	}
	return f%1000007;
  }
}

int main()
{
  freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
  scanf("%d%d",&n,&m);
  int i,x[101];
  for(i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    x[i]=0;
  }
  printf("%d",flower(0,0,x));
  fclose(stdin);
  fclose(stdout);
  return 0;
}
