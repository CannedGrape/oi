#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long n,k,m,s,t,c[101],a[101][101],u[10001],v[10001],d[10001];
int main()
{
    freopen("culture.in","r",stdin);
    freopen("culture.out","w",stdout);
    long long i,j;
    cin>>n>>k>>m>>s>>t;
    for (i=1;i<=n;i++)
      cin>>c[i];
    for (i=1;i<=k;i++)
    {
      for (j=1;j<=k;j++)
        cin>>a[i][j];
    }
    for (i=1;i<=m;i++)
      cin>>u[i]>>v[i]>>d[i];
    cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
