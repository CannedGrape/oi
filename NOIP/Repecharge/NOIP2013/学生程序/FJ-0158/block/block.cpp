#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,ans=0,pos;
int h[100001];
int minn(int l,int r)
{
    int i;
    int min0=10086;
    for (i=l;i<=r;i++)
    {
        if (h[i]<min0)
        {
          min0=h[i];
          pos=i;
          }
    }
    return min0;
}
void solve(int l,int r)
{
     int key,i;
     key=minn(l,r);
     ans+=key;
     for (i=l;i<=r;i++)
       h[i]-=key;
     if (l<pos)
       solve(l,pos-1);
     if (r>pos)
       solve(pos+1,r);
}      
int main()
{
    int i;
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++)
      cin>>h[i];
    solve(1,n);
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
