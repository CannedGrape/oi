#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,k,x;
long long my_function(long long a,long long b)
{
     long long t=1,e=a;
     while(b)
     {
             if(b&1)
                    t=(t*e)%n;
             e=e*e%n;
             b>>=1;
     }
     return t;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    cin>>n>>m>>k>>x;
    cout<<(x+my_function(10,k)*m)%n<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
