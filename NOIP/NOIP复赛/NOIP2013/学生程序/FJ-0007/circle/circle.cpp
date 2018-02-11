#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
long long  mypow(int x,int y)
{
   long long r=1,base=x;
     while (y!=0)
     {if(y&1)r*=base;base*=base;y>>=1;}
   return r;
}
using namespace std;
int main()
{
   
   freopen("circle.in","r",stdin);
   freopen("circle.out","w",stdout);
   int n,m,k,x;
   scanf("%d%d%d%d",&n,&m,&k,&x);
  // cout<<mypow(10,k);
   //cout<<" "<<mypow(10,k)*m+x<<endl;
  cout<<((mypow(10,k))*m+x)%n<<"\n";
   //printf("%lld",((mypow(10,k))*m+x)%n);
   fclose(stdin);
   fclose(stdout);
   return 0;
}
