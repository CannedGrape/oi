#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int n,x;
char s[100002];
int d[50002];
char c[50002];
int ans=0,L1=0,L2=0,sum=0;
bool flag=0;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	scanf(" %s",s); int L=strlen(s); s[L]=' ';
	for (int i=0;i<=L;i++)
	{
		if (i==0 || (!isdigit(s[i-1]) && isdigit(s[i])))
			ans=s[i]-'0';
		else
		{
			if (!isdigit(s[i]))
			{
				c[++L2]=s[i],d[++L1]=ans%10000;
				if (flag)
				{
					L2--;
					d[L1-1]=d[L1-1]*d[L1]%10000;
					L1--;
					flag=0;
				}
				if (s[i]=='*')flag=1;
			}
			else
			{
				ans=ans*10+s[i]-'0';
				ans=ans%10000;
			}
		}
	}
	for (int i=1;i<=L1;i++)
		sum+=d[i];
	printf("%d\n",sum);
	return 0;
}
