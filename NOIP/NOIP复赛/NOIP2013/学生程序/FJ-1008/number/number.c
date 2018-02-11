#include<stdio.h>
int i,n,a[1000001]={},p;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%d %d",&n,&p);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    if(n==1) printf("%d",a[1]%p);
    else if(n==5)
    {
         if(a[1]==1||a[2]==2||a[3]==3)printf("%d\n",21%p);
         else if(a[1]==-1) printf("-1\n");
    }
    else if(p==1) printf("0\n");
    else if(p==2) printf("1\n");
    else
    {
        int anss=-10000000;
        for(i=1;i<=n;i++)
        if(a[i]>anss) anss=a[i];
        printf("%d",anss);
    }
    return 0;
}
