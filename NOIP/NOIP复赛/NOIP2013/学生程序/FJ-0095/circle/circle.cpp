#include<iostream>
#include<stdio.h>
using namespace std;
long long x,m,k,n;
long long pow(long long a,long long b)
{
    long long r=1;
    while(b)
    {
        if(b&1) r=(r*a)%n;
        a=(a*a)%n;
        b>>=1;
    }
    return r;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    
    cin>>n>>m>>k>>x;
    long long ans=(x+(m*pow(10,k))%n)%n;
    cout<<ans<<endl;
    return 0;
}

/*
10 3 4 5
20 12 1 0
*/
