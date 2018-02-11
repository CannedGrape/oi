#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;
long long n,m,l1,l2;
long long ans=-1;

long long gcd(long long a,long long b)
{
     if(b!=0) return gcd(b,a%b);
     else return a;
}

void init()
{
     cin>>n>>m;
}

void work()
{
     int k1,k2,t,i,j;
     n=n%m;

     t=n,k1=1;
     while(t!=1){
     k1++;
     l1=t;
     t+=n;
     if(t>=m)t-=m;
     if(t*2-m==1) {ans=k1*2;break;}
     if(t+l1-m==1) {ans=k1*2-1;break;}
     }
}

void print()
{
     cout<<ans<<endl;
}

int main()
{
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    
    init();
    work();
    print();
    
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
