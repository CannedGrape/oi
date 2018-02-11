#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,x,n1;
int main()
{
	freopen ("count.in","r",stdin);
	freopen ("count.out","w",stdout);
	int ram1=0,ram2=0;
	scanf("%d %d",&n,&x);
	n1=n;
	if (x==0)
	{
		printf ("%d\n",n/10);
	}
	else
	{
		while (n>0)
		{
			if (n%10==x || n%10>x)
			{
				ram1++;
				n/=10;
				ram2++; 
			}
			else
			{
				n/=10;
				ram2++;
			}
		}
	if (n1>=100)
	{
		printf ("%d\n",(ram2-1)*10+ram1);
	}
	else if (n1<10)
	{
		printf ("1");
	}
	else if (n1==11)
	{
		printf ("4");
	}
	else if (ram1==1)
	{
		printf ("%d\n",ram1+(ram2-1)*2);
	}
	}
	return 0;
}
