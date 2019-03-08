#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,m,x,k,q;
long long lcm;
long long gcd(long long a,long long b)
{
    if(b==0)  return a;
    return gcd(b,a%b);
}
long long qpow(long long a,long long b,long long c)
{
     long long s=1;
     a%=c;
     while(b>0)
     {
         if(b & 1)  s=(s*a)%c;
         a=(a*a)%c;
         b/=2;
     }
     return s;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    cin>>n>>m>>k>>x;
    lcm=n/gcd(n,m);
    q=qpow(10,k,lcm);
    q%=n;
    q=(x+(q*m)%n)%n;
    cout<<q<<endl;
    //system("pause");
    return 0;
}
