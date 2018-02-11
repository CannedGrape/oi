#include<stdio.h>
main()
{
      freopen("expr.in","r",stdin);
      freopen("expr.out","w",stdout);
      long int head,next,last;
      long int i,n=1;
      char fu,fu2;
      scanf("%d",&head);
      for(i=0;i<=3;i++)
      {
                                   scanf("%d",&next);
                                   scanf("%c",&fu);
                                   if(fu=='*')
                                     head=next*head;
                                   if(fu=='+')
                                   {
                                   scanf("%d",&last);
                                   scanf("%c",&fu2);
                                     if(fu2=='*')
                                     head=next*last+head;
                                     else
                                     head=next+head;
                                   }
                                   head=head%10000;
      }
      printf("%d",head%10000+1);
      return 0;
}
