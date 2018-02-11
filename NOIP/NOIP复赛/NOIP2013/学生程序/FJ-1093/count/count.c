#include<stdio.h>
main()
{
      freopen("count.in","r",stdin);
      freopen("count.out","w",stdout);
      int n,x,b,p=10,c;
      int i,ans=0;
      scanf("%d %d",&n,&x);
      for(i=0;i<=n;i++)
      {
                       c=i;
                       while(i>=10)
                       {
                                   b=i%10;
                                   i=i/10;
                                   if(b==x) ans++;
                                   if(i==x) {ans++;break;}
                       }
                       i=c;
      }
      printf("%d",ans+1);
      return 0;
}
