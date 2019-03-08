#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>
struct data{ int d,w;};
int main(){
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int n,i,j,ans=0;
    cin>>n;
    data a[n+1],b[n+1];
    int ap[n+1],bp[n+1];
    for(i=1;i<=n;i++)
    {cin>>a[i].d; }
    for(i=1;i<=n;i++)
    {cin>>b[i].d; }
    for(i=1;i<=n;i++)
    {ap[i]=a[i].d;bp[i]=b[i].d;}
    sort(ap+1,ap+1+n);
    sort(bp+1,bp+1+n);
    for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
      {if(ap[i]==a[j].d)a[j].w=i;
      if(bp[i]==b[j].d)b[j].w=i;}
    for(i=1;i<=n;i++)if(a[i].w!=b[i].w)ans++;
    if(ans>0)ans--;
    cout<<ans%99999997;
    return 0;} 
    
