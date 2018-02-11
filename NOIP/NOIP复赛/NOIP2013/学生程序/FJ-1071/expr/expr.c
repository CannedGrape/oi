#include<stdio.h>
char a[10000001]={0};
long  ans=0;
void select()
{
     long i=0;
     while(a[i]!='\0')
     {
          ans+=a[i];
          i++;
     }
     printf("%ld",ans);
}
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    gets(a);
    select();
    return 0;
}
