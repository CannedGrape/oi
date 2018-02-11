#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int n,p,a[1000001];
long long sp[1000001],ans;
long long Max(long long a,long long b){ return a>b?a:b;}
long long Abs(long long a){ return a>0?a:-a;}
void fir();
void sec();

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%d%d",&n,&p);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    fir();
    sec();
    if(ans<0) printf("-");
    ans=Abs(ans);
    printf("%lld",ans%p);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

void fir()
{
     sp[1]=a[1]; 
     for(int i=2; i<=n; ++i) sp[i]=Max(Max(a[i],a[i]+sp[i-1]),sp[i-1]);
}

void sec()
{
     ans=sp[1];   
     for(int i=2; i<=n; ++i) ans=Max(ans,sp[i-1]+ans);
}
 
