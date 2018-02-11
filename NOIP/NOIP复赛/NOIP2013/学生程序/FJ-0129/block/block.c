#include<stdio.h>
int h[100010]={0};
int a[100010]={0};
int b[100010]={0};
int n;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    scanf("%d",&n);
    int i,j,sum1,sum2,ans,min,temp;
    sum1=sum2=1;
    min=99999;
    scanf("%d",&h[1]);
    for(i=2;i<=n;i++)
    {
        scanf("%d",&h[i]);
        if(h[i-1]<h[i])
        {
            sum2++;
            b[sum2-1]=h[i];
        }
        else if(h[i]<h[i-1])
        {
            sum1++;
            a[sum1-1]=h[i-1];
        }
        if(i==n)a[sum1]=h[i];
        if(h[i]<min)min=h[i];
    }
    ans=min;
    for(i=1;i<=sum1;i++)ans+=a[i];
    ans-=min*sum1;
    temp=min;
    for(i=1;i<=sum2;i++)temp+=b[i];
    temp-=min*sum2;
    if(temp<ans)ans=temp;
    printf("%d",ans);
    return 0;
}
