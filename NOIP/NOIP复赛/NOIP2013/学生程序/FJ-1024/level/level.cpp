#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    int m,n;
    scanf("%d%d",&n,&m);
    int a[1001],b[1001],i,j,k;
    memset(a,0,sizeof(a));
    for(i=1;i<=m;i++)
    {
        scanf("%d",&k);
        for(j=1;j<=k;j++)
        {
            scanf("%d",&b[j]);
            a[b[j]]++;
        }
    }
    sort(a+1,a+n+1);
    printf("%d",a[n]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
