#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[100001],ans=0,r;
char x[100001];
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	int l,i,s,j;
	bool f=0;
	gets(x);
	l=strlen(x);
	r=0;
	for (i=0;i<l;i++)
	{
		if(x[i]!='*' && x[i]!='+')
		{
			s=0;
			while (x[i]!='*' && x[i]!='+' && i<l)
			{
				s*=10;s+=int(x[i])-48;
				s%=10000;i++;
			}
			i--;
			r++;a[r]=s;
			if(f==1)
			{
				a[r-1]=a[r]*a[r-1]%10000;r--;
				f=0;
			}
			
		}
		if(x[i]=='*') f=1;
	}
	for(i=1;i<=r;i++)
	ans+=a[i];
	cout<<ans<<endl;
	return 0;
}