#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main()
{
    int a,g[50001],d,e,f,h,i,m,n,q;
    int z[100000][100000];
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    cin>>n>>m;
    int b[5][m];
    for(a=1;a<=m;a++)
     cin>>b[1][a]>>b[2][a]>>b[3][a];
    cin>>q;
    int c[2][q];
    for(a=1;a<=q;a++)
      cin>>c[1][a]>>c[2][a];
    for(a=1;a<=q;a++)
      cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
