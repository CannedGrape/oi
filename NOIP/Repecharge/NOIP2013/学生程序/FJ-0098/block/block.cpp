#include<cstdio>
#include<iostream>
int n,h[100010]={0};
long long ans=0;
using namespace std;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    cin>>n>>h[1];
    ans=h[1];
    for(int i=2;i<=n;i++){
        cin>>h[i];
        if(h[i]>h[i-1])ans=ans+h[i]-h[i-1];}
    cout<<ans<<endl;
    return 0;
}
