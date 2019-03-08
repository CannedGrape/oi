#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char a[10000000],d[12]={'\0'};
int b[1000001];
bool x=false;
int main()
{
	int i,j,k=-1,l=0,ans=0,num=-1;
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	gets(a);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!='+'&&a[i]!='*'&&num<0) num=i;
		if(a[i]=='+')
		{
			for(j=num;j<i;j++)
			{
				k++;
				d[k]=a[j];
			}
			k=-1;
			num=-1;
			l++;
			b[l]=atoi(d);
			memset(d,'\0',sizeof(d));
			x=false;
		}
		if(a[i]=='*'&&x==false)
		{
			for(j=num;j<i;j++)
			{
				k++;
				d[k]=a[j];
			}
			k=-1;
			num=-1;
			l++;
			b[l]=atoi(d);
			memset(d,'\0',sizeof(d));
			x=true;
		}
		if(a[i]=='*'&&x==true)
		{
			for(j=num;j<i;j++)
			{
				k++;
				d[k]=a[j];
			}
			k=-1;
			num=-1;
			b[l]*=atoi(d);
			memset(d,'\0',sizeof(d));
		}
		if(i==strlen(a)-1&&x==true)
		{
			for(j=num;j<=i;j++)
			{
				k++;
				d[k]=a[j];
			}
			b[l]*=atoi(d);
		}
		if(i==strlen(a)-1&&x==false)
		{
			for(j=num;j<=i;j++)
			{
				k++;
				d[k]=a[j];
			}
			l++;
			b[l]=atoi(d);
		}
	}
	for(i=1;i<=l;i++)
	{
		ans+=b[i];
	}
	ans%=10000;
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
