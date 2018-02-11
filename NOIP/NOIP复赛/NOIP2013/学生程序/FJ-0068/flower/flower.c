#include <stdio.h>
int n,list[100001] = {0},ans = 0;
int max(int a,int b)
{
    return a>b?a:b;
}
void work1()
{
    int i,now,tans = 0;
    short swi;
    now = list[1];
    swi = 1;
    tans = 1;
    for(i=2;i<=n;i++)
    {
        if(swi)
        {
            if(list[i]>now)
            {
                tans++;
                swi = 0;
            }
            now = list[i];
        }
        else
        {
            if(list[i]<now)
            {
                tans++;
                swi = 1;
            }
            now = list[i];
        }
    }
    ans = max(ans,tans);
    return;
}
void work2()
{
    int i,now,tans = 0;
    short swi;
    now = list[1];
    swi = 1;
    tans = 1;
    for(i=2;i<=n;i++)
    {
        if(swi)
        {
            if(list[i]<now)
            {
                tans++;
                swi = 0;
            }
            now = list[i];
        }
        else
        {
            if(list[i]>now)
            {
                tans++;
                swi = 1;
            }
            now = list[i];
        }
    }
    ans = max(ans,tans);
    return;
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&list[i]);
    work1();
    work2();
    printf("%d\n",ans);
    return 0;
}
