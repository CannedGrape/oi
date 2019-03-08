#include<cstdio>
#include<algorithm>
#define maxn 100010
#define mo 99999997
using namespace std;
struct pp{int h,p;}a[maxn],b[maxn],a1[maxn],b1[maxn];
int n,head=1,tail=1,flag;
long long ans=0,aa,bb,mm;
bool cmp(pp A,pp B)
{return A.h<B.h || (A.h==B.h && A.p<B.p);}

bool cmp2(pp A,pp B)
{return A.p<B.p;}

long long abss(long long x)
{return x>=0?x:-x;}

long long minn(long long x,long long y)
{return x<y?x:y;}

int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].h);
        a[i].p=i;
    }
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&b[i].h);
        b[i].p=i;
    }
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp);
    for (int i=1;i<=n;i++)
    {
        a1[i].h=a[i].h;
        a1[i].p=a[i].p;
        b1[i].h=b[i].h;
        b1[i].p=b[i].p;
        }
        
    
    
    
    
    head=1;
    int i;
    for (i=2;i<=n;i++)
    {
        if (a[i].h==a[head].h) continue;
        else
        {
            
            sort(b1+head,b1+i,cmp2);
             head=i;
        }
    }
    sort(b1+head,b1+i,cmp2);
    
    head=1;    
    for (i=2;i<=n;i++)
    {
        if (b[i].h==b[head].h) continue;
        else
        {
            sort(a1+head,a1+i,cmp2);
            head=i;
        }
    }
    sort(a1+head,a1+i,cmp2);
    
    mm=(long long) mo;
    for (i=1;i<=n;i++)
    {
        aa=(long long)a1[i].p;
        bb=(long long)b1[i].p;
        ans+=abss(aa-bb);
    }
    ans=(ans/2)%mm;
    printf("%lld\n",ans);

    //while (1);
    return 0;
}
    
