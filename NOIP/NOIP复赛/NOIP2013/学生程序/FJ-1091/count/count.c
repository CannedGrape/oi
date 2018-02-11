#include<stdio.h>
int main()
{
    int i,j,n,s,a,x;
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d%d",&n,&x);
    s=0;
    for(i=1;i<=n;i++)
    {
       j=i;
       a=j%10;
       j=j/10;
       if(a==x)
          s++;
       while(j!=0)
       {
          a=j%10;
          j=j/10;
          if(a==x)
             s++;
       }
    }
    printf("%d\n",s);
    return 0;
}
