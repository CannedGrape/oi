#include<iostream>
#include<cstdio>
using namespace std;
int n,x,did[1000001];
int yes(int nn)
{
    if(did[nn/10]>-1)
                      return did[nn]=did[nn/10]+yes(nn%10);
    if(nn<10)return nn==x;
    int ans=yes(nn/10);
    if(nn%10==x)++ans;
//cout<<"nn:"<<nn<<' ';
//cout<<ans<<endl;
    return did[nn]=ans;
}
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    cin>>n>>x;
    int ans=0;
    for(int i=1;i<=n;++i){
            did[ans]=-1;
            ans+=yes(i);}
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
