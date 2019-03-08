#include<iostream>
#include<stdio.h>
using namespace std;

long long n,m,k,x;

int gcd(int a,int b)
{return b?gcd(b,a%b):a;}

int main ()
{
    freopen ("circle.in","r",stdin);
    freopen ("circle.out","w",stdout);
    cin>>n>>m>>k>>x;
    
    long long a= m*n/gcd(m,n);  
    long long h=a/m,temp=1,num; 
    while (k--)
    {
           if (temp<h) temp*=10;
           else {num=temp%h;}
    }
    while (num--)
    {
           x+=m;
           x%=n;
    }
    cout<<x;
    return 0;
}
