#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=10001,MAXM=50001,MAXQ=30001;
const int MAXS=(50001*3+30001*2)*10;
struct EDGE
{
  int x,y,l;
} e[MAXM];
char buf[MAXS];
int n,m,q,pp;
int fa[MAXN],ans[MAXQ];
int coun,first[MAXN],next[MAXQ],last[MAXQ],tt[MAXQ],pis[MAXQ];

void file_open()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
}

void file_close()
{
    fclose(stdin); fclose(stdout);
}

int analyse()
{
    while (buf[pp]>'9' || buf[pp]<'0') pp++;
    int tmp=0;
    while (buf[pp]>='0' && buf[pp]<='9')
    {
      tmp=tmp*10+buf[pp]-'0';
      pp++;
    }
    return tmp;
}

int cmp(const EDGE &x,const EDGE &y)
{
    return x.l>y.l;
}

int init()
{
    int len=fread(buf,1,MAXS,stdin);
    buf[len]='\0';
    n=analyse();
    m=analyse();
    for (int i=1;i<=m;i++)
    {
      e[i].x=analyse();
      e[i].y=analyse();
      e[i].l=analyse();
    }
    sort(e+1,e+m+1,cmp);
    return 0;
}

int find_father(int x)
{
    if (fa[x]!=x) fa[x]=find_father(fa[x]);
    return fa[x];
}

void add_query(int x,int y,int z)
{
    coun++;
    pis[coun]=z;
    tt[coun]=y;
    next[coun]=first[x];
    last[first[x]]=coun;
    first[x]=coun;
}

void hebing(int x,int y)
{
    fa[x]=y;
    int k=first[y];
    if (k==0) {first[y]=first[x]; return ;}
    while (next[k]!=0) k=next[k];
    next[k]=first[x];
    last[first[x]]=k;
}

int work()
{
    int x,y;
    q=analyse();
    for (int i=1;i<=q;i++)
    {
      x=analyse();
      y=analyse();
      add_query(x,y,i);
    }
    
    for (int i=1;i<=n;i++)
      fa[i]=i;
    memset(ans,-1,sizeof(ans));
    for (int i=1;i<=m;i++)
    {
      int f1=find_father(e[i].x),f2=find_father(e[i].y);
      if (f1==f2) continue;
      for (int k=first[f1];k!=0;k=next[k])
        if (find_father(tt[k])==f2)
        {
          if (k==first[f1]) first[f1]=next[k];
          else
          {
            next[last[k]]=next[k];
            last[next[k]]=last[k];
          }
          ans[pis[k]]=e[i].l;
        }
          
      for (int k=first[f2];k!=0;k=next[k])
        if (find_father(tt[k])==f1)
        {
          if (k==first[f2]) first[f2]=next[k];
          else
          {
            next[last[k]]=next[k];
            last[next[k]]=last[k];
          }
          ans[pis[k]]=e[i].l;
        }
      
      hebing(f1,f2);
    }
    
    for (int i=1;i<=q;i++)
      printf("%d\n",ans[i]);
    
    return 0;
}

int main()
{
    file_open();
    init();
    work();
    //system("pause");
    file_close();
    return 0;
}
