#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int len=0,a[1000001]={0},b[1000001]={0};
string s;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin >> s;
	len=s.size();
	int shu=1,fh=1;
	for(int i=0;i<=len-1;i++)
	{
		if(s[i]=='*'){b[fh]=1;fh++;shu++;continue;}
		if(s[i]=='+'){b[fh]=0;fh++;shu++;continue;}
		a[shu]*=10;
		a[shu]+=s[i]-'0';
		if(a[shu]>=10000)a[shu]%=10000;
	}
	bool ok=true;
	while(ok)
	{
	  for(int i=1;i<=fh-1;i++)
	  {
		if(b[i]==1)
		{
		  a[i]*=a[i+1];
		  for(int j=i+1;j<=shu;j++)
		    a[j]=a[j+1];
		  shu--;
		  for(int j=i;j<=fh;j++)
		    b[j]=b[j+1];
		  fh--;
		}
	  }
	  for(int i=1;i<=fh;i++)
	  {
		  if(b[i]==1)break;
		  else ok=false;
	  }
	}
	for(int i=1;i<=fh-1;i++)
	{
        a[i]+=a[i+1];
		for(int j=i+1;j<=shu;j++)a[j]=a[j+1];
		shu--;
		for(int j=i;j<=fh;j++)b[j]=b[j+1];
		fh--;
	}
	if(a[1]%10000==0)cout << a[1] << endl;
	else cout << a[1]%10000 << endl;
	return 0;
}

