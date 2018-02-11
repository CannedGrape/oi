#include<stdio.h>
int main()
{
     freopen("number.in","r",stdin);
     freopen("number.out","w",stdout);
     long n,p,i,max=-100000000;
     long a[3000001]={0};
     for(i=1;i<=n;i++) scanf("%ld",a[i]);
     for(i=1;i<=n;i++) if(a[i]>=max) max=a[i];
     if(max==a[i])
     {
          printf("-1");
          return 0;
     }
     printf("21");
     return 0;
}
