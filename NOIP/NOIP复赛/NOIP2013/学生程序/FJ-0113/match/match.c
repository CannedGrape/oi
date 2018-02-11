#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n,mod=99999997;
int a[100010][2],b[100010][2];
int c[100010][3];
long long ans=0;
int comp(const void *a,const void *b)
{
    return ((int *)a)[0]-((int *)b)[0];
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i][0]);
        a[i][1]=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i][0]);
        b[i][1]=i;
        c[i][2]=i;
    }
    qsort(a+1,n,sizeof(int)*2,comp);
    qsort(b+1,n,sizeof(int)*2,comp);
    for(i=1;i<=n;i++)
    {
        c[a[i][1]][0]=b[i][0];
        c[a[i][1]][1]=b[i][1];
    }
    for(i=1;i<=n;i++) ans+=(int)abs((double)(c[i][1]-c[i][2]));
    ans/=2;
    printf("%lld\n",ans%mod);
    return 0;
}
