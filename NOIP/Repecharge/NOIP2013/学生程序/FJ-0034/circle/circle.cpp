#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
int mod10[1000010];
int flag[1000010];
int n,m,k,x;
int main()
{
    long long ans,mod10k;
    int i,round,start,end;
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    cin>>n>>m>>k>>x;
    for(i=0;i<1000010;i++)
      flag[i]=n+10;
    mod10[1]=10%n;
    i=1;
    do
    {
        flag[mod10[i]]=i;
        i++;
        mod10[i]=mod10[i-1]*10%n;
    }
    while(flag[mod10[i]]==n+10);
    start=flag[mod10[i]];
    end=i-1;
    round=end-start+1;
    if(k<=start)
       mod10k=mod10[k];
    else
       mod10k=mod10[(k-start)%round+start];
    ans=mod10k*(m%n)+x;
    ans=ans%n;
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

