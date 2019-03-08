#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string s;
long long ans,i,j=1,ls,l,l2,k=1,w;
bool pd=false,pd2=false,pd3;
int x[100002];
char ffh[1000001],fh,f;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin,s);s[s.size()]='!';
    for(i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9'){if(pd==false&&pd2==false){l*=10;l+=s[i]-'0';}else{l2*=10;l2+=s[i]-'0';}}
		else {
			if(pd){if(fh=='*'){l%=10000;l2%=10000;l=(l2*l)%10000;fh=s[i];l2=0;if(fh!='*')x[j++]=l,pd=false,l=0;}
			  else {x[j++]=l;l=l2;l2=0;pd2=false;fh=s[i];}}
			else{fh=s[i];pd=true;pd2=true;}
		     }
		if(s[i]=='+')w++;
    
	}
    if(j==w+1)x[j++]=l;
    ans=0;
    for(i=1;i<j;i++)ans=(x[i]+ans)%10000;
    printf("%d\n",ans);
	return 0;
}

