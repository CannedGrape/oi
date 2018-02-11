#include<cstdio>
#define maxn 100010
using namespace std;
int h[maxn],n;
int ans=1,maxx,minn,i,j,f_ans;
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    // A 偶数高 
    int t=1,flag=1;
    ans=1;
    for (int i=2;i<=n;i++)
    {
        if (flag)
        {
            if (h[i]<=h[t]) t=i;
            else
            {
                ans++;
                t=i;
                flag=0;
            }
        }
        else
        {
            if (h[i]>=h[t]) t=i;
            else
            {
                ans++;
                t=i;
                flag=1;
            }
        }
        //printf("%d--%d  %d  %d\n",i,t,flag,ans);
    }
    //printf("%d\n",ans);
    f_ans=ans;
    //B 奇数高 
    t=1;ans=1;flag=1;
    for (int i=2;i<=n;i++)
    {
        if (flag)
        {
            if (h[i]>=h[t]) t=i;
            else
            {
                ans++;
                t=i;
                flag=0;
            }
        }
        else
        {
            if (h[i]<=h[t]) t=i;
            else
            {
                ans++;
                t=i;
                flag=1;
            }
        }
        //printf("%d--%d  %d  %d\n",i,t,flag,ans);
    }
    if (ans>f_ans)
        f_ans=ans;
    printf("%d\n",f_ans);
    
    //while (1);
    return 0;
}
