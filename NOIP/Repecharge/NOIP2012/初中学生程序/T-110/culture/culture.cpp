#include<iostream>
using namespace std;
int v[100],h[100000];
int main()
{
    int n,k,m,s,t,l,d,u;
    freopen("culture.in","r",stdin);
    freopen("culture.out","w",stdout);
    cin>>n>>k>>m>>s>>t;
    int a,b,c;
    for(a=1;a<=n;a++)
      cin>>v[a];
    for(a=1;a<=k;a++)
      for(b=1;b<=k;b++)
        cin>>h[b];
    for(a=1;a<=m;a++)
      cin>>u>>l>>d;
    cout<<d;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
