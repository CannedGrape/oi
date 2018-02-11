#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
char s[200000];long long Stack[100000];
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	scanf("%s",s);int i=0,len=strlen(s),top=0;int a,b,res=0;long long t;
	while (i<len-1)
	{
		a=i;t=0;while (s[i+1]>=48&&s[i+1]<=57) i++;b=i;for (i=b;i>=a;i--) t+=(s[i]-48)*pow(10,double(b-i));i=b;
		if (s[i+1]=='+') Stack[top]=t,top++,i+=2;
		else
		{
			Stack[top]=t;
			while (s[i+1]=='*')
			{
				i+=2;a=i;t=0;while (s[i+1]>=48&&s[i+1]<=57) i++;b=i;for (i=b;i>=a;i--) t+=(s[i]-48)*pow(10,double(b-i));i=b;
				Stack[top]*=t;
				top++;
			}
		}
	}
	a=i;t=0;for (i=len-1;i>=a;i--) t+=(s[i]-48)*pow(10,double(len-1-i));
	if (s[a-1]=='+') Stack[top]=t,top++;if (s[a-1]=='*') Stack[top-1]*=t,top++;
	for (i=0;i<top;i++) res=(res+Stack[i])%10000;
	cout<<res<<endl;
	return 0;
}
