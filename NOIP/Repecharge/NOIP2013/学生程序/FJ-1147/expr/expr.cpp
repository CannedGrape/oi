#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
long long i,j,len,l=0,r,x=1,b[100005]={0},y,ans=0;
string s;
char a[100005];
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	len=s.size();
    for(i=0;i<len;i++)
      {
		if(s[i+1]=='+'||s[i+1]=='*')
        {
		 r=i;
		 a[x]=s[i+1];
		 y=1;
		 for(j=r;j>=l;j--)
		   {
			b[x]+=(s[j]-'0')*y;
			y*=10;
		   }
		 x++;
		 l=i+2;
		 i++;
		 continue;
		}
		if(i==len-1)
		{
		 r=i;
		 y=1;
		 for(j=r;j>=l;j--)
		   {
			b[x]+=(s[j]-'0')*y;
			y*=10;
		   }
		}
	  }
	for(i=1;i<=x;i++)
      if(a[i]=='*')
        {
		 b[i]=(b[i]%10000)*(b[i+1]%10000)%10000;
           for(j=i+1;j<=x;j++)
             {a[j-1]=a[j];
		      b[j]=b[j+1];
		     }
		 a[x]=' ';
		 b[x+1]=0;
		 i--;
		 x--;
		}
	for(i=1;i<=x;i++)
      {ans+=b[i];
       ans=ans%10000;}
    cout<<ans<<endl;
	return 0;
} 

