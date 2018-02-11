#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int n,m;

bool a[1001][1001]={1};
bool b[1001];
int c[1001];
bool k[1001];
int h[2001];
int ans;
bool f;

void check(int x);
void bfs(int st);

int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    memset(a,1,sizeof(a));
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; ++i)
    {
            int x;
            scanf("%d",&x);
            for(int j=1; j<=x; ++j) scanf("%d",&c[j]),b[c[j]]=1,k[c[j]]=1;
            check(x);
    }
    
//    for(int i=1; i<=n; ++i)
//    {
//            for(int j=1; j<=n; ++j)
//            {
//                    cout<<a[i][j]<<" ";
//                    }
//            cout<<endl;        
//            }
    
    for(int i=1; i<=n; ++i) bfs(i);
    if(f) ++ans;
    printf("%d",ans);
    system("pause");
}

void check(int x)
{
     for(int i=1; i<x; ++i)
     {
             b[c[i]]=0;
             for(int j=c[i]+1; j<=n; ++j) 
                     a[c[i]][j]=(a[c[i]][j] && b[j]);
     }
     b[x]=0;
}

void bfs(int st)
{
     bool flag=1;
     int t=0;
     int w=1;
     b[st]=1;
     h[1]=st;
     while(t<w)
     {
               ++t;
               for(int i=h[t]; i<=n; ++i)
               {
                       if(a[h[t]][i] && k[i])
                       {
                                     flag=(flag && 1);
                       if(!b[i])
                       {
                                flag=0;
                                     ++w;
                                     h[w]=i;
                                     b[i]=1;                           
                       }
                       }
               }
     }
//     memset(b,0,sizeof(b));
     if(!flag && t>1) ++ans;
     if(flag && t==1) f=1; 
}
