#include<iostream>
#include<cstdio>
using namespace std;
int ans,a[100000],i=1;
char ch;bool d=true;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	while(scanf("%c",&ch)!=EOF)
	{
		
		if(isdigit(ch))a[i]=(a[i]*10+int(ch)-48)%10000;
	    else 
	    {
			if(d==false)d=true,a[i-1]*=a[i],a[i--]=0,a[i-1]%=10000;
		    if(ch=='*')d=false;
		    i++;
	    }
	}
	if(d==false)d=true,a[i-1]*=a[i],a[i--]=0;
	for(int j=1;j<=i;j++)
		a[j]+=a[j-1],a[j]%=10000;
	printf("%d\n",a[i]%10000);
	return 0;
}
