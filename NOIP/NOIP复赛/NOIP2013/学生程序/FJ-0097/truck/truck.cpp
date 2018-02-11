//truck
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 10010
#define MAXM 50010
#define INF 2147483640
#define min(a,b) a<b?a:b

int N,M,Q;
struct edge{
       int x,y,c;
}P[MAXM];
int to[MAXM*2],next[MAXM*2],co[MAXM*2],map[MAXN],tot=0;
int fa[MAXN],getf[MAXN][15],la[MAXN][15],belong[MAXN],dep[MAXN],blo=0;
bool avi[MAXM];

bool cmp(edge A,edge B)
{
     return A.c>B.c;
}

int find(int p)
{
    if(fa[p]==p) return p;
    fa[p]=find(fa[p]);
    return fa[p];
}

void add(int x,int y,int d)
{
     to[++tot]=y;next[tot]=map[x];co[tot]=d;map[x]=tot;
     to[++tot]=x;next[tot]=map[y];co[tot]=d;map[y]=tot;
}

void dfs(int p,int pre)
{
     belong[p]=blo;
     for(int k=map[p];k;k=next[k])
             if(to[k]!=pre)
             {
                           getf[to[k]][0]=p;
                           la[to[k]][0]=co[k];
                           dep[to[k]]=dep[p]+1;
                           dfs(to[k],p);
             }
}

int Get_Min(int a,int b)
{
    if(dep[a]<dep[b])
    {
                     int temp=a;a=b;b=temp;
    }
    int j=14,ans=INF;
    while(dep[a]>dep[b])
    {
                        if(dep[getf[a][j]]>=dep[b])
                        {
                                                ans=min(ans,la[a][j]);
                                                a=getf[a][j];
                        }
                        j--;
    }
    if(a==b)return ans;
    for(int j=14;j;j--)
            if(getf[a][j]^getf[b][j])
            {
                                     ans=min(ans,la[a][j]);
                                     ans=min(ans,la[b][j]);
                                     a=getf[a][j];
                                     b=getf[b][j];
            }
    if(a==b) return ans;
    ans=min(ans,la[a][0]);
    ans=min(ans,la[b][0]);
    return ans;
}

int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d%d",&N,&M);
    for(int i=1;i<=M;i++)
            scanf("%d%d%d",&P[i].x,&P[i].y,&P[i].c);
    std::sort(P+1,P+M+1,cmp);
    memset(la,60,sizeof(la));
    for(int i=1;i<=N;i++)
            fa[i]=i;
    for(int i=1;i<=M;i++)
    {
            int fx=find(P[i].x),fy=find(P[i].y);
            if(fx==fy) continue;
            avi[i]=true;
            add(P[i].x,P[i].y,P[i].c);
            fa[fx]=fy;
    }
    for(int i=1;i<=N;i++)
            if(!belong[i])
            {
                          blo++;
                          dep[i]=1;
                          dfs(i,0);
            }
    for(int j=1;j<=14;j++)
            for(int i=1;i<=N;i++)
            {
                    getf[i][j]=getf[getf[i][j-1]][j-1];
                    la[i][j]=min(la[i][j-1],la[getf[i][j-1]][j-1]);
            }
    scanf("%d",&Q);
    int a,b;
    while(Q--)
    {
              scanf("%d%d",&a,&b);
              if(belong[a]^belong[b])
              {
                                     printf("-1\n");
                                     continue;
              }
              printf("%d\n",Get_Min(a,b));
    }
    return 0;
}
