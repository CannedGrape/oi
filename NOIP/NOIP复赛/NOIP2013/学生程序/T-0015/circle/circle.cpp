#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n;
long long m,k,x,ans;
long long ksm(long long num)
{
    long long t;
    if (num==1) return 10;
    if (num%2==0)
    {
      t=ksm(num/2);
      t=t*t;
      t%=n;
    }
    else
    {
      t=ksm((num-1)/2);
      t=t*t;
      t%=n;
      t=t*10;
      t%=n;
    }
    return t;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    cin>>n>>m>>k>>x;
    ans=(x+ksm(k)*m)%n;
    cout<<ans;
    fclose(stdin);fclose(stdout);
    return 0;
}
