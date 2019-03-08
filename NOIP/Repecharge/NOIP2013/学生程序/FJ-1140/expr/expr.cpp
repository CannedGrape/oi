#include<iostream> 
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
string s;
char fh[100010],f;
int sz[100010],z,cd,t;
int mod(int a){return a-a/10000*10000;}
int pd(int i)
{
	++z;
    int t=i;
    while(s[t+1]>='0' && s[t+1]<='9' && t+1<=cd)++t;
    for(int j=t,x=1;j>=i;j--,x*=10){sz[z]+=(s[j]-'0')*x;sz[z]=mod(sz[z]);}
	return t;
}

int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
    cin>>s;cd=s.size();
    if(s[0]<'0' || s[0]>'9')t=1;
    for(int i=t;i<cd;++i)
        if(s[i]>='0' && s[i]<='9')i=pd(i);
        else fh[++f]=s[i];
    int t=1;
    while(t<=f)
    {   while(t<=f && fh[t]=='+')++t;
	    sz[t+1]*=sz[t];mod(sz[t+1]);
	    ++t;
	}
	t=1;
	while(t<=z)
	{   while(t<=z && fh[t]=='*')++t;
	    int tt=t+1;
	    while(tt<=z && fh[tt]=='*')++tt;
	    sz[tt]+=sz[t];mod(sz[tt]);
	    ++t;
	}
	printf("%d\n",mod(sz[z]));
return 0;
}
