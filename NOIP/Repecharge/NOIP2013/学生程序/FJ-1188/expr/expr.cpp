#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
char a[2000002];
long long sz[100010],gs=0;
bool z1;
int main()
{
  int i,jg=0;
  freopen("expr.in","r",stdin);
  freopen("expr.out","w",stdout);
  gets(a);
  for(i=0;i<strlen(a);i++)
  { 
	if(a[i]>='0' && a[i]<='9')
	{
	  while(a[i]>='0' && a[i]<='9' && i<strlen(a))sz[gs]*=10,sz[gs]+=a[i]-'0',i++;
	  sz[gs]%=10000;
	  if(z1)sz[gs-1]*=sz[gs],sz[gs-1]%=10000,sz[gs]=0,gs--,z1=0;
	  gs++,i--;
	}
    else if(a[i]=='*')z1=1;
  }
  for(i=0;i<gs;i++)jg+=sz[i];
  cout<<jg%10000<<endl;
  return 0;
}

