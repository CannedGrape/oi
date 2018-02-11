//match
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100010
#define MOD 99999997

int N;
struct node{
       int a,c,b;
}P[MAXN],Q[MAXN];
int to[MAXN*2],next[MAXN*2],map[MAXN],tot=0,cnt,ans=0;
bool vis[MAXN];

bool cmp(node A,node B)
{
     return A.a<B.a;
}

bool cmp1(node A,node B)
{
     return A.c<B.c;
}

void add(int x,int y)
{
     to[++tot]=y;next[tot]=map[x];map[x]=tot;
     to[++tot]=x;next[tot]=map[y];map[y]=tot;
}

void dfs(int p)
{
     cnt++;
     vis[p]=true;
     for(int k=map[p];k;k=next[k])
             if(!vis[to[k]])
                        dfs(to[k]);
}
                      
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
            scanf("%d",&P[i].a);
            P[i].c=i;
    }
    for(int i=1;i<=N;i++)
    {
            scanf("%d",&Q[i].a);
            Q[i].c=i;
    }
    std::sort(P+1,P+N+1,cmp);
    std::sort(Q+1,Q+N+1,cmp);
    for(int i=1;i<=N;i++)
    {
            P[i].b=i;
            Q[i].b=i;
    }
    std::sort(P+1,P+N+1,cmp1);
    std::sort(Q+1,Q+N+1,cmp1);
    for(int i=1;i<=N;i++)
            add(P[i].b,Q[i].b);
    for(int i=1;i<=N;i++)
            if(!vis[i])
            {
                       cnt=0;
                       dfs(i);
                       ans=(ans+cnt-1)%MOD;
            }
    printf("%d\n",ans);
    return 0;
}
