#include <iostream>
#include <cstdio>
#include <memory.h>
#define MAXN 100050
#define MAXM 100100
using namespace std;
int st[MAXN],ed[MAXN],fa[MAXN],fdis[MAXN],gst[MAXN],ged[MAXN],gv[MAXN],gnext[MAXN];
int v[MAXM],w[MAXM],next[MAXM],fgs[MAXN],zzs[MAXN],zzz[MAXN],zz[MAXN],lhere[MAXN],fdlist[MAXN],tonode[MAXN],id[MAXN];
long long ta[MAXM],tb[MAXM],lt[MAXN],mini[MAXN];
bool state[MAXN],cannot[MAXN];
int n,m,i,j,noe,tmpu,tmpv,tmpw,freenum,tanum,tbnum,tmp,chnum,y,gnoe;
long long ltime,l,r,mid;
void Add_Edge(int x,int y,int z)
{
    v[++noe]=y; w[noe]=z;
    if(st[x])
        next[ed[x]]=noe;
    else
        st[x]=noe;
    ed[x]=noe;
}
void Add_Edge2(int x,int y)
{
    gv[++gnoe]=y;
    if(gst[x])
        gnext[ged[x]]=gnoe;
    else
        gst[x]=gnoe;
    ged[x]=gnoe;
}
void Dfs(int x)
{
    int i,y;
    state[x]=1;
    for(y=v[i=st[x]];i;y=v[i=next[i]])
        if(!state[y])
        {
            fa[y]=x;
            fdis[y]=w[i];
            Dfs(y);
        }
}
void Qsorta(int l,int r)
{
    int i=l,j=r;
    long long x=ta[(l+r)>>1],t;
    while(i<=j)
    {
        while(ta[i]<x) i++;
        while(x<ta[j]) j--;
        if(i<=j)
        {
            t=ta[i]; ta[i]=ta[j]; ta[j]=t;
            i++; j--;
        }
    }
    if(l<j) Qsorta(l,j);
    if(i<r) Qsorta(i,r);
}
void Qsortb(int l,int r)
{
    int i=l,j=r;
    long long x=tb[(l+r)>>1],t;
    while(i<=j)
    {
        while(tb[i]<x) i++;
        while(x<tb[j]) j--;
        if(i<=j)
        {
            t=tb[i]; tb[i]=tb[j]; tb[j]=t;
            i++; j--;
        }
    }
    if(l<j) Qsortb(l,j);
    if(i<r) Qsortb(i,r);
}
void Check(int x)
{
    int i,y,minim=1000000000;
    state[x]=1;
    for(y=v[i=st[x]];i;y=v[i=next[i]])
        if(!state[y])
        {
            Check(y);
            if(fgs[y]<minim) minim=fgs[y];
        }
    if(minim==1000000000) minim=0;
    fgs[x]=zzs[x]+minim;
    return;
}
bool Work_old(long long now)
{
    //INIT
    memset(zzs,0,sizeof(zzs));
    //Note: init is not completed. Ask for modifing. <- COMPLETED.
    //FLOAT
    freenum=0;
    for(i=1;i<=m;i++)
    {
        tmp=zzz[i]; ltime=now;
        while((fa[tmp]>1)&&(fdis[tmp]<=ltime))
        {
            ltime-=fdis[tmp];
            tmp=fa[tmp];
        }
        zzs[zz[i]=tmp]++; lt[i]=ltime;
        if(ltime>=fa[tmp])
            fdlist[++freenum]=i;
    }
    //CHECK
    tmp=0; tbnum=0;
    memset(state,0,sizeof(state));
    state[1]=1;
    for(i=1;i<=chnum;i++)
    {
        y=tonode[i];
        Check(y);
        tmp+=fgs[y];
        if(fgs[y]==0) 
            tb[++tbnum]=fdis[y];
    }
    if(tbnum==0) return 1;
    if(tmp<chnum) return 0;
    if(freenum<tbnum) return 0;
    memset(cannot,0,sizeof(cannot));
    memset(id,0,sizeof(id));
    for(i=1;i<=n;i++)
        mini[i]=(long long)(1000000000)*1000000;
    for(i=1;i<=freenum;i++)
    {
        j=fdlist[i];
        if(lt[j]<mini[zz[j]])
        {
            mini[zz[j]]=lt[j];
            id[zz[j]]=j;
        }
    }
    for(i=1;i<=n;i++) cannot[id[i]]=1;
    tanum=0;
    for(i=1;i<=freenum;i++)
    {
        j=fdlist[i];
        if(!cannot[j])
            ta[++tanum]=lt[j]-fdis[zz[j]];
    }
    Qsorta(1,tanum);
    Qsortb(1,tbnum);
    if(tanum<tbnum) return 0;
    for(i=j=1;i<=tbnum;i++)
    {
        while((ta[j]<tb[i])&&(j<=tanum)) j++;
        if(j>tanum) return 0;
        j++;
    }
    return 1;
}
void Flow(int rt,int x,long long ltime)
{
    int i,y;
    state[x]=1;
    if(ltime<0) return;
    for(y=gv[i=gst[x]];i;y=gv[i=gnext[i]])
    {
        zz[y]=rt;
        lt[y]=ltime;
        fdlist[++freenum]=y;
        fgs[rt]++;
    }
    for(y=v[i=st[x]];i;y=v[i=next[i]])
        if(!state[y])
            Flow(rt,y,ltime-fdis[y]);
}
bool Work(long long now)
{
    //INIT
    memset(zzs,0,sizeof(zzs));
    //Note: init is not completed. Ask for modifing. <- COMPLETED.
    //FLOAT
    freenum=0;
    /*
    for(i=1;i<=m;i++)
    {
        tmp=zzz[i]; ltime=now;
        while((fa[tmp]>1)&&(fdis[tmp]<=ltime))
        {
            ltime-=fdis[tmp];
            tmp=fa[tmp];
        }
        zzs[zz[i]=tmp]++; lt[i]=ltime;
        if(ltime>=fa[tmp])
            fdlist[++freenum]=i;
    }
    */
    memset(lhere,0,sizeof(lhere));
    memset(state,0,sizeof(state));
    for(i=1;i<=m;i++) lhere[zzz[i]]++;
    state[1]=1;
    for(y=v[i=st[1]];i;y=v[i=next[i]]) 
        Flow(y,y,now);
    
    //CHECK
    tmp=0; tbnum=0;
    memset(state,0,sizeof(state));
    state[1]=1;
    for(i=1;i<=chnum;i++)
    {
        y=tonode[i];
        //Check(y);
        tmp+=fgs[y];
        if(fgs[y]==0) 
            tb[++tbnum]=fdis[y];
    }
    if(tbnum==0) return 1;
    if(tmp<chnum) return 0;
    if(freenum<tbnum) return 0;
    memset(cannot,0,sizeof(cannot));
    memset(id,0,sizeof(id));
    for(i=1;i<=n;i++)
        mini[i]=(long long)(1000000000)*1000000;
    for(i=1;i<=freenum;i++)
    {
        j=fdlist[i];
        if(lt[j]<mini[zz[j]])
        {
            mini[zz[j]]=lt[j];
            id[zz[j]]=j;
        }
    }
    for(i=1;i<=n;i++) cannot[id[i]]=1;
    tanum=0;
    for(i=1;i<=freenum;i++)
    {
        j=fdlist[i];
        if(!cannot[j])
            ta[++tanum]=lt[j]-fdis[zz[j]];
    }
    Qsorta(1,tanum);
    Qsortb(1,tbnum);
    if(tanum<tbnum) return 0;
    for(i=j=1;i<=tbnum;i++)
    {
        while((ta[j]<tb[i])&&(j<=tanum)) j++;
        if(j>tanum) return 0;
        j++;
    }
    return 1;
}
int main()
{
    freopen("blockade.in","r",stdin);
    freopen("blockade.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d%d",&tmpu,&tmpv,&tmpw);
        Add_Edge(tmpu,tmpv,tmpw);
        Add_Edge(tmpv,tmpu,tmpw);
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++) scanf("%d",&zzz[i]);
    memset(state,0,sizeof(state));
    Dfs(1);
    for(i=1;i<=n;i++) 
        if(fa[i]==1) 
        {
            //totable[i]=++chnum;
            tonode[++chnum]=i;
        }
    for(i=1;i<=m;i++) Add_Edge2(zzz[i],i);
    //for(i=1;i<=n;i++) printf("fa[%d]=%d\n",i,fa[i]);
    l=0; r=(long long)(1000000000)*1000000; mid=(l+r)/2;
    
    if(n<1000)
    {
    
    while(r>l)
    {
        if(Work_old(mid))
            r=mid;
        else
            l=mid+1;
        mid=(l+r)/2;
    }
    if(l==(long long)(1000000000)*1000000)
        printf("-1\n");
    else
        cout<<l<<endl;
        
    }
    else
    {
        while(r>l)
    {
        if(Work_old(mid))
            r=mid;
        else
            l=mid+1;
        mid=(l+r)/2;
    }
    if(l==(long long)(1000000000)*1000000)
        printf("-1\n");
    else
        cout<<l<<endl;
    }
    /*
    if(Work(10)) cout<<1<<endl; else cout<<0<<endl;
    if(Work(7)) cout<<1<<endl; else cout<<0<<endl;
    if(Work(8)) cout<<1<<endl; else cout<<0<<endl;
    if(Work(9)) cout<<1<<endl; else cout<<0<<endl;
    if(Work(10)) cout<<1<<endl; else cout<<0<<endl;
    if(Work(11)) cout<<1<<endl; else cout<<0<<endl;
    */
    fclose(stdin);
    fclose(stdout);
    return 0;
}
