#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
  freopen("circle.in","r",stdin);
  freopen("circle.out","w",stdout);
  int n,m,k,x,x2;
  scanf("%d%d%d%d",&n,&m,&k,&x);
  x2=(m*10)%n;
  k--;
  while(k--)
    x2=(x2*10)%n;
  printf("%d",(x2+x)%n);
//  system("pause");
  fclose(stdin);
  fclose(stdout);
  return 0;
}
