#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define MAXN 10001
int n,m,p;
long long a[MAXN][MAXN],ans[30001];
bool bb[MAXN];
int allmin(int x,int y)
{
    if(x<y)
    return x;
    else
    return y;
}
int allmax(int x,int y)
{
    if(x>y)
    return x;
    else
    return y;
}
int solve(int b)
{
    int i,j,k,x,y;
    scanf("%d%d",&x,&y);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if((i!=j)&&(bb[i])&&(bb[j]))
    for(k=1;k<=n;k++)
    if((i!=k)&&(j!=k)&&(bb[k]))
    a[j][i]=a[i][j]=allmax(allmin(a[i][k],a[j][k]),a[i][j]);
    ans[b]=a[y][x];
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    memset(ans,0,sizeof(ans));
    memset(a,0,sizeof(a));
    memset(bb,false,sizeof(bb));
    int i,j,k,x,y,z;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        bb[x]=true;bb[y]=true;
        a[y][x]=a[x][y]=allmax(a[x][y],z);
    }
    scanf("%d",&p);
    for(i=1;i<=p;i++){solve(i);
    if(ans[i]==0)ans[i]--;
    }    
    for(i=1;i<=p;i++)
    printf("%lld\n",ans[i]);
   fclose(stdin);
    fclose(stdout);
    return 0;
}
