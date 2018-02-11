#include<stdio.h>
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    long int i,ii,j,n,x,tmp,ans=0;
    scanf("%ld %ld",&n,&x);
    for(i=1;i<=n;i++)
    {
                     ii=i;
                     while(ii!=0)
                     {
                                 if(ii%10==x)ans++;
                                 ii/=10;
                     }
    }
    printf("%ld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
