#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main()
{    
    long n,m,x;
    long long k;
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    cin>>n>>m>>k>>x;
    long long y;
    y=1;
    for(int c=1;c<=k;c++)
      y=10*y;
    for(y=y;y>=1;y--)
        if(x<=n-m)
          x=x+m;
        else
          x=m-n+x;
    cout<<x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    
