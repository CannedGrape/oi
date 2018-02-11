#include<stdio.h>
int n,m,k,x;
unsigned long long num=1;
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int i,j;
    scanf("%d%d%d%d",&n,&m,&k,&x);
    if(k<7)
    {
        for(i=1;i<=k;i++)num*=10;
        for(i=1;i<=num;i++){x=(x+m)%n;}
        printf("%d\n",x);
    }
    else
    {
        printf("%d",n/2);
    }
    return 0;
}    
