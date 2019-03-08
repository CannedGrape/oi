#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<math.h>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repk(i,a,b) rep(i,a,(b)-1)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)
#define ifn(x) if(!x)
typedef long long ll;
const ll llinf=0x7fffffffffffffffll;
const int inf=0x3fffffff,upinf=0x7fffffff;
const double dinf=1e20,eps=1e-12;

int N,M,Q;
bool chess[30][30];
struct Sit
{
        int ex,ey,sx,sy,tx,ty,step;
}q[500]; 
bool rec[20000000];

bool Hash(Sit x)
{
     int h=0;
     h+=(x.ex+1)*1;
     h+=(x.ey+1)*31;
     h+=(x.sx+1)*961;
     h+=(x.sy+1)*29791;
     h+=(x.tx+1)*923521;
     h+=(x.ty+1)*28629151;
     h=abs(h)%20000000;
     if(rec[h])
               {
               rec[h]=0;
               return 1;
               }
     else return 0;
}
void Init()
{
     memset(rec,1,sizeof(rec));
}
int Bfs(Sit ques)
{
     queue<Sit>que;
     que.push(ques);
     Sit i,j;
     while(!que.empty())
                        {
                        i=que.front();
                        que.pop();
                        if(i.sx == i.tx && i.sy == i.ty) return i.step;
                        
                        if(i.ex+1<N && chess[i.ex+1][i.ey])
                                    {
                                     j=i;
                                     j.ex++;
                                     if(j.ex == j.sx && j.ey == j.sy) j.sx--;
                                     j.step++;
                                     if(Hash(j)) que.push(j);
                                     }
                        if(0<=i.ex-1 && chess[i.ex-1][i.ey])
                                    {
                                     j=i;
                                     j.ex--;
                                     if(j.ex == j.sx && j.ey == j.sy) j.sx++;
                                     j.step++;
                                     if(Hash(j)) que.push(j);
                                     }
                        if(i.ey+1<M && chess[i.ex][i.ey+1])
                                    {
                                     j=i;
                                     j.ey++;
                                     if(j.ex == j.sx && j.ey == j.sy) j.sy--;
                                     j.step++;
                                     if(Hash(j)) que.push(j);
                                     }
                        if(0<=i.ey-1 && chess[i.ex][i.ey-1])
                                    {
                                     j=i;
                                     j.ey--;
                                     if(j.ex == j.sx && j.ey == j.sy) j.sy++;
                                     j.step++;
                                     if(Hash(j)) que.push(j);
                                     }
                        }
     return -1;
}                                  
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&N,&M,&Q);
    int t; repk(i,0,N) repk(j,0,M) scanf("%d",&t),chess[i][j]=t;
    repk(i,0,Q) scanf("%d%d%d%d%d%d",&q[i].ex,&q[i].ey,&q[i].sx,&q[i].sy,&q[i].tx,&q[i].ty),q[i].ex--,q[i].ey--,q[i].sx--,q[i].sy--,q[i].tx--,q[i].ty--,q[i].step=0;
    repk(i,0,Q) 
                {
                Init();
                printf("%d\n",Bfs(q[i]));
                }
    fclose(stdin); fclose(stdout);
    return 0;
}
                
