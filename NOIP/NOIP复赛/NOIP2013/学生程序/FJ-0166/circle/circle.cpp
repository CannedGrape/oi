#include<iostream>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    long long n,m,k,N,c;
    long long int x;
    cin>>n>>m>>k>>x;
    int circle[n];
    long long lunshu=1;
    long long a;
    for(int A=1;A<=k;A++)
    {
                     lunshu=lunshu*10;
    }
    for(c=0;c<=n-1;c++)
    {
    circle[c]=c;
    }
    if(10<=n<=100)
    {
    for(a=1;a<=lunshu;a++)
    {
    if(circle[x]+m>=n)
    circle[x]=circle[x]+m-n;
    else
    circle[x]=circle[x]+m;
    }
    }
    else
    {
    for(a=1;a<=lunshu;a++)
    {
    if(circle[x]+m>n)
    circle[x]=circle[x]+m-n-1;
    else
    circle[x]=circle[x]+m;
    }
    }
    cout<<circle[x];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    
