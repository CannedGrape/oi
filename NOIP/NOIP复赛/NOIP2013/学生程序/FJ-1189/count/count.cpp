#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,x,ans=0;

int main()
{
  int i,k;
  freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  scanf("%d%d",&n,&x);
  for(i=1;i<=n;i++)
  {
	k=i;
    while(k>0) 
	{
	  if(k%10==x) ans++;
	  k/=10;
	}
  }
  printf("%d\n",ans);
  //system("pause");
  return 0;
}
