#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int e[100010][4],p[10010]={};
int n,m,Q;
int f[1010][1010]={};
int top=0;
int dis[10010],q[1000010];
short v[10010]={};
void add(int x,int y,int z)
{
    top++;
    e[top][0]=x;
    e[top][1]=y;
    e[top][2]=z;
    e[top][3]=p[x];
    p[x]=top;
}
int min(int x,int y)
{
    if(x<y) return x;
    return y;
}
void spfa(int x)
{
    int i,a,val;
    memset(dis,-1,sizeof(dis));
    memset(v,0,sizeof(v));
    int head=0,tail=1;
    q[1]=x;
    v[x]=1;
    dis[x]=100000;
    while(head<tail)
    {
        head++;
        a=q[head];
        i=p[a];
        while(i!=0)
        {
            val=min(dis[a],e[i][2]);
            if(val>dis[e[i][1]])
            {
                dis[e[i][1]]=val;
                if(v[e[i][1]]==0)
                {
                    tail++;
                    q[tail]=e[i][1];
                    v[e[i][1]]=1;
                }
            }
            i=e[i][3];
        }
        v[a]=0;
    }
    for(i=1;i<=n;i++)
    {
        if(i==x) continue;
        f[i][x]=f[x][i]=dis[i];
    }
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int i,j,k,x,y,z;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);add(y,x,z);
    }
    scanf("%d",&Q);
    for(i=1;i<=Q;i++)
    {
        scanf("%d%d",&x,&y);
        if(f[x][y]!=0) printf("%d\n",f[x][y]);
        else
        {
            spfa(x);
            spfa(y);
            printf("%d\n",f[x][y]);
        }
    }
    return 0;
}
