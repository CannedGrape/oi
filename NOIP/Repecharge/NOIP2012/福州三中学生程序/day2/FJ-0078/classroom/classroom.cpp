#include <iostream>
#include <cstdio>
#include <memory.h>
#define MAXN 1000010
#define MAXM 1000010
using namespace std;
int ma[MAXN],so[MAXN],a[MAXN],d[MAXM],s[MAXM],t[MAXM];
int n,m,i,l,r,mid;
bool check(int k)
{
    int i,tmp=0;
    memcpy(a,ma,sizeof(ma));
    for(i=1;i<=k;i++)
    {
        a[s[i]]-=d[i];
        a[t[i]+1]+=d[i];
    }
    for(i=1;i<=n;i++)
    {
        tmp+=a[i];
        if(tmp<0) return 0;
    }
    return 1;
}
int main()
{
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) 
    {
        scanf("%d",&so[i]);
        ma[i]=so[i]-so[i-1];
    }
    for(i=1;i<=m;i++) scanf("%d%d%d",&d[i],&s[i],&t[i]);
    l=0; r=m; mid=(l+r+1)/2;
    while(r>l)
    {
        if(check(mid))
            l=mid;
        else
            r=mid-1;
        mid=(l+r+1)/2;
    }
    if(l==m)
        printf("0\n");
    else
        printf("-1\n%d\n",l+1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
