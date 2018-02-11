#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
int i,n,x,num=0;
int main()
{
	  freopen("count.in","r",stdin);
      freopen("count.out","w",stdout);
      scanf("%d%d",&n,&x);
      for(i=1;i<=n;i++)
       {
		if(i%10==x)
		  num++;
	    if(i/10%10==x&&i>9)
		  num++;
	    if(i/100%10==x&&i>99)
		  num++;
		if(i/1000%10==x&&i>999)
		  num++;
		if(i/10000%10==x&&i>9999)
		  num++;
		if(i/100000%10==x&&i>99999)
		  num++;
	   }
      printf("%d\n",num);
      return 0;
}
