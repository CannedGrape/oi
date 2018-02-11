#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
long long s[100000]={0};
int main()
{
   int i,r,f;
   char ch;
   long long a=0,m=0;
   freopen("expr.in","r",stdin);
   freopen("expr.out","w",stdout);   
   f=0;r=0;
   while (1)
   {
	ch=getchar();
	if ((ch-48<0 || ch-48>9 || ch=='\n') && f==1) {s[r-1]=s[r-1]*m;s[r-1]%=10000;s[r]-=1000000000;f=0;}
	if (ch=='\n') break;
	if (ch-48>=0 && ch-48<=9) {m=m*10+(long long)(ch-48);m%=10000;}
	  else
	  {
	   if (ch=='*') f=1;
	   
	   s[r++]+=m;m=0;
	  }
    
   }
   s[r++]+=m;if (f==1) {s[r-1]=s[r-1]*m;s[r-1]%=10000;s[r]-=1000000000;}
   for (i=0;i<r;i++) if (s[i]>0) a+=s[i],a%=10000;
   cout<<a%10000<<endl;
  return 0;
}

