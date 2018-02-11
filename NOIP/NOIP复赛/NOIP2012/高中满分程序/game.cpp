#include <iostream>
#include <cstdio>
#include <cmath>
#include <memory.h>
#define MAXN 1010
#define MAXBIT 5010
#define INF 1000000000
#define PREC 1e-8
using namespace std;
long double lga[MAXN],lgb[MAXN];
int a[MAXN],b[MAXN],met[MAXN],ans[MAXBIT+10],ansi[MAXBIT+10],ls[MAXBIT+10];
bool state[MAXN];
long double l,r,mid,slga;
int i,j,n;
bool check(long double rate)
{
    int i,j,id;
    long double na=slga,tmp;
    memset(state,0,sizeof(state));
    for(i=1;i<=n;i++)
    {
        tmp=-INF; id=0;
        for(j=1;j<=n;j++)
            if((!state[j]) && ((na-lgb[j])<=rate) && (lga[j]>tmp))
            {
                tmp=lga[j];
                id=j;
            }
        if(id==0) return 0;
        met[i]=id;
        state[id]=1;
        na-=tmp;
    }
    return 1;
}
long double floatabs(long double x)
{
    if(x<0) return -x; else return x;
}
void opit(int k)
{
    int i;
    long long ans=a[0];
    for(i=k;i<=n;i++)
        ans*=a[met[i]];
    //cout<<"Tc "<<ans/a[met[k]]<<endl;
    ans/=b[met[k]];
    cout<<ans<<endl;
}
void prod(int k)
{
    int i,mp=a[k];
    memset(ls,0,sizeof(ls));
    for(i=1;i<=MAXBIT;i++)
    {
        ls[i]=ls[i]+ans[i]*mp;
        ls[i+1]=ls[i+1]+(ls[i]/10);
        ls[i]%=10;
    }
    memcpy(ans,ls,sizeof(ls));
}
void divi(int k)
{
    int i,dp=b[k];
    for(i=MAXBIT;i>=1;i--)
    {
        ansi[i]=ans[i]/dp;
        ans[i-1]=ans[i-1]+(ans[i]%dp)*10;
    }
}
void opit100(int k)
{
    int i,j;
    memset(ans,0,sizeof(ans));
    ans[1]=1;
    prod(0);
    for(i=k+1;i<=n;i++)
        prod(met[i]);
    //cout<<"Tw "; for(j=10;j;j--) cout<<ans[j]; cout<<endl;
    b[met[k]]=b[met[k]]/a[met[k]];
    divi(met[k]);
    i=MAXBIT;
    while(ansi[i]==0)i--;
    for(j=i;j>=1;j--)
        printf("%d",ansi[j]);
    printf("\n");
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    slga=0;
    for(i=0;i<=n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        b[i]*=a[i];
        lga[i]=log(a[i]); lgb[i]=log(b[i]);
        slga=slga+lga[i];
    }
    l=0; r=slga; mid=(l+r)/2;
    check(1);
    while(r-l>PREC)
    {
        if(check(mid))
            r=mid;
        else
            l=mid;
        mid=(l+r)/2;
    }
    check(r);
    for(i=1;i<=n;i++)
    {
        if(floatabs(slga-lgb[met[i]]-r)<PREC)
        {
            //opit(i);
            opit100(i);
            break;
        }
        slga-=lga[met[i]];
    }
    //cout<<mid<<endl;
    //for(i=1;i<=n;i++) cout<<met[i]<<endl;
    //system("pause");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
