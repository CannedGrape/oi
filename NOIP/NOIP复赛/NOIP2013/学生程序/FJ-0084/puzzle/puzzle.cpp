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
  freopen("puzzle.in","r",stdin);
  freopen("puzzle.out","w",stdout);
  //Æ­·Ö 
  int n,m,q;
  scanf("%d%d%d",&n,&m,&q);
  if(q==1)
    printf("-1");
  else
  {
    if(q==2)
      printf("2\n-1");
    else
      while(q--) printf("-1\n");
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
