#include <cstdio>
#include <cstring>
#include <cassert> // XXX

const int maxN=100000+100;
const int maxH=10000;
const int safeMaxH=maxH+100;

int N;
int a[maxN+2];
int vall[maxH+1];
int peak[maxH+1];

void work()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d",&a[i]);
    a[0]=a[1]; // not needed
    a[N+1]=a[N]-1;

    int lastH=a[1]-1;
    memset(vall,0,sizeof(vall));
    memset(peak,0,sizeof(peak));
    for(int i=1;i<=N;i++)
    {
        if(a[i]==a[i+1])
            continue;
        if(a[i]<lastH && a[i]<a[i+1])
            vall[a[i]]++;
        if(a[i]>lastH && a[i]>a[i+1])
            peak[a[i]]++;
        lastH = a[i];
    }

//#warning
    /*
    for(int i=0;i<=10;i++)
        printf("%d ", peak[i]);
    printf("\n");
    for(int i=0;i<=10;i++)
        printf("%d ", vall[i]);
    printf("\n");
    */

    int segs = 1 + vall[0], ans=0; // no need for int64
    for(int h=1;h<=maxH;h++)
    {
        ans+=segs;
        segs-=peak[h];
        segs+=vall[h];
    }

    printf("%d\n",ans);
}

int main()
{
    freopen("block.in" ,"r",stdin );
    freopen("block.out","w",stdout);
    work();
    return 0;
}
