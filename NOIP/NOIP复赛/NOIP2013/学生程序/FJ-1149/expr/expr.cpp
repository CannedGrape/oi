#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
char bds[1000010],fuhao[100010];
int sz[100010],sums,sumf,ans=0;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	int i,j=1,k=1,len,tmp=0;
	gets(bds);
	len=strlen(bds);
	tmp=0;
	//deal
	for (i=0;i<len;i++)
	{
	  if (isdigit(bds[i])==0)
	  { fuhao[j]=bds[i];j++;
	    sz[k]=tmp;tmp=0;k++;
	    //cout<<sz[k]<<' ';
	  }
	  else
	  {if (i==len-1) sz[k]=tmp*10+bds[i]-48;
	   else
	   {tmp=tmp*10+bds[i]-48;
	   }
	  }
	}
	sums=k;sumf=j;
	for (i=1;i<=sums;i++)
	{ sz[i]%=10000;}
	for (i=1;i<=sumf;i++)
	{ if (fuhao[i]=='*')
	  { sz[i]=sz[i]*sz[i+1];
	    sz[i]%=10000;
	    sz[i+1]=-1;
	  }
	}
	ans=sz[1];
	for (i=1;i<=sumf;i++)
	{  if (fuhao[i]=='+')
	  { ans=(ans+sz[i+1])%10000;
	  }
	}
	cout<<ans<<endl;
	return 0;
}
