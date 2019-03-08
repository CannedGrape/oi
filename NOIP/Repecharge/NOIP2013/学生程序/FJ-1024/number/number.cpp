#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long n,p;
    scanf("%I64d%I64d",&n,&p);
    long long a[n+1],b[n+1],i,j,t;
    bool k;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(i=1;i<=n;i++)
    scanf("%I64d",&a[i]);
    b[1]=a[1];
    for(i=2;i<=n;i++)
    {
        k=0;
        for(j=1;j<=i;j++)
        if(a[j]>0)
        {
            b[i]+=a[j];
            k=1;
        }
        if(k==0)
        {
            b[i]=a[i];
            for(j=2;j<=i;j++)
            if(a[i]>b[i])
                b[i]=a[i];
        }
    }
    for(i=2;i<=n;i++)
    {
        t=a[1]+b[1];
        for(j=1;j<=i-1;j++)
        if(a[j]+b[j]>t)
            t=a[j]+b[j];
        a[i]=t;
    }
    sort(a+1,a+n+1);
    if(a[n]<0)
    {
        cout<<"-";
        a[n]=0-a[n];
    }
    a[n]=a[n]%p;
    printf("%I64d",a[n]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
