#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
char d[22];
char a[100010];
int b[100010];
int main()
{
	int s,o=1,s1,a1=1,b1=1,i=0,j=0,i1=1,j1=1;
	while (scanf("%c",&d[o])==1)
	{
	    while (isdigit(d[o]))
	    {
		    o++;
	        scanf("%c",&d[o]);
	    }
	    if (o>1) b[b1]=(d[o-1]-48);
	    if (o>2) b[b1]+=(d[o-2]-48)*10;
	    if (o>3) b[b1]+=(d[o-3]-48)*100;
	    if (o>4) b[b1]+=(d[o-4]-48)*1000;
	    a[a1]=d[o];
	    o=1;a1++;b1++;
	}
	a1-=2;b1--;
	while (j1<=a1 || j>0)
	{
		if (a[i1]=='*') 
		{
		    b[j1+1]*=b[j1];
			i1++;
			j1++;
			b[j1]%=10000;
			continue;
		}
		if (a[i1]=='+' && a[i1+1]=='*')
		{
			i=i1;j=j1;i1++;j1++;
			while (a[i1]=='*')
			{
				b[j1+1]*=b[j1];
				i1++;
				j1++;
			b[j1]%=10000;
			}
			b[j1]+=b[j];
			b[j1]%=10000;i=0;j=0;
			b[j1+1]+=b[j1];
			i1++;
			j1++;
			b[j1]%=10000;
			continue;
		}
		if (a[i1]=='+')
		{
		    b[j1+1]+=b[j1];
			i1++;
			j1++;
			b[j1]%=10000;
		}
	}
	b[j1]%=10000;
	printf("%d",b[b1]);
	return 0;
}
