#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a,n,s=0,i,t;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&a,&n);
	for (i=1;i<=a;i++)
	    {
		 t=i;
		 do
	       {
     	    if (t%10==n)
               s++;
		    t=t/10;
		   }while (t>0);
		}
	printf("%d\n",s);
	return 0;
}
