#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define P 35
#define H 1313131
#define C 13311

using namespace std;

int map[P][P],n,m,q;
int que[10010][P][P],head,tail,ans = -1,deep[10010];
int sx[10010],sy[10010],tx[10010],ty[10010],ex[P],ey[P];
long long h;
int hash[H];
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,-1,1,0,0};


int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int i,j,nx,ny,k;
    scanf("%d%d%d",&n,&m,&q);
    for(i = 1;i <= n;i++)
          for(j = 1;j <= m;j++) scanf("%d",&que[1][i][j]);
    while(q)
    { 
            ans = -1;
            memset(hash,0,sizeof(hash));
            memset(deep,0,sizeof(deep));
            scanf("%d%d%d%d%d%d",&ex[1],&ey[1],&sx[1],&sy[1],&tx[1],&ty[1]);
            head = tail = 1;
            if(que[1][ex[1]][ey[1]] != 0) que[1][ex[1]][ey[1]] = 3;
            if(que[1][sx[1]][sy[1]] != 0) que[1][sx[1]][sy[1]] = 2;
            h = 0;
            for(i = 1;i <= n;i++)
                  for(j = 1;j <= m;j++) h = ((h * C) + que[1][i][j] + 1) % H;
            hash[h] = 1;
            while(head <= tail)
            {
                       for(i = 1;i <= 4;i++)
                       {
                             nx = ex[head] + dx[i];
                             ny = ey[head] + dy[i];
                             if(que[head][nx][ny] != 0)
                             {
                                 if(nx == sx[head] && ny == sy[head] && ex[head] == tx[head] && ey[head] == ty[head])
                                 {
                                       ans = deep[head] + 1;
                                       head = tail;
                                       break;
                                 }
                                 else
                                 {
                                     ++tail;
                                     for(j = 1;j <= n;j++)
                                           for(k = 1;k <= m;k++) que[tail][j][k] = que[head][j][k];
                                     swap(que[tail][nx][ny],que[tail][ex[head]][ey[head]]);
                                     ex[tail] = nx;
                                     ey[tail] = ny;
                                     if(sx[head] == nx && sy[head] == ny)
                                     {
                                        sx[tail] = ex[head];sy[tail] = ey[head];
                                     }
                                     else 
                                     {
                                        sx[tail] = sx[head];sy[tail] = sy[head];  
                                     }
                                     tx[tail] = tx[head];ty[tail] = ty[head];  
                                     h = 0;
                                     deep[tail] = deep[head] + 1;
                                     for(j = 1;j <= n;j++)
                                           for(k = 1;k <= m;k++) h = ((h * C) + que[tail][j][k] + 1) % H;
                                     if(hash[h]) --tail;
                                     else hash[h] = 1;
                                 }
                             }
                       }
                       ++head;
                    //   printf("%d\n",tail);
                       if(tail > 10000) break;
            }
            if(sx[1] == tx[1] && sy[1] == ty[1] && que[1][sx[1]][sy[1]] != 0) ans = 0;
            printf("%d\n",ans);
            --q;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
