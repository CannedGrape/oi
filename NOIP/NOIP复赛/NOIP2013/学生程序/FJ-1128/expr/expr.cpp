#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
string a;
long long b[200001],s,s1;
char b1[100001];
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
	cin>>a;
	long long i=0,l=a.size(),v=0;
	while(i<l)
	{
	    if(a[i]<='9'&&a[i]>='0')
	    {
			while(a[i]<='9'&&a[i]>='0')v=v*10+a[i]-'0',i++;
			b[++s]=v;  v=0;
		}
		else
		{
		    b1[++s1]=a[i],i++;
 		    while(b1[s1]>=b1[s1-1] && s1!=1)
		    {
			    if(b1[--s1]=='+')b[s-1]+=b[s],s-=1;
			    else b[s-1]*=b[s],s-=1;
			    b1[s1]=b1[s1+1];  b1[s1+1]=0;  b[s+1]=0;
			}
		}
	}
	while(s1>0)
	{
	    if(b1[s1]=='+')b[s-1]+=b[s],s-=1;
		else b[s-1]*=b[s],s-=1;
		b1[s1]=0;  b[s+1]=0;
		s1--;
	}
	cout<<b[1]%10000<<endl;
	return 0;
}
