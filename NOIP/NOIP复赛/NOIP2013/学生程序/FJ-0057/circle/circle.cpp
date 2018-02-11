#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,k,x;
void input()
{
     scanf("%d %d %d %d",&n,&m,&k,&x);
}
long long ksm(int a,int b) 
{
    long long r,base;
    r=1;base=a;
    while(b)
      {if( b&1 )
         r=(r*base)%n;
       base=(base*base)%n;
       b>>=1;
      }
    return r;
}
void work()
{
     long long a,ans;
     a=ksm(10,k);
     ans=(a*m)%n;
     cout<<(x+a)%n<<endl;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    input();
    work();
    fclose(stdin);
    fclose(stdout);
return 0;
}
