#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
char str[2000010];
int ans=0,s[100010];

int ten(int k)
{
  int i,sum=1;
  for(i=1;i<=k;i++) sum*=i;
  return sum;
}

int main()
{
  int i,k,l,xx;
  freopen("expr.in","r",stdin);
  freopen("expr.out","w",stdout);
  gets(str);
  l=strlen(str);i=0;k=0;
  while(i<l) 
  {
	if('0'<=str[i] && str[i]<='9')
	{
	  xx=0;
	  while('0'<=str[i] && str[i]<='9'){xx=xx*10+str[i]-48;i++;}
	  k++;s[k]=xx%10000;
	}
	else if(str[i]=='*')
	     {
	       xx=0;i++;
	       while('0'<=str[i] && str[i]<='9'){xx=xx*10+str[i]-48;i++;}
	       s[k]=(s[k]%10000)*(xx%10000);
	     }
	     else if(str[i]=='+') 
              {
	            ans+=s[k]%10000,k--;i++;
	          }
  }
  printf("%d\n",(ans+s[1])%10000);
  return 0;
}
