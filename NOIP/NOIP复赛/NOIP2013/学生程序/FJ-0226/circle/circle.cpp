#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int n,k,m,x;
int v[10000000];

int work2(int b,int MODE)
{
 int ans;
 if (b==1) return 10%MODE;	
 ans=work2(b/2,MODE);
 ans=ans*ans%MODE;
 if(b%2!=0) ans=ans*10%MODE;
 return ans;
}
int work1()
{
 v[0]=x;	
 int step=(x+m)%n,z=1;
 while(step!=x)	
 {
  v[z]=step;		
  step=(step+m)%n;
  z++;		
 }
 int ans=work2(k,z);
 printf("%d\n",v[ans]);
}


int main()
{
 freopen("circle.in","r",stdin);
 freopen("circle.out","w",stdout);	
 scanf("%d%d%d%d",&n,&m,&k,&x);
 work1();
 return 0;
}
