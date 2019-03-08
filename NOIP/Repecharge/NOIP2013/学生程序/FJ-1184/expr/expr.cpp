#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int ans=0,sc,i,k;
int as[100005],ta,tb,a=0;
string s;
bool cheng,ja;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;sc=s.size();ta=0;tb=0;i=0;k=1;
	while(i<=sc-1)
	{
	  ta=0;tb=0;
	  while(s[i]!='*'&&s[i]!='+'&&i<=sc-1){ta=(ta*10+s[i]-48)%10000;i++;a=i;}
	  if(s[i]=='*')cheng=true;
	  while(s[i]=='+'&&i<=sc-1)
	  {
		as[k]=ta%10000;k++;i++;ta=0;if(a!=i-1)ja=true;else ja=false;
		while(s[i]!='*'&&s[i]!='+'&&i<=sc-1){ta=(ta*10+s[i]-48)%10000;i++;}
	  }if(ja){as[k]=ta%10000;k++;}
	  i++;if(i<=sc-1)cheng=true;
	  while(s[i]!='*'&&s[i]!='+'&&i<=sc-1){tb=(tb*10+s[i]-48)%10000;i++;}
	  if(cheng){as[k]=ta*tb%10000;k++;}
	  else{as[k]=ta;k++;}
	}
	k--;
	for(int i=1;i<=k;i++)
	  ans=(ans+as[i])%10000;
	cout<<ans<<endl;
	return 0;
}
