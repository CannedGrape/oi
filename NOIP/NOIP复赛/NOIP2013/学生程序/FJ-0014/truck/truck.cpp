#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>

const int MAXN=10005;
const int MAXM=50005;
const int MAXQ=30005;

typedef struct
{
    int a,b,z;
} TEdge;

typedef struct
{
    int fromv, endv, z, next;
} TETable;

inline bool edgecmp(const TEdge &a, const TEdge &b)
{
    return (a.z>b.z);
}

inline int Min(const int a, const int b)
{
    return (a<b)?a:b;
}



int n,m,q;
TEdge e[MAXM];
TETable et[MAXM*2 + 5];
int start[MAXN], ecount;
int upper[MAXN], father[MAXN], maxvalue[MAXN], zUp[MAXN];


inline void addEdge(const int a, const int b, const int z)
{
    ++ecount;
    et[ecount].fromv=a;
    et[ecount].endv=b;
    et[ecount].z=z;
    et[ecount].next=start[a];
    start[a]=ecount;
}

int getfather(const int x)
{
    if (father[x]!=x)
        father[x]=getfather(father[x]);
    return father[x];
}

void getUnion(const int x, const int y)
{
    int fx=getfather(x);
    int fy=getfather(y);
    father[fx]=fy;
}

void getMST()
{
    for (int i=1; i<=n; ++i)
    {
        father[i]=i;
    }
    int count=0;
    for (int i=1; i<=m && count<n-1; ++i)
    {
        if (getfather(e[i].a)!=getfather(e[i].b))
        {
            addEdge(e[i].a,e[i].b,e[i].z);
            addEdge(e[i].b,e[i].a,e[i].z);
            ++count;
            getUnion(e[i].a, e[i].b);
        }
    }
}

bool vst[MAXN];

void buildTree(const int now)
{
    vst[now]=true;
    for (int p=start[now]; p; p=et[p].next)
    {
        if (!vst[et[p].endv])
        {
            upper[et[p].endv]=now;
            maxvalue[et[p].endv]=Min(maxvalue[now],et[p].z);
            zUp[et[p].endv]=et[p].z;
            buildTree(et[p].endv);
        }
    }
}

void Input()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; ++i)
    {
        scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].z);
    }
    std::sort(e+1,e+m+1,edgecmp);
}

void Solve()
{
    scanf("%d", &q);
    int xx,yy,ans;
    for (int i=1; i<=q; ++i)
    {
        scanf("%d%d", &xx, &yy);
        if (getfather(xx) != getfather(yy))
        {
            printf("-1\n");
        }
        else
        {
            bool found=false;
            int min1=2147483600;
            for (int tmp=xx; tmp; tmp=upper[tmp])
            {
                min1=Min(min1,zUp[tmp]);
                if (upper[tmp]==yy)
                {
                    found=true;
                    break;
                }
            }
            if (!found)
            {
                min1=2147483600;
                for (int tmp=yy; tmp; tmp=upper[tmp])
                {
                    min1=Min(min1,zUp[tmp]);
                    if (upper[tmp]==xx)
                    {
                        found=true;
                        break;
                    }
                }
            }
            if (found)
                ans=min1;
            else
                ans=Min(maxvalue[xx],maxvalue[yy]);
            printf("%d\n", ans);
        }
    }
}

int main()
{

//
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    Input();
    getMST();
    memset(upper,0,sizeof(upper));
    memset(vst,false,sizeof(vst));
    memset(maxvalue,63,sizeof(maxvalue));  
    for (int i=1; i<=n; ++i)
    {
        if (!vst[i])
            buildTree(i);
    }
    Solve();
//    system("pause");
    
    return 0;
}
