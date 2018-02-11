#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
long long bds[7000001],ans;
char a[8000001];
int len=0;
int main()
{
 freopen("expr.in","r",stdin);
 freopen("expr.out","w",stdout); 
 int zhi,bs,i,j;
 char p=0;
 scanf("%s",a);
 for (i=0;a[i]!='\0';i++)
 {
   if (a[i]>='0'&&a[i]<='9');
    {
   	 for (j=i+1;a[j]>='0'&&a[j]<='9';j++);
     zhi=a[j-1]-'0';
     bs=10;
     for (int l=j-2;l>=i;l--,bs*=10) zhi+=(a[l]-'0')*bs;
     bds[len++]=zhi;
     i=j;
    }
   if (a[i]=='*') 
   { 
	 for (j=i+1;a[j]>='0'&&a[j]<='9';j++);
     zhi=a[j-1]-'0';
     bs=10;
     for (int l=j-2;l>i;l--,bs*=10) zhi+=(a[l]-'0')*bs;
     bds[len-1]=zhi*bds[len-1];
     i=j;
   }
 }
 for (i=0;i<len;i++) {ans+=(long long)bds[i];ans%=10000;}
 printf("%lld\n",ans);
}
