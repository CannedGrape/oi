#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int n,h[100010];
long long ans=0;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for (i=1;i<=n;i++)
    {
        ans+=h[i];
        while (h[i])
            for (j=i;(h[j]>0 && j<=n);j++)
                h[j]--;
    }
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
