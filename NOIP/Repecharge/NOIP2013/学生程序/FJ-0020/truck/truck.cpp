#include<cstdio>
#include<algorithm>
#define maxn 20010
#define maxm 100010
using namespace std;
struct pp{int u,v,w;}ed[maxm];

int m,n,x,y,z,q,s,t,T,fu,fv;
int f[maxn],head[maxn];
//int next[maxm],u[maxm],v[maxm],w[maxm];
bool cmp(pp A,pp B)
{return A.w>B.w;}

int gf(int x)
{return f[x]==x?x:f[x]=gf(f[x]);}


int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);
    }
    sort(ed+1,ed+1+m,cmp);
    scanf("%d",&T);
    while (T--)
    {
        //memset(f,0,sizeof(f));
        for (int i=0;i<=n;i++)
            f[i]=i;
        scanf("%d%d",&s,&t);
        int flag=0;
        for (int i=1;i<=m;i++)
        {
            fu=gf(ed[i].u);
            fv=gf(ed[i].v);
            if (fu!=fv)
                f[fv]=fu;
            if (gf(s)==gf(t))
            {
                printf("%d\n",ed[i].w);
                flag=1;
                break;
            }
        }
        if (!flag) puts("-1");
    }
    //while (1);
    return 0;
} 
            
        
        
        
        
        
    
