#include <stdio.h>
#include <stdlib.h>
int n,m,q,e[50001][3] = {0},p[10001] = {0},root[10001] = {0},qlist[30001][2] = {0},ans[30001] = {0},cnt = 0;
int comp(const void *a,const void *b)
{
    return ((int*)b)[2]-((int*)a)[2];
}
void adde(int sn,int fn,int val,int id)
{
    e[id][0] = sn;
    e[id][1] = fn;
    e[id][2] = val;
}
int findroot(int nod)
{
    if(root[nod]!=nod) root[nod] = findroot(root[nod]);
    return root[nod];
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int i,j,sn,fn,val,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) root[i] = i;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&sn,&fn,&val);
        adde(sn,fn,val,i);
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&qlist[i][0],&qlist[i][1]);
        ans[i] = -1;
    }
    qsort(e+1,m,sizeof(e[0]),comp);
    for(i=1;i<=m;i++)
    {
        sn = e[i][0];
        fn = e[i][1];
        val = e[i][2];
        a = findroot(sn);
        b = findroot(fn);
        if(a==b) continue;
        root[a] = b;
        for(j=1;j<=q;j++)
        {
            if(ans[j]==-1)
            {
                a = findroot(qlist[j][0]);
                b = findroot(qlist[j][1]);
                if(a==b)
                {
                    ans[j] = val;
                    cnt++;
                }
            }
        }
        if(cnt==q) break;
    }
    for(i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}
