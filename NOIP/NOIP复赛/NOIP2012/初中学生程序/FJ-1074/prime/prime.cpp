#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
  freopen("prime.in","r",stdin);
  freopen("prime.out","w",stdout);
  int n,i,j,k;
  scanf("%d",&n);
  for(i=2;i<=n/2;i++)
  {
    if(n%i==0)
    {
      j=n/i;
      for(k=2;k<=j/2;k++)
      {
	    if((i%k==0 && i!=k) || j%k==0)
	    {
	      k=0;
	      break;
		}
      }
      if(k)
      {
      	printf("%d\n",j);
      }
      break;
    }
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
