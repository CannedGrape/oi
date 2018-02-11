#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int a[100001],odd[100001],f[100001][2];
    memset(a,0,sizeof(a));
    memset(odd,0,sizeof(odd));
    memset(f,0,sizeof(f));
    int n,ans=0,d;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
            scanf("%d",&a[i]);
            odd[i]=1;
            }
    if(n>1000)d=500;
    else d=n;
    for(int i=2;i<=n;i++)
    {
            for(int j=max(1,i-d);j<i;j++)
            {
                    if(a[i]>a[j])
                    {
                                 odd[i]=max(odd[i],f[j][0]+1);
                                 f[i][1]=max(f[i][1],odd[j]+1);
                                 }
                    else if(a[i]<a[j])
                    {
                         odd[i]=max(odd[i],f[j][1]+1);
                         f[i][0]=max(f[i][0],odd[j]+1);
                    }
            }
    }
    for(int i=1;i<=n;i++)
    {
            ans=max(ans,f[i][0]);
            ans=max(ans,f[i][1]);
            ans=max(ans,odd[i]);
            }
            cout<<ans;
    return 0;
}
