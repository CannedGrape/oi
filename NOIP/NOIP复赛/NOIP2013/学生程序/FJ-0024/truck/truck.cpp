#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
       int a,b,v;
}lu[50010];
int n,m,q;
int father[10010];
int sz,to[100010],pre[100010],vv[100010],last[10010],deep[10010];
int fa[10010][15],xiao[10010][15];
int getfa(int x)
{
    if(father[x]==0)  return x;
    else return father[x]=getfa(father[x]);
}
inline bool comp(sth a,sth b)
{
       return a.v>b.v;
}
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;vv[sz]=c;pre[sz]=last[a];last[a]=sz;
}
bool mark[10010];
void dfs(int x,int lastv)
{
     mark[x]=1;xiao[x][0]=lastv;
     int i=last[x];
     while(i>0)
     {
          if(!mark[to[i]])
          {
              fa[to[i]][0]=x;
              deep[to[i]]=deep[x]+1;
              dfs(to[i],vv[i]);
          }
          i=pre[i];
     }
}
int LCA(int a,int b)
{
    if(deep[a]<deep[b])  {int t=a;a=b;b=t;}
    int i,c=deep[a]-deep[b];
    for(i=14;i>=0;i--)
    if(c>=(1<<i))
    {
        c-=(1<<i);a=fa[a][i];
    }
    for(i=14;i>=0;i--)
    {
       if((deep[a]>(1<<i)) && fa[a][i]!=fa[b][i])
       {
            a=fa[a][i];b=fa[b][i];
       }
    }
    if(a==b)  return a;
    else return fa[a][0];
}
void solve(int a,int b)
{
     int x=getfa(a),y=getfa(b);
     if(x!=y)  {printf("-1\n");return;}
     int c=LCA(a,b);
     int ans=10000000;
     int k,i;
     k=deep[a]-deep[c]-1;
     if(k==0) {ans=min(ans,xiao[a][0]);}
     else 
     if(k!=-1)
     {
           for(i=14;i>=0;i--)
           {
              if(k>=(1<<i))
              {
                 k-=(1<<i);
                 ans=min(ans,xiao[a][i]);
                 a=fa[a][i];
              }
           }
     ans=min(xiao[a][0],ans);
     }
     k=deep[b]-deep[c]-1;
     if(k==0) {ans=min(ans,xiao[b][0]);}
     else 
     if(k!=-1)
     {
           for(i=14;i>=0;i--)
           {
              if(k>=(1<<i))
              {
                 k-=(1<<i);
                 ans=min(ans,xiao[b][i]);
                 b=fa[b][i];
              }
           }
     ans=min(xiao[b][0],ans);
     }
     printf("%d\n",ans);
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    sz=0;
    memset(last,0,sizeof(last));
    memset(mark,0,sizeof(mark));
    memset(fa,0,sizeof(fa));
    memset(father,0,sizeof(father));
    memset(deep,0,sizeof(deep));
    int a,b,c,i,j,now=0,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)  scanf("%d%d%d",&lu[i].a,&lu[i].b,&lu[i].v);
    sort(lu+1,lu+1+m,comp);
    for(i=1;i<=m;i++)
    {
       x=getfa(lu[i].a);
       y=getfa(lu[i].b);
       if(x!=y)
       {
           father[x]=y;
           Ins(lu[i].a,lu[i].b,lu[i].v);Ins(lu[i].b,lu[i].a,lu[i].v);
           now++;
           if(now==n-1) break;
       }
    }
    memset(xiao,127,sizeof(xiao));
    for(i=1;i<=n;i++)
    {
        x=getfa(i);
        if(!mark[x]) {deep[x]=1;dfs(x,1000000);}
    }
    for(i=1;i<=14;i++)
    for(j=1;j<=n;j++) 
    {fa[j][i]=fa[fa[j][i-1]][i-1];xiao[j][i]=min(xiao[j][i-1],xiao[fa[j][i-1]][i-1]);}  
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {                   
       scanf("%d%d",&a,&b);
       solve(a,b);
    }
    //system("pause");
    return 0;
}
/*
4 3
1 2 4
2 3 3
3 1 1
3
1 3
1 4 
1 3
*/
