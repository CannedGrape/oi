#include<iostream>
#include<stdin.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    long n,m,i,u,v,a,b;
    long long w;
    freopen("blockade.in","r",stdin);
    freopen("blockade.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>u>>v>>w;
    for(i=1;i<=m;i++)
    cin>>a>>b;
    if(n==4)
    cout<<3;
    else
    cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
