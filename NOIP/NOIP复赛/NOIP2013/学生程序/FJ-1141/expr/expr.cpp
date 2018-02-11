#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int sz[100001],ls,lf,l;
char str[100010],fh[100001];
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	int i;
	scanf("%s",str);
	l=strlen(str);
	str[l]='+';
	l++;
	ls=0;lf=0;
	for(i=0;i<=l-1;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			ls++;
			while(str[i]>='0'&&str[i]<='9')
			{
				sz[ls]=sz[ls]*10+str[i]-'0';
				i++;
			}
			i--;
			if(sz[ls]>10000)
			{
				sz[ls]=sz[ls]%10000;
			}
		}
		else
		{
		   if(str[i]=='+')
	   	   {
			   while(lf>=1)
			   {
				   if(fh[lf]=='*')
				   {
			          sz[ls-1]=sz[ls]*sz[ls-1];
			          sz[ls]=0;
			          ls--;lf--;
			       }
			       else if(fh[lf]=='+')
			       {
				      sz[ls-1]=sz[ls]+sz[ls-1];
				      sz[ls]=0;
				      ls--;lf--;
				   }
				    if(sz[ls]>10000)
			        {
			         	sz[ls]=sz[ls]%10000;
		        	}
			   }
			   lf++;
			   fh[lf]='+';
		   }
		   else
		   {
				if(str[i]=='*')
				{
					lf++;
					fh[lf]='*';
				}
		   }
		}
	}
	printf("%d\n",sz[1]);
	return 0;
}
