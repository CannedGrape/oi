#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,x,a,b,i,sum;
int main()
{
  freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  scanf("%d%d",&n,&x);
  for(i=1;i<=n;i++)
  {
	a=i;
	while(a)
	{
	  b=a%10;
	  if(b==x)sum++;
	  a=a/10;
	}
  }
  printf("%d\n",sum);
  return 0;
}
