#include<cstdio>
#include<cstring>
#define MAXP 810010
#define INF ~0U>>1

int N,M,T;
bool map[35][35];
int EX,EY,SX,SY,TX,TY;
int vis[35][35][35][35],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int Q[MAXP][5],h,t,ans=INF;

void bfs()
{
     if(SX==TX && SY==TY) {ans=0; return;}
     if(!map[SX][SY] || !map[TX][TY]) return;
     h=0,t=1;
     vis[SX][SY][EX][EY]=0;
     Q[1][0]=SX; Q[1][1]=SY;
     Q[1][2]=EX; Q[1][3]=EY;
     Q[1][4]=0;
     int cx,cy,bx,by,c,xx,yy;
     while(h!=t)
     {
                h++;
                cx=Q[h][0]; cy=Q[h][1]; bx=Q[h][2]; by=Q[h][3]; c=Q[h][4];
                for(int k=0;k<4;k++)
                {
                        int xx=bx+dx[k],yy=by+dy[k];
                        if(xx<=0 || xx>N || yy<=0 || yy>M || !map[xx][yy]) continue;
                        if(xx==cx && yy==cy && bx==TX && by==TY)
                        {
                                  ans=c+1; return;
                        }
                        if(xx==cx && yy==cy)
                        {
                                  if(vis[bx][by][xx][yy]<0)
                                  {
                                                           vis[bx][by][xx][yy]=c+1;
                                                           Q[++t][0]=bx; Q[t][1]=by; Q[t][2]=xx; Q[t][3]=yy; Q[t][4]=c+1;
                                  }
                        }
                        else
                        {
                            if(vis[cx][cy][xx][yy]<0)
                            {
                                                     vis[cx][cy][xx][yy]=c+1;
                                                     Q[++t][0]=cx; Q[t][1]=cy; Q[t][2]=xx; Q[t][3]=yy; Q[t][4]=c+1;
                            }
                        }
                }
     }
}

int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&N,&M,&T);
    int x;
    for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++)
            {
                    scanf("%d",&x);
                    map[i][j]=(x&1);
            }
    while(T--)
    {
              memset(vis,-1,sizeof(vis));
              ans=INF;
              scanf("%d %d %d %d %d %d",&EX,&EY,&SX,&SY,&TX,&TY);
              bfs();
              if(ans^INF) printf("%d\n",ans);
              else printf("-1\n");
    }
    return 0;
}
