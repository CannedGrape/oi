#include<stdio.h>
int n,a[100005]={0},max[100005]={0},min[100005]={0};
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    max[1]=a[1];min[1]=a[1];
    max[0]=1;min[0]=1;
    for(i=2;i<=n;i++)
    {
        if(max[0]%2==0)
        {
            if(a[i]>max[max[0]])max[max[0]]=a[i];
            if(a[i]<max[max[0]]){max[0]++;max[max[0]]=a[i];}
        }
        if(max[0]%2==1)
        {
            if(a[i]>max[max[0]]){max[0]++;max[max[0]]=a[i];}
            if(a[i]<max[max[0]])max[max[0]]=a[i];
        }
        if(min[0]%2==0)
        {
            if(a[i]>min[min[0]]){min[0]++;min[min[0]]=a[i];}
            if(a[i]<min[min[0]])min[min[0]]=a[i];
        }
        if(min[0]%2==1)
        {
            if(a[i]>min[min[0]])min[min[0]]=a[i];
            if(a[i]<min[min[0]]){min[0]++;min[min[0]]=a[i];}
        }
    }
    if(max[0]<min[0])max[0]=min[0];
    printf("%d\n",max[0]);
    //while(1);
    return 0;
}
