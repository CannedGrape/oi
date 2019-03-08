#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
char temp[1100011];
int l=0,r;
int sum=0;
char a[10],b[10];
int ad=10,bd=-1,adtemp=-1;
int su[100002],sud=0,muqian=1;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	gets(temp);
	for(int i=0;i<strlen(temp);i++)
	{
		if(temp[i]=='*')
		{
			temp[i]='%';
			for(int y=i-1;y>=0;y--)
			{
				if(temp[y]!='+'&&temp[y]!='*')
				{
					ad--;
					a[ad]=temp[y];
					temp[y]='%';
				}
				else
				break;
			}
			for(int qq=ad;qq<=9;qq++)
			{
				adtemp++;
				a[adtemp]=a[qq];
				a[qq]='\0';
			}
			for(int y=i+1;y<strlen(temp);y++)
			{
				if(temp[y]!='+'&&temp[y]!='*')
				{
					bd++;
					b[bd]=temp[y];
					temp[y]='%';
				}
				else
				break;
			}
			sud++;
			su[sud]=atoi(b)*atoi(a);
			memset(a,'\0',sizeof(a));
			memset(b,'\0',sizeof(b));
			ad=10,bd=-1,adtemp=-1;
		}
	}
	for(int y=0;y<strlen(temp);y++)
	{
		if(temp[y]!='+')
		{
			bd++;
			b[bd]=temp[y];
			temp[y]='%';
		}
		else
		break;
	}
	for(int i=0;i<strlen(temp);i++)
	{
	if(temp[i]=='+')
		{
			for(int y=i+1;y<strlen(temp);y++)
			{
				if(temp[y]!='+'&&temp[y]!='*')
				{
					bd++;
					b[bd]=temp[y];
					temp[y]='%';
				}
				else
				break;
			}
			sud++;
			su[sud]=atoi(b);
			memset(b,'\0',sizeof(b));
			ad=10,bd=-1,adtemp=-1;
		}
	}
	for(int i=1;i<=sud;i++)
	sum+=su[i];
	if((sum-9999)>0)
	{
		sum=sum%10000;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return(0);
}
