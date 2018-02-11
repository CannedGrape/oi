#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int n,h[100010],b[100010],x,y,i,minn;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&h[i]);
    minn=h[1];
    for (i=2;i<=n;i++) minn=min(minn,h[i]);
    for (i=1;i<=n;i++) h[i]-=minn;
    for (i=1;i<=n+1;i++)
    {
        b[i]=h[i]-h[i-1];
        if (b[i]>0) x+=b[i];
        else y-=b[i];
    }
    printf("%d\n",max(x,y)+minn);
    return 0;
}
