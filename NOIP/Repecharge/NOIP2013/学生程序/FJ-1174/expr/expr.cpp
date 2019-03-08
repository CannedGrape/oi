#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
char ch;
int f=1,t,k,ans;
int sta[100002],flag[100002];
int work(int a)
{
	a++;
	while(sta[a]!=0) a++;
	a--;
	return a;
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	while(scanf("%c",&ch)!=EOF)
	{
		if(ch>='0' && ch<='9') sta[f]=sta[f]*10+(ch-'0');
		else 
		{
			if(ch=='+') flag[f]=1,flag[f+1]=1,f++;
			else if (ch=='*')flag[f]=2,flag[f+1]=2,f++;
		}
	}
	for(int i=1;i<=f-1;i++)
	{
		if(flag[i]==2)
		{
			t=sta[i]*sta[i+1];sta[i]=0;sta[i+1]=0;sta[i+1]=t;f++;i++;
		}
	}
	for(int i=1;i<=f-1;i++)
	{
		ans+=sta[i];
	}
	printf("%d\n",ans%10000);
	return 0;
}
