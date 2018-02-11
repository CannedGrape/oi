/* truck.cpp NOIP 2013 day1.C
   By Sweetdumplings @ FZYZ / Fudan University
*/
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 10003
#define MAXM 60003
using namespace std;
struct eList
{
    int tot,Head[MAXN],V[MAXM*2],Pre[MAXM*2],W[MAXM*2];
    void AddEdge(int a,int b,int c)
    {
        ++tot;
        W[tot]=c;
        V[tot]=b;
        Pre[tot]=Head[a];
        Head[a]=tot;
    }
    void AddEdge2(int a,int b,int c)
    {
        AddEdge(a,b,c);
        AddEdge(b,a,c);
    }
}g;
struct EdgeType
{
    int u,v,w;
}EL[MAXM];
int N,M,Q;
bool cmp(EdgeType a,EdgeType b)
{
    return a.w>b.w;
}
namespace Set
{
    int s[MAXN];
    int Fa(int v)
    {
        return s[v]==v?s[v]:s[v]=Fa(s[v]);
    }
    bool Diff(int a,int b)
    {
        return Fa(a)!=Fa(b);
    }
    void Merge(int a,int b)
    {
        s[Fa(b)]=Fa(a);
    }
    void Init(int N)
    {
        for (int i=1;i<=N;++i) s[i]=i;
    }
};
void Kruskal()
{
    sort(EL+1,EL+M+1,cmp);
    Set::Init(N);
    int Count=0;
    for (int i=1;i<=M;++i)
    {
        if (Set::Diff(EL[i].u,EL[i].v))
        {     
            g.AddEdge2(EL[i].u,EL[i].v,EL[i].w);
            Set::Merge(EL[i].u,EL[i].v);
            if (++Count==N) break;
        }
    }
}
//LCA Part
int Deepth[MAXN];
bool Mark[MAXN];
int Ancent[MAXN][15];
int WeiLim[MAXN][15];
void GetDeepth(int now)
{
    Mark[now]=1;
    for (int p=g.Head[now];p;p=g.Pre[p])
    {
        if (Mark[g.V[p]]) continue;
        Deepth[g.V[p]]=Deepth[now]+1;
        Ancent[g.V[p]][0]=now;
        WeiLim[g.V[p]][0]=g.W[p];
        GetDeepth(g.V[p]);
    }
    Mark[now]=0;
}
void GetAncent(int now)
{
    Mark[now]=1;
    for (int i=1;(1<<i)<=Deepth[now];++i)
    {
        Ancent[now][i]=Ancent[Ancent[now][i-1]][i-1];
        WeiLim[now][i]=min(WeiLim[now][i-1],WeiLim[Ancent[now][i-1]][i-1]);
    }
    for (int p=g.Head[now];p;p=g.Pre[p])
    {
        if (!Mark[g.V[p]]) GetAncent(g.V[p]);
    }
    Mark[now]=0;
}
void LCAInit()
{
    Deepth[N]=0;
    GetDeepth(N);
    GetAncent(N);
}
int Query(int A,int B)
{
    int Ans=0x7fffffff;
    if (Deepth[A]<Deepth[B])
    {
        int k=A;
        A=B;
        B=k;
    }
    int DeltaDeepth=Deepth[A]-Deepth[B];
    for (int i=0;DeltaDeepth;++i)
    {
        if (DeltaDeepth&(1<<i))
        {
            Ans=min(Ans,WeiLim[A][i]);
            A=Ancent[A][i];
            DeltaDeepth-=(1<<i);
        }
    }
    if (A==B) return Ans;
    for (int i=14;i>=0;--i)
    {
        if (Ancent[A][i]==Ancent[B][i]) continue;
        Ans=min(Ans,WeiLim[A][i]);
        Ans=min(Ans,WeiLim[B][i]);
        A=Ancent[A][i];
        B=Ancent[B][i];
    }
    if (A!=B)
    {
        Ans=min(Ans,WeiLim[A][0]);
        Ans=min(Ans,WeiLim[B][0]);
    }
    return Ans;
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d%d",&N,&M);
    for (int i=1;i<=M;++i)
    {
        scanf("%d%d%d",&EL[i].u,&EL[i].v,&EL[i].w);
    }
    //Super Root:N+1
    for (int i=1;i<=N;++i)
    {
        ++M;
        EL[M].u=N+1;
        EL[M].v=i;
        EL[M].w=-1;
    }
    N++;
    Kruskal();
    LCAInit();
    scanf("%d",&Q);
    for (int i=1;i<=Q;++i)
    {
        int A,B;
        scanf("%d%d",&A,&B);
        printf("%d\n",Query(A,B));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
