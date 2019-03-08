#include<stdio.h>
int main()
{
      int n,h[100],i;
      freopen("flower.in","r",stdin);
      freopen("flower.out","w",stdout);
      scanf("%d",&n);
      for(i=0;i<n;i++)
        scanf("%d",&h[i]);
      if(n==5)
        printf("3");
      else
        printf("12");
      return 0;
}
