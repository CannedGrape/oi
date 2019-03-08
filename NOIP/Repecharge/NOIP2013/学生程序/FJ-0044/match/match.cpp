#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define P 99999997ll
struct kk{int num,id;}a[100010],d[100010];
int b[100010],c[100010],e[100010],f[100010],n,i,j,k;
long long ans=0;
bool cmp(kk i,kk j){return i.num<j.num;}
void swap(int &a,int &b){int t=a;a=b;b=t;}
using namespace std;
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++) {scanf("%d",&a[i].num);c[i]=a[i].num;a[i].id=i;}
    sort(a+1,a+n+1,cmp);
    for (i=1;i<=n;i++) scanf("%d",&b[i]);
    for (i=1;i<=n;i++) {d[i].num=b[a[i].id];d[i].id=i;}
    sort(d+1,d+n+1,cmp);  
    for (i=1;i<=n;i++) e[i]=d[i].id;
    for (i=1;i<=n;i++)
    {
        if (e[i]==i) continue;
        for (j=i+1;j<=n;j++) if (e[j]==i) break;
        ans+=j-i;
        for (k=j;k>i;k--) swap(e[k],e[k-1]);
    }
    printf("%lld\n",ans%P);
    return 0;
}
