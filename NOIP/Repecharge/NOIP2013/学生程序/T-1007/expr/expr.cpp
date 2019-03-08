#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string s,t;
char a[100001];
int k=1,n[100002],u=0;
int Ten_Pow(int i)
{
	int pow=1;
	for (int j=1;j<=i;j++)
	    pow=pow*10;
	return pow;
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	for (int i=s.size();i>=0;i--)
	    {
		 if (s[i]>='0' && s[i]<='9')
		    {
		     n[k]=n[k]+(s[i]-48)*Ten_Pow(u);
		     u++;
			}
		 if (s[i]=='+' || s[i]=='*')
		    {
			 a[k]=s[i];
			 k++;
			 u=0;
			}
		}
	for (int i=1;i<=k-1;i++)
		if (a[i]=='*')
	       {
    	    n[i+1]=(n[i]%10000)*(n[i+1]%10000)%10000;
		    n[i]=0;
		    a[i]='+';
		   }
	for (int i=2;i<=k;i++)
	    n[i]=(n[i-1]%10000+n[i]%10000)%10000;
	printf("%d\n",n[k]);
	return 0;
}
