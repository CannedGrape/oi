#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define Rep(i,n) for(int i=0;i<n;i++)
#define RepD(i,n) for(int i=n-1;i>=0;i--)
#define For2k(i,k,n) for(int i=k;i<=n;i++)
#define For2kD(i,k,n) for(int i=n;i>=k;i--)
#define INF (2139062143)
#define MAXN (30+10)
#define MAXM (30+10)
#define MAXQ (500+10)
#define MAXq (5000000+10)
typedef long long ll;
int n,m,T;
bool f[MAXN][MAXN][MAXN][MAXN];
int b[MAXN][MAXN]={{0}},q[MAXq][5];
int dire[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void go(int &ex,int &ey,int &sx,int &sy,int i)
{
     ex+=dire[i][0],ey+=dire[i][1];
     if (sx==ex&&sy==ey) sx-=dire[i][0],sy-=dire[i][1];
}
int bfs(int tx,int ty)
{
     memset(f,0,sizeof(f));    
     int head=1,tail=1;
     while(head<=tail)
     {
         Rep(i,4)             
            if (b[q[head][0]+dire[i][0]][q[head][1]+dire[i][1]])
            {
                int ex=q[head][0],ey=q[head][1],sx=q[head][2],sy=q[head][3];     
                go(ex,ey,sx,sy,i);                                           
                if (f[ex][sy][sx][sy]==0)
                {
                    f[ex][sy][sx][sy]=1;
                    if (sx==tx&&sy==ty) return q[head][4]+1;
                    if (tail<5000000) 
                    {
                        ++tail;
                        q[tail][0]=ex,q[tail][1]=ey,q[tail][2]=sx,q[tail][3]=sy,q[tail][4]=q[head][4]+1;
                    }else return -1;                                                     
                }
            }
         
         head++;
     }
     return -1;
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&n,&m,&T);
    For(i,n) For(j,m) scanf("%d",&b[i][j]);
    For(i,T)
    {
       int tx,ty;
       scanf("%d%d%d%d%d%d",&q[1][0],&q[1][1],&q[1][2],&q[1][3],&tx,&ty);q[1][4]=0;
       if (q[1][2]==tx&&q[1][3]==ty) puts("0");
       else printf("%d\n",bfs(tx,ty));
    }
    
    return 0;
}
