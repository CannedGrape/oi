#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int stack[10000],pd[10000],top=1,tail=1,n;
char ch;
int main()
{
    //freopen("expr.in","r",stdin);
	//freopen("expr.out","w",stdout);
	while(1)
	{
		ch=getchar();
		if(ch=='\n') 
		{
			stack[tail]=n;
			tail--;
			break;
		}
		if(isdigit(ch))
		{
			n=n*10+ch-'0';
		}
		if(ch=='+')
		{
			stack[tail]=n;
			pd[top]=1;
			tail++;
			top++;
			n=0;
		}
		if(ch=='*')
		{
			stack[tail]=0;
			pd[top]=2;
			tail++;
			top++;
			n=0;
		}
		for(int i=1;i<=top;i++)
		{
			if(pd[i]==2) 
			stack[i+1]*=stack[i],stack[i]=0;
		}
		for(int i=1;i<=tail;i++)
		{
			if(stack[i]>0) stack[i+1]+=stack[i],stack[i]=0;
		}
	}
	printf("%d",stack[2]);
	return 0;
}
