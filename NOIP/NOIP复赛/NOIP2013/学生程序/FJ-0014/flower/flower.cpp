#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
const int MAXN=100000+5;

int n;
int h[MAXN];

int getRanges()
{
    int tmpk,rangeK=0,count=0;
    bool undefined=true;
    for (int i=2; i<=n; ++i)
    {
        tmpk=h[i]-h[i-1];
        if (tmpk>0)
        {
            if (undefined || ((!undefined) && rangeK<0))
            {
                undefined=false;
                ++count;
                rangeK=tmpk;
            } 
        }
        else if (tmpk<0)
        {
            if (undefined || ((!undefined) && rangeK>0))
            {
                undefined=false;
                ++count;
                rangeK=tmpk;
            }
        }
    }
    return count;
}


int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d", &h[i]);
    }
    if (n==1)
    {
        printf("0\n");
    }
    else if (n==2)
    {
        printf("1\n");
    }
    else
    {
        int ans=getRanges()+1;
        if (ans==n)
            --ans;
        printf("%d\n", ans);
    }
    return 0;
}
