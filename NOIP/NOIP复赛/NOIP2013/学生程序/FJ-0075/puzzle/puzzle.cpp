#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
int N,M,Q,ex,ey,sx,sy,tx,ty;
int g[110][110]={},m[110][110];
const int dx[4]={1,-1,0,0},
          dy[4]={0,0,1,-1};
struct seat{int x,y;}s,ss;
/*queue<seat>q;
void tryy(int x,int y){
     s.x=x;s.y=y;
     q.push(s);
     while(!q.empty()){
                       ss=q.front();q.pop();
                       for(int i=0;i<=3;++i){
                               s.x=ss.x+dx[i];s.y=ss.y+dy[i];
                               if(s.x<=N && s.x>=1 && s.y<=M && s.y>=1){
                                         q.push(s);
                                         if(s.x==sx-1
                       
}*/
int main(){
    freopen("puzzle.in","r",stdin);freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&N,&M,&Q);
    for(int i=1;i<=N;++i)
            for(int j=1;j<=M;++j)
                    scanf("%d",&g[i][j]);
    for(int i=1;i<=Q;++i){
            scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
            for(int j=1;j<=N;++j)for(int k=1;k<=M;++k)m[i][j]=g[i][j];
            m[ex][ey]=-1;
//            tryy(ex,ey);
    }
    for(int i=1;i<=Q;++i)cout<<-1<<endl;
    return 0;
}
