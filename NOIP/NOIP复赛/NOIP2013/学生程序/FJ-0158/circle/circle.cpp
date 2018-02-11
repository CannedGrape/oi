#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
long long n,m,k,x;
int pow4(int a,int b,int c)
{
    long long r=1;
    int base=a;
    while (b!=0)
    {
          if (b&1)
          r=r*base%c;
          base=base*base%c;
          b>>=1;
          }
    return r;
}
long long solve(void)
{
    int t;
    long long i;
    long long f;
    long long temp,num;
    temp=x;
    for (i=1;i<=1000000000;i++)
    {
        t=(x+m)%n;
        x=t;
        if (x==temp)
          break;
    }
    num=i;
    f=pow4(10%num,k,num);
    x=temp;
    for (i=1;i<=f;i++)
    {
        t=(x+m)%n;
        x=t;
    }
    return x;
}
int main()
{
     freopen("circle.in","r",stdin);
     freopen("circle.out","w",stdout);
     cin>>n>>m>>k>>x;
     cout<<solve()<<endl;
     fclose(stdin);
     fclose(stdout);
     return 0;
}
     

