#include<cstdio>
#include<iostream>
using namespace std;
int n,p,x;
int a[1000001],b[1000001];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%d%d",&n,&p);
    for (int i=1;i<=n;++i)scanf("%d",&a[i]);
    x=a[1]+a[1];
    b[1]=a[1];
    for (int i=2;i<=n;++i)
    {
        if (b[i-1]>0)b[i]=b[i-1];
        if (a[i]>0)b[i]=b[i]+a[i];
        else if (b[i]==0)b[i]=max(a[i],b[i-1]);
        x=max(x,a[i-1]+b[i-1]);
        a[i]=x;
    }
    if (x>a[1])
    {if (x<0&&x%p==0)printf("-%d\n",x%p);
    else printf("%d\n",x%p);}
    else 
    {if (a[1]<0&&a[1]%p==0)printf("-%d\n",x%p);
    else printf("%d\n",a[1]%p);}
   fclose(stdin);fclose(stdout);
   return 0;
}

