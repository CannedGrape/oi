#include<cstdio>
int n,x,tot;
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d%d",&n,&x);
    for (int i=1;i<=n;++i)
    {
      int s=i;
      while (s>0)
      {
        if (s%10==x)++tot;
        s/=10;    
      }    
    }
    printf("%d",tot);
    fclose(stdin);fclose(stdout);
}
