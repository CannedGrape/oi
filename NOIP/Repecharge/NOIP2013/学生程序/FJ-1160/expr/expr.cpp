#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int top=0,f[100001]={0},y[100001]={0};
string str;

void pop()
{
	if(y[top-1]) f[top-1]=(f[top-1]*f[top])%10000;
	else f[top-1]=(f[top-1]+f[top])%10000;
	f[top--]=0;
}

int main()
{
	freopen("expr.in","r",stdin);freopen("expr.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();++i)
	  if(str[i]=='+') {y[top]=0;for(;top;pop());++top;}
	  else if(str[i]=='*') {y[top]=1;for(;top&&y[top-1];pop());++top;}
	  else f[top]=(f[top]*10+str[i]-'0')%10000;
	for(;top;pop());
	printf("%d",f[0]);
	return 0;
}
