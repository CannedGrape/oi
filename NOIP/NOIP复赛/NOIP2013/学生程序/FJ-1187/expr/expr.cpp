#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long num[100003],s[150002];
short syb[100002];
void Plus(int a)
{
	int p;
	s[150000]+=num[a],p=s[150000]/10,s[150000]%=10;
	for(int i=149999;i>=1&&p>0;i--)
	{
		s[i]+=p,p=s[i]/10,s[i]%=10;
	}
	return;
}
void Prints()
{
	int i;
	for(i=149997;i<=150000&&s[i]==0;i++);
	for(;i<=150000;i++)cout<<s[i];
	cout<<endl;
	return;
}
int main()
{
	char ch;
	int n=0,Pi=1,Pj=1;
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	while(true)
	{
		ch=getchar();
		if(ch=='\n'){num[Pi]=n,Pj--;break;}
		if(isdigit(ch)) n=n*10+(int)ch-48;
		if(ch=='+') num[Pi]=n,syb[Pj]=1,Pi++,Pj++,n=0;
		if(ch=='*') num[Pi]=n,syb[Pj]=2,Pi++,Pj++,n=0;
	}
	for(int j=1;j<=Pj;j++)
	{
		if(syb[j]==2) num[j-1]*=num[j],num[j]=0;
	}
	for(int i=1;i<=Pi;i++)
	{
		if(num[i]>0)Plus(i);
	}
	Prints();
	return 0;
}
