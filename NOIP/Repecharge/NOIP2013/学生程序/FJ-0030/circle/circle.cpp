#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int n,m,x;
    long long k;
    cin>>n>>m>>k>>x;
    int ys=m*10%n;
    while(k>1)
    {
           if(k%2==1){k--;
           for(int i=1;i<=10;i++)
           {
                   ys=(ys*ys)%n;}
           }
           k/=2;
           ys=(ys*ys)%n;
                     }
    cout<<(x+ys)%n;
    return 0;
}
