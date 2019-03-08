#include<stdio.h>
int n,m,k,x;
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&k,&x);
    int i,j,temp,ans,t;
    temp=10;
    if(k==0)ans=(x+m)%n;
    else if(k==1)ans=(x+10*m)%n;
    else 
    {
        t=temp%n;
        for(i=1;i<=k-1;i++)temp=(temp*t)%n;
        ans=(x+temp*m)%n;
    }
    printf("%d",ans);   
    return 0;
}
