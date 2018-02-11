#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int n,h[100001];
    cin>>n;
    for(int i=1;i<=n;i++)
    scanf("%d",&h[i]);
    h[0]=0;
    int mn=h[1],ans=0;
    for(int i=1;i<=n;i++)
    {
            if(h[i]>h[i-1])
            ans++;
            if(h[i]<h[i-1])
              if(h[i]<mn)
              {
                         ans++;
                         mn=h[i];
              }
                         
    }
    cout<<ans;
}
