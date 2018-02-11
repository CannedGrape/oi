#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[100000001];
int n,a[100000001],b[100000001],k=1;
__int64 c[100000001];
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	
	cin >> s;
	n=strlen(s);
	for(int o=0;o<n;o++)
	{
	  a[o]=s[o]-'0';
	  if(a[o]==-5){a[o]=10;b[o]=1;}
	  if(a[o]==-6){a[o]=11;b[o]=2;}
	}	
	int j=1;
	for(int i=n-1;i>=0;i--)
	{
	  if(b[i]==0)
	  {
		c[j]+=a[i]*k;
		k*=10;
	  }
	  else
	  {
		j++;
		if(b[i]==1) c[j]=-1;
		if(b[i]==2) c[j]=-2;
		j++;
		k=1;
	  }
	}
	for(int i=2;i<j;i++)
	  if(c[i]==-2)
	  {
	    c[i-1]*=c[i+1];
	    for(int o=i+2;o<=j;o++)
		  c[o-2]=c[o];
		c[j]=0;
		j--;
	  }j--;
	for(int i=2;i<j;i++)
	  if(c[i]==-1)
	  {
	    c[i-1]+=c[i+1];
	    for(int o=i+2;o<=j;o++)
		  c[o-2]=c[o];
		c[j]=0;
		j--;
	  }
	c[1]+=c[3];
	cout << c[1]%10000 << endl;
	return 0;
}
