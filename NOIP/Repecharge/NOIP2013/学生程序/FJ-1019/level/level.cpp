#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    int n,m,k1,k2;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&k1);
        for(int j=1;j<=k1;j++) scanf("%d",&k2);
    }
    printf("%d",min(n,m));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
