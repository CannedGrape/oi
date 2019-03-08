#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;

const int maxV=10000+100;
const int maxE=50000+100;
const int maxQ=30000+100;
const int maxNode=maxV*2; // maxV*2-1

struct Road
{
    int c[2],w;
};
bool operator<(const Road& a, const Road& b)
{
    return a.w>b.w;
}

struct Query
{
    int ans;
    int v; // the other point
    int next;
};

// i-th city must be i-th node, roads come after them
struct Node
{
    int p; //parent
    int c[2]; //child
    int w; // weight of road, if the node is a road
};

int V,E,Q;
Road road[maxE];

// build tree
int node_cnt;
Node node[maxNode+1];

// query
Query query[maxQ*2];
int header[maxV+1];

// tarjan
bool visited[maxV+1];
bool inS[maxNode+1];

// disjoint set
int DJSparent[maxNode+1];
int DJSstack[maxNode+1];

int rootDJS(int v)
{
    int r=v,Stop=0;
    while(DJSparent[r]!=-1)
    {
        DJSstack[Stop++] = r;
        r = DJSparent[r];
    }
    while(Stop>0)
        DJSparent[DJSstack[--Stop]]=r;
    return r;
}

void dprint(int v,int shift=0)
{
    for(int i=0;i<shift;i++)
        printf("   ");
    printf("%d\n", v);
    for(int i=0;i<2;i++)
        if(node[v].c[i]!=-1)
            dprint(node[v].c[i], shift+1);
}

void TarjanLCA(int v)
{
    const Node& n=node[v];
    inS[v]=true;
    if(v>V)
    {
        for(int i=0;i<2;i++)
        {
            TarjanLCA(n.c[i]);
            DJSparent[n.c[i]]=v;
        }
    }
    else
    {
        visited[v]=true;
        for(int q=header[v];q!=-1;q=query[q].next)
        {
            int w = query[q].v;
            if(!visited[w])
                continue;
            int r = rootDJS(w);
            if(inS[r])
                query[q].ans=r;
        }
    }
    inS[v]=false;
}

void work()
{
    scanf("%d%d",&V,&E);
    for(int i=0;i<E;i++)
        scanf("%d%d%d", &road[i].c[0], &road[i].c[1], &road[i].w);
    sort(road,road+E);

    node_cnt=0;
    for(int i=1;i<=V;i++)
    {
        node_cnt++;
        node[i].p=-1;
        node[i].c[0]=-1;
        node[i].c[1]=-1;
        //node[i].w=-1; //nvm
        DJSparent[i]=-1;
    }
    for(int e=0;e<E;e++)
    {
        if(rootDJS(road[e].c[0])==rootDJS(road[e].c[1]))
            continue;
        int n = ++node_cnt;
        node[n].w=road[e].w;
        node[n].p=-1;
        DJSparent[n]=-1;
        for(int i=0;i<2;i++)
        {
            int r = rootDJS(road[e].c[i]);
            node[n].c[i] = r;
            node[r].p=n;
            DJSparent[r]=n;
        }
    }

    memset(header+1,-1,sizeof(header[0])*V);
    scanf("%d",&Q);
    for(int i=0;i<Q;i++)
    {
        int u,v;
        scanf("%d%d", &u, &v);
        query[i<<1].v = v;
        query[i<<1].next = header[u];
        header[u]=i<<1;
        query[i<<1|1].v = u;
        query[i<<1|1].next = header[v];
        header[v]=i<<1|1;
        query[i<<1].ans = query[i<<1|1].ans = -1;
    }
    memset(visited+1,false,sizeof(visited[0])*V);
    memset(inS+1,false,sizeof(inS[0])*node_cnt);
    memset(DJSparent+1,-1,sizeof(DJSparent[0])*node_cnt);
    for(int i=1;i<=V;i++)
        if(!visited[i])
        {
            int r=i;
            while(node[r].p!=-1)
                r=node[r].p;
            // dprint(r);
            TarjanLCA(r);
        }
    for(int i=0;i<Q;i++)
    {
        int x=i<<1;
        if(query[x].ans==-1)
            x++;
        if(query[x].ans==-1)
            printf("-1\n");
        else
            printf("%d\n",node[query[x].ans].w);
    }
}

int main()
{
    freopen("truck.in" ,"r",stdin );
    freopen("truck.out","w",stdout);
    work();
    return 0;
}
