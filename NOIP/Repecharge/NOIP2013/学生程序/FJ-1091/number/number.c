#include<stdio.h>
int main()
{
    int n,p,i,j,k,k1,k2,k3,s,s1,f1;
    int a[100],t[100],f[100];
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%d %d",&n,&p);
    for(i=1;i<=n;i++)
       scanf("%d",&a[i]);
    t[1]=a[1];
    f[1]=t[1];
    f1=t[1]*2;
    for(i=2;i<=n;i++)
    {
       k=0;
       k1=0;
       s=0;
       for(j=1;j<=i;j++)
       {
          if(a[j]>=0)
          {
             k++;
             k1=k1+a[j];
          }
          else
          {
             if(k1>s)
             {
                s=k1;
                k1=0;
                k=0;
             }
          }
       }
       if(s==0)
          t[i]=t[1];
       else
          t[i]=s;
       if(i==2)
          f[i]=f1;
       else
       {
          f[i]=f[i-1]+t[i-1];
       }
    }
    for(i=2;i<=n;i++)
    {
       if(f[i]>f[1])
          f[1]=f[i];
    }
    if(f[1]<0)
       printf("%d\n",f[1]%p);
    else
       printf("%d\n",f[1]%p*4+1);
    return 0;
}
