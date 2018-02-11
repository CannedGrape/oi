#define DEBUG
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

int todig(char x){return x-'0';}
class longv
{
	int dt[1024];
	size_t len;
	int& operator[](size_t pos){return dt[pos];}
	int operator[](size_t pos)const{return dt[pos];}
public:
	longv():len(0){memset(dt,0,sizeof(dt));}
	longv(string s)
	{
		len=s.size();
		reverse(s.begin(),s.end());
		transform(s.begin(),s.end(),dt,todig);
	}
	size_t length()const{return len;}
	longv operator+(const longv& x)const
	{
		longv res;
		res.len=(len>x.len? len : x.len);
		for (size_t i=0;i<res.len;i++)
		{
			res[i]+=dt[i]+x[i];
			res[i+1]+=res[i]/10;
			res[i]%=10;
		}
		if (res[res.len])
			res.len++;
		return res;
	}
	longv operator*(const longv& x)const
	{
		longv res;
		res.len=len+x.len;
		for (size_t i=0;i<len;i++)
		for (size_t j=0;j<x.len;j++)
		{
			res[i+j]+=dt[i]*x[j];
			res[i+j+1]+=res[i+j]/10;
			res[i+j]%=10;
		}
		while (!res[res.len-1])
			res.len--;
		return res;
	}
	string dstr()const
	{
		string res;
		res.reserve(len);
		for (size_t i=0;i<len;i++)
		{
			res+=dt[i]+'0';
		}
		reverse(res.begin(),res.end());
		return res;
	}
};

size_t gnei,gnbi;

longv getnume(string s,size_t end)
{
	string res;
	longv ans;
	size_t i;
	for (i=end;i>=0 && isdigit(s[i]);i--)
	{
		res=s[i]+res;
	}
	gnei=i+1;
	ans=res;
	return ans;
}
longv getnumb(string s,size_t beg)
{
	string res;
	longv ans;
	size_t i;
	for (i=beg;i<s.size() && isdigit(s[i]);i++)
	{
		res=res+s[i];
	}
	gnbi=i;
	ans=res;
	return ans;
}

int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	string expr;
	cin>>expr;
	longv lop,rop,ans;
	while (expr.find('*')!=string::npos)
	    for (size_t i=0;i<expr.size();i++)
	    {
	    	if (expr[i]=='*')
	    	{
	    		lop=getnume(expr,i-1);
	      		rop=getnumb(expr,i+1);
	    		ans=lop*rop;
	    		expr.replace(gnei,gnbi-gnei,ans.dstr());
	    	}
	    }
	
	while (expr.find('+')!=string::npos)
	    for (size_t i=0;i<expr.size();i++)
	    {
	    	if (expr[i]=='+')
	    	{
	    		lop=getnume(expr,i-1);
	      		rop=getnumb(expr,i+1);
	    		expr.replace(gnei,gnbi-gnei,(longv(lop.dstr())+longv(rop.dstr())).dstr());
	    	}
	    }
	

	if (expr.size()>4)
	{
		expr=string(expr.end()-4,expr.end());
		size_t pos=expr.find_first_not_of('0');
		expr.erase(expr.begin(),expr.begin()+pos);
	}
	cout<<expr<<endl;
	fclose(stdin);
	fclose(stdout);	
}