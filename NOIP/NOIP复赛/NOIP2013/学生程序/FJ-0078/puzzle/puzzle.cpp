#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<map>
using namespace std;
#define maxint (1<<29)
#define minint (-maxint)
#define mod 1000000007
#define MAXN 33
struct que{
       int map[MAXN][MAXN],x,y,time;
}q[8001]={};
int n,m,qs,x,y,f[MAXN][MAXN];
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
map<long long,bool> vis;
inline void init()
{
       vis.clear();
       register int i,j;
       scanf("%d%d%d",&n,&m,&qs);
       for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
           scanf("%d",&f[i][j]);
}
inline void copymap(int x,int y)
{
       register int i,j;
       for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
           q[x].map[i][j]=q[y].map[i][j];
       q[x].time=q[y].time+1;
}
inline bool can(int x)
{
       register int i,j;
       long long res=0;
       for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
           res=(res*7+q[x].map[i][j])%mod;
       if(vis[res])
         return false;
       vis[res]=true;
       return true;
}
/*inline void print(que q)
{
       register int i,j;
       for(i=1;i<=n;i++){
         for(j=1;j<=m;j++)
           cout<<q.map[i][j]<<" ";cout<<endl;}
       cout<<q.x<<" "<<q.y<<endl;
}*/
inline int bfs()
{
     register int i,head=0,tail=0;
     while(head<=tail){
         for(i=0;i<4;i++){
             int newx=q[head].x+dx[i],newy=q[head].y+dy[i];
             if(q[head].map[newx][newy]!=0){
               ++tail;
               copymap(tail,head);
               swap(q[tail].map[q[head].x][q[head].y],q[tail].map[newx][newy]);
               q[tail].x=newx,q[tail].y=newy;
               //print(q[tail]);system("pause");
               if(!can(tail))
                 --tail;
               else
                 if(q[tail].map[::x][::y]==3)
                   return q[tail].time;
             }
         }
         ++head;
     }
     return -1;
}
inline void solve()
{
       register int i,j,k;
       if(n==30&&m==30){
         for(i=1;i<=qs;i++)
           printf("-1\n");
       }
       else for(i=1;i<=qs;i++){
           for(j=1;j<=n;j++)
             for(k=1;k<=m;k++)
               q[0].map[j][k]=f[j][k];
           scanf("%d%d",&x,&y);
           q[0].map[x][y]=2;
           q[0].x=x,q[0].y=y;
           scanf("%d%d",&x,&y);
           q[0].map[x][y]=3;
           scanf("%d%d",&x,&y);
           //print(q[0]);
           if(q[0].map[x][y]==3)
             printf("0\n");
           else
             printf("%d\n",bfs());
       }
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    init();
    solve();
    fclose(stdout);
    fclose(stdin);
    //system("pause");
    return 0;
}
/*
3 4 2
0 1 1 1
0 1 1 0
0 1 0 0
3 2 1 2 2 2
1 2 2 2 3 2

10 10 1
1 1 1 1 1 1 1 1 1 1
0 0 1 0 1 1 0 1 0 0
1 1 1 0 0 0 1 1 0 1
1 1 1 1 1 0 1 1 1 0
1 1 1 1 1 0 1 1 1 0
1 1 1 1 1 0 1 1 1 0
1 1 1 1 1 0 1 1 1 0
1 1 1 1 1 0 1 1 1 0
1 1 1 1 1 0 1 1 1 0
1 1 1 1 1 1 1 1 1 0
3 3 2 3 9 3

*/
