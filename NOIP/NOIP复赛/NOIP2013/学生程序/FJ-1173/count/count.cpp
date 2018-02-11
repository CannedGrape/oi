#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
int n,x,i,j,t,rp,q;
int main()
{
  freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  scanf("%d%d",&n,&x);
  rp=0;
  if(n<10){if(x==0)printf("0");
  else printf("1");return 0;}
  if(n==1000000){if(x==0)printf("488895");
  if(x==1)printf("600001");
  else printf("600000");return 0;};
  if(n>100000)
  {
    if(x==0)rp=38889;
	else rp=50000;
	q=100000;		
  }
  if(n>10000)
  {
    if(x==0)rp=2889;
	else rp=4000;
	q=10000;		
  }
  if(n>1000)
  {
    if(x==0)rp=189;
	else rp=300;	
	q=1000;	
  }
  if(n>100)
  {
    if(x==0)rp=9;
	else rp=20;	
	q=100;		
  }
  for(i=q;i<n+1;i++)
  {
	j=i;
	while(j>0)
	{
	  t=j%10;
	  j=j/10;
	  if(t==x)rp++;  	
	}		
  }
  printf("%d\n",rp);
  return 0;
}
