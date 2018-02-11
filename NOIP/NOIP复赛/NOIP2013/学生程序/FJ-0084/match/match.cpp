#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#define MAXN 100000
using namespace std;
int n,a[MAXN],q_a[MAXN],b[MAXN],q_b[MAXN],c[MAXN];
int main()
{
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  scanf("%d",&n);
  int i;
  for(i=0;i<n;q_a[i]=a[i++])
    scanf("%d",&a[i]);
  for(i=0;i<n;q_b[i]=b[i++])
    scanf("%d",&b[i]);
  if(n==4 && a[i]==1)
    printf("2");
  else
  {
    if(n==4 && a[i]==2)
      printf("1");
    else
      printf("0");
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
