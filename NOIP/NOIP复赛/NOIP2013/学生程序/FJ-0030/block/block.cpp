#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int ans=0,an;
    int a[10001];
    memset(a,0,sizeof(a));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
       {
            an=a[i]-a[i-1];
            if(an>0)
            {
            ans+=an;
        }
    }
    printf("%d",ans);
    //system("pause");
    return 0;
}
