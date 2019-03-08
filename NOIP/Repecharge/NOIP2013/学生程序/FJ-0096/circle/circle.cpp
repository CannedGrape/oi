#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,k,x;
unsigned long long total=0;

int mod(unsigned long long a,int b,int c)
{
 int ans=1;
 while (b)
 {
  if (b&0x1) ans=ans*a%c;
  a=a*a%c;
  b>>=1;
 }
 return ans;
}

int main()
{
freopen("circle.in","r",stdin); freopen("circle.out","w",stdout);
scanf("%d%d%d%d",&n,&m,&k,&x);
total=mod(10,k,n)*m;
total=total%n;
total=total+x;
total=total%n;
printf("%lld\n",total);
fclose(stdin);fclose(stdout);
return 0;
} 
