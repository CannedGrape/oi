#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,q;
int mx[50005]={},my[50005]={},mv[50005]={};
int qu[30005][3]={},bh[50005]={},fa[10005]={},dis[10005]={};
int be[10005]={},to[10005]={},v[10005]={},la[10005]={};
queue<int> l;
void input()
{
     int k,x,y,z;
     scanf("%d %d",&n,&m);
     k=0;
     for(int i=1;i<=m;++i)
       {scanf("%d %d %d",&x,&y,&z);
        bh[i]=i;
        mx[i]=x;
        my[i]=y;
        mv[i]=z;
       }
     scanf("%d",&q);
     for(int i=1;i<=q;++i)
       {scanf("%d %d",&qu[i][1],&qu[i][2]);
        }
}
bool cmp(int x,int y)
{
     if( mv[x]<mv[y] ) return false;
     else return true;
}
int getf(int x)
{
    if(fa[x]==x) return x;
    else
      {fa[x]=getf(fa[x]);
       return fa[x];
      }
}
void bigtree()
{
     int k,p,fx,fy,i,x,y;
     sort(bh+1,bh+m+1,cmp);
     for(int i=1;i<=n;++i)
       fa[i]=i;
     k=0;
     i=0;
     p=0;
     do
       {
        ++i;
        x=mx[ bh[i] ];
        y=my[ bh[i] ];
        fx=getf(x);
        fy=getf(y);
        if(fx!=fy)
          {fa[  fa[x]  ]=fa[y];
           ++k;
           
           ++p;
           to[p]=y;
           v[p]=mv[ bh[i] ];
           la[p]=be[x];
           be[x]=p;
           ++p;
           to[p]=x;
           v[p]=mv[ bh[i] ];
           la[p]=be[y];
           be[y]=p;
           
           
           
          }
       }while( i<m && k<n );
}
void work()
{
     int x,y,he,t,fx,fy;
     bigtree();
     for(int i=1;i<=q;++i)
       {x=qu[i][1];  y=qu[i][2];
        fx=getf(x);
        fy=getf(y);
        if( fx!=fy )
          printf("-1\n");
        else
          {
           int o;
           o=true;
           l.push(x);
           dis[x]=2000000;
           while( !l.empty() && o )
             {t=l.front();
              he=be[t];
              if(he!=0)
               {do
                 {
                  dis[ to[he] ]=min( dis[t],v[he] );
                  l.push(to[he]);
                  if( to[he]==y )
                    {o=false;
                     break;
                    }
                  he=la[he];
                 }while(he!=0);
               }
              l.pop();
             }
           printf("%d\n",dis[y]);
           while(!l.empty())
             l.pop();
          }
       }
     
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    input();
    work();
    fclose(stdin);
    fclose(stdout);
return 0;
}
