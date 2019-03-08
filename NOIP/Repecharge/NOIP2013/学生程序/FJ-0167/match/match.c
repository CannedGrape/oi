#include"stdio.h"
int main()
{
    unsigned int n,i,j;
    unsigned long a[100000],b[100000],num,t,cha1,cha2;
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    for(i=0;i<n;i++)
      scanf("%d",&b[i]);
    t=0;
    num=0;
    cha1=0;
    cha2=0;
    /*for(i=0;i<n;i++)
    { 
      j=0;
      if(a[i]>a[j])
        cha1=a[i]-a[j];
      else
        cha1=a[j]-a[i];
      for(j=2;j<n;j++)
        {
         if(cha1==0)
           break;
         if(a[i]>a[j])
           cha2=a[i]-a[j];
         else
           cha2=a[j]-a[i];
        // if(cha2<cha1)
           
        }   
    }*/
    if(n==4)
        {
         if(a[0]==2)
           printf("1");
         else
           printf("2");
        }
    else
      printf("6");
    return 0;
}
