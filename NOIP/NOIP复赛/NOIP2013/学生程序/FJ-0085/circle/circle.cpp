#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <memory.h>
using namespace std;
long long n,m,k,x,length=0;
long long ans;

long long pf(long long aa){return aa*aa;}
long long count(long long k0,long long n0)
{
    if(k0==0) return 1;
    else if(k0==1) return 10%n0;
    else if(k0%2==0) return pf(count(k0/2,n0))%n0;
    else return ( pf(count(k0/2,n0))%n0 * 10 ) % n0;
}

void init()
{
     cin>>n>>m>>k>>x;
    
}

void work()
{ 
     length=count(k,n);
     ans=(m*length+x)%n;
}
void print()
{
     cout<<ans<<endl;
}

int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    
    init();
    work();
    print();
    
    freopen(stdin);
    freopen(stdout);
    //system("pause");
    return 0;
}
