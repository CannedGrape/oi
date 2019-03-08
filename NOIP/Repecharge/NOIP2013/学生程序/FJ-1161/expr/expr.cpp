# include<iostream>
# include<cstdio>
# include<cstdlib>
# include<cstring>
# include<string>
# include<cmath>
# include<algorithm>
using namespace std;
long a[100005],la=0,lb=0,c[100005];
char b[100005];
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	
	long i;
	char x;
	bool flag=0;
	scanf("%c",&x);
	for (;x!='\n';)
	{
		 if (x>='0' && x<='9') a[la]=a[la]*10+x-48;
		 if (x=='+')
		 {
			  if (b[lb]=='+') a[la-1]+=a[la],a[la]=0,la--;
			  else
			  {
				   if (b[lb]=='*') a[la-1]*=a[la],a[la]=0,la--,b[lb]=x;
				   else b[lb]=x;
			  }
			  la++;
		 }
		 if (x=='*') 
		 {
			  if (b[lb]=='*' || b[lb]=='+') b[++lb]=x;
			  else b[lb]=x;
			  la++;
		 }
		 scanf("%c",&x);
	}
	
	for (;lb>=0;) 
	{
		 if (b[lb]=='+') a[la-1]=a[la]+a[la-1],a[la]=0,la--,lb--;
		 else a[la-1]=a[la]*a[la-1],a[la]=0,la--,lb--;
	}
	
	for (i=0;i<4;i++) 
	{
		 c[i]=a[0]%10,a[0]/=10;
	     if (a[0]==0) break;
	}
	for (i=3;i>=0;i--) 
	{
		if (c[i]>0) flag=1;
		if (flag==1) printf("%d",c[i]);
	}
	printf("\n");
	return 0;
}
