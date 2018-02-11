#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
char a[10000000];
int main()
{
	int beg=0,beg1=0,ans=0,i;
	bool c=true;
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	gets(a);
	int nn=strlen(a);
	a[nn]='+';
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]>='0'&&a[i]<='9'&&c)
		{
			beg=beg*10+a[i]-48;	
			if(beg>10000)
			beg=beg%10000;
		}
		else
			if(a[i]>='0'&&a[i]<='9')
			{
				beg1=beg1*10+a[i]-48;
				if(beg1>10000)
				beg=beg%10000;	
			}
		if(a[i]=='+')
		{
			if(c)beg1=1;
			ans=ans+(beg1*beg)%10000;
			c=true;
			beg=0;
			beg1=0;
		}
		if(a[i]=='*')
		{
			c=false;
			if(beg1!=0)
			{
				beg=(beg*beg1)%10000;
				beg1=0;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
