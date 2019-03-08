#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    long long  n,m,x;
	long long  k;
    long long  ans;
    cin>>n>>m>>k>>x;
    long long temp=m;
    long long i;
    for(i=1;i<=k;i++)
    temp=(temp*10)%n;
    ans=(temp+x)%n;
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    
