#include <iostream>
#include <cstdio>
#include <memory.h>
#define MAXN 100010
#define INF 1000000000
#define PREC 1e-8
using namespace std;
int h[MAXN],mapa[MAXN],mapb[MAXN],da[MAXN],db[MAXN],x[MAXN];
int n,m,i,j,id1,id2,ra,rb,sta,lim,h1;
double min1,min2,mini;
int intabs(int xz)
{
    if(xz<0) return -xz; else return xz;
}
double floatabs(double x)
{
    if(x<0) return -x; else return x;
}
double dis(int i,int j)
{
    if(h[j]>h[i]) return h[j]-h[i]+0.5; else return h[i]-h[j];
}
void run(int sta,int lim,int &ra,int &rb)
{
    ra=rb=0;
    while(1)
    {
        if((mapa[sta]==0)||(da[sta]>lim))
            return;
        else
        {
            lim-=da[sta];
            ra+=da[sta];
            sta=mapa[sta];
        }
        if((mapb[sta]==0)||(db[sta]>lim))
            return;
        else
        {
            lim-=db[sta];
            rb+=db[sta];
            sta=mapb[sta];
        }
    }
    return;
}
int main()
{
    freopen("drive.in","r",stdin);
    freopen("drive.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for(i=1;i<=n;i++)
    {
        id1=id2=0;
        min1=min2=INF+1;
        for(j=i+1;j<=n;j++)
        {
            if(dis(i,j)<min1)
            {
                min2=min1; id2=id1;
                min1=dis(i,j); id1=j;
            }
            else
                if(dis(i,j)<min2)
                {
                    min2=dis(i,j); id2=j;
                }
        }
        mapa[i]=id2; mapb[i]=id1;
        db[i]=intabs(h[i]-h[id1]);
        da[i]=intabs(h[i]-h[id2]);
    }
    scanf("%d",&x[0]);
    mini=INF*2; id1=0; h1=0;
    for(i=1;i<=n;i++)
    {
        run(i,x[0],ra,rb);
        if((rb==0)&&(mini>INF+1))
        {
            if(h[i]>h1)
            {
                h1=h[i];
                id1=i;
            }   
        }
        else
            if(ra*1.0/rb<mini-PREC)
            {
                mini=ra*1.0/rb;
                id1=i;
                h1=h[i];
            }
            else
                if(floatabs(ra*1.0/rb-mini)<PREC)
                {
                    if(h[i]>h1)
                    {
                        h1=h[i];
                        id1=i;
                    }
                }
    }
    printf("%d\n",id1);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&sta,&lim);
        run(sta,lim,ra,rb);
        printf("%d %d\n",ra,rb);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
