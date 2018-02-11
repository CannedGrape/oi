#include<iostream>
#include<cstdio>
using namespace std;

int n,m,k,x;

int qpow (int a,int b)
{
    int t=a;
    int ans=1;
    while (1)
    {
      if (b==0) break;
      if (b&1) ans=(ans*t)%n;
      t=(t*t)%n;
      b=b>>1;
    }
    return ans%n;
}

int main ()
{
    freopen ("circle.in","r",stdin);
    freopen ("circle.out","w",stdout);
    cin>>n>>m>>k>>x;
    int temp=qpow(10,k);
    temp=(temp*(m % n) )%n;
    temp=((x%n)+(temp%n))%n;
    cout<<temp<<endl;
    //system ("pause");
    return 0;
}
