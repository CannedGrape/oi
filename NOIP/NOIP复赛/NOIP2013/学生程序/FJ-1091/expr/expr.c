#include<stdio.h>
int main()
{
    int k,k1,k2,i,j;
    long long s;
    long long a[100];
    char c[100];
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    k=0;
    while(c[k]!='\n')
    {
       k++;
       scanf("%lld",&a[k]);
       scanf("%c",&c[k]);
    }
    for(i=1;i<=k;i++)
    {
       if(c[i]=='*')
       {
          k1=i;
          for(j=i+1;j<=k;j++)
          {
             if(c[j]!='*')
                k2=j;
          }
          for(j=k1;j<k2;j++)
          {
             a[k1]=(a[k1]*(a[j+1]%10000))%10000;
             a[j+1]=0;
          }
       }
    }
    s=0;
    for(i=1;i<=k;i++)
       s=(s+(a[i]%10000))%10000;
    printf("%lld\n",s);
    return 0;
}
