#include <stdio.h>
#include <stdlib.h>
#define MOD 99999997
int n,l[100010] = {0},l1[100010] = {0},l2[100010] = {0},pos[100010] = {0},list[100010][2] = {0},tarr[100010] = {0};
long long ans = 0;
int comp(const void *a,const void *b)
{
    return ((int*)a)[0]-((int*)b)[0];
}
void work(int ll,int rr)
{
    if(ll==rr) return;
    int i,j,mid = (ll+rr)>>1,posl,posr,cnt = 0;
    work(ll,mid);
    work(mid+1,rr);
    posl = ll;
    posr = mid+1;
    for(i=ll;i<=rr;i++)
    {
        if(l[posl]<=l[posr])
        {
            tarr[i] = l[posl];
            posl++;
            if(posl>mid)
            {
                for(j=posr;j<=rr;j++) tarr[++i] = l[j];
                break;
            }
        }
        else
        {
            ans = (ans+posr-posl-cnt)%MOD;
            cnt++;
            tarr[i] = l[posr];
            posr++;
            if(posr>rr)
            {
                for(j=posl;j<=mid;j++) tarr[++i] = l[j];
                break;
            }
        }
    }
    for(i=ll;i<=rr;i++) l[i] = tarr[i];
    return;
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&list[i][0]);
        list[i][1] = i;
    }
    qsort(list+1,n,sizeof(list[0]),comp);
    for(i=1;i<=n;i++) l1[list[i][1]] = i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&list[i][0]);
        list[i][1] = i;
    }
    qsort(list+1,n,sizeof(list[0]),comp);
    for(i=1;i<=n;i++) l2[list[i][1]] = i;
    for(i=1;i<=n;i++) pos[l2[i]] = i;
    for(i=1;i<=n;i++) l[i] = pos[l1[i]];
    work(1,n);
    printf("%lld\n",ans);
    return 0;
}
