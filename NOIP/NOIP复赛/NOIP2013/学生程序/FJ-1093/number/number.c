#include<stdio.h>
#include<string.h>
struct studenttype
{
       int number;
       int tz;
       int fs;
}student[100000];
main()
{
      freopen("count.in","r",stdin);
      freopen("count.out","w",stdout);
      int i,n,p,a,j;
      scanf("%d %d",&n,&p);
      for(i=0;i<n;i++)
      {
                      scanf("%d",&student[i].number);
      }
      student[0].tz=student[0].number;
      for(i=0;i<n;i++)
      {
                   for(j<0;j<i;j++)
                   {
                                      a=student[i].number+student[j].number;
                   }
      }
      for(i=1;i<n;i++)
      {
                      for(j=0;j<i;j++)
                      student[i].tz=student[j].tz+student[j].fs;
      }
      printf("%d",student[5].fs%p);
      return 0;
}
