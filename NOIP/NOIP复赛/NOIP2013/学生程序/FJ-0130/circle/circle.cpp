#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<fstream>
using namespace std;
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int l;
    long long k;
    int x,m,n;
    cin>>n>>m>>k>>x;
    l=(10*m+x)%n;
    for(long long i=2;i<=k;i++)
    l=(10*l+x)%n;
    cout<<l;
    return 0;
}
