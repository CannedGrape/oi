#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
long long a=0;
char str[400010],c[100001];
int s[100001],tops=0,topc=0,i,len;
int main()
{
  freopen("expr.in","r",stdin);
  freopen("expr.out","w",stdout);
  gets(str);
  len=strlen(str);
  i=0;
  while(i<len)
  {    
    a=0;
	while('0'<=str[i]&&str[i]<='9'){a=a*10+(str[i]-48);i++;}
    a%=10000;
    s[tops+1]=a;tops++;
    if(c[topc]=='*'){s[tops-1]=s[tops-1]*s[tops];s[tops-1]%=10000;s[tops]=0;tops--;topc--;}
    if(i<len-1)
    {c[topc+1]=str[i];topc++;i++;}
  }
  a=0;
  for(i=1;i<=tops;i++)
    a+=s[i];
  cout<<a<<endl;
  return 0;
}
