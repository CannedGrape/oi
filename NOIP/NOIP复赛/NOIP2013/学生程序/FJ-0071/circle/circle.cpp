#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int pow(int a,int b,int c)
{
    long long r=1;
    long long base=a;
    while(b!=0)
    {
    if(b&1)
    r=r*base%c;
    base=base*base%c;
    b>>=1;
    }
    return r;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int m,n,x,k;
    cin>>n>>m>>k>>x;
    long long h;
    h=pow(10,k,n);
    h=h*m;
    h=h%n;
    x=x+h;
    if(x>n-1)
    x-=n;
    cout<<x<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;    
}
