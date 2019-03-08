#include <cstdio>
#include <cstring>
#include <algorithm>

using std::max;

const int maxN=100000+100;

void work()
{
    int N;
    scanf("%d",&N);
    if(N==1)
        printf("1\n");
    else if(N==2)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==b)
            printf("1\n");
        else printf("2\n");
    }
    else
    {
        int a,b; // a上升, b下降
        int h,last;
        scanf("%d",&last);
        a=b=1;
        for(int i=2;i<=N;i++)
        {
            scanf("%d",&h);
            if(h==last)
                continue;
            if(h<last)
            {
                if(a!=-1)
                {
                    b=a+1;
                    a=-1;
                }
            }
            else
            {
                if(b!=-1)
                {
                    a=b+1;
                    b=-1;
                }
            }
            last=h;
        }
        printf("%d\n",max(a,b));
    }
}

int main()
{
    freopen("flower.in" ,"r",stdin );
    freopen("flower.out","w",stdout);
    work();
    return 0;
}
