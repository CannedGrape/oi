#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
const int MAXN=35;
const int MAXQ=505;
const int dx[4]={+1,-1,0,0};
const int dy[4]={0,0,+1,-1}; //0~3
int n,m,q;
bool ditu[MAXN][MAXN];
int EX[MAXQ], EY[MAXQ], SX[MAXQ], SY[MAXQ], TX[MAXQ], TY[MAXQ];

typedef struct 
{
    int ex,ey,gx,gy, step;
} TState;

const int QSIZE=900000;
TState Que[QSIZE+5];
bool vst[32][32][32][32];
int bfs(const int qid)
{
    if (SX[qid]==TX[qid] && SY[qid]==TY[qid])
        return 0;
    int QHead, QTail, nowex, nowey, nex,ney, ngx,ngy;
    QHead=0;
    QTail=0;
    memset(vst,false,sizeof(vst));
    ++QTail;
    Que[QTail].ex=EX[qid];
    Que[QTail].ey=EY[qid];
    Que[QTail].gx=SX[qid];
    Que[QTail].gy=SY[qid];
    Que[QTail].step=0;
    vst[EX[qid]][EY[qid]][SX[qid]][SY[qid]]=true;
    while (QHead<QTail)
    {
        ++QHead;
        nowex=Que[QHead].ex;
        nowey=Que[QHead].ey;
        for (int i=0; i<=3; ++i)
        {
            nex=nowex+dx[i];
            ney=nowey+dy[i];
            if ((nex>0 && nex<=n && ney>0 && ney<=m) && ditu[nex][ney])
            {
                if (nex==Que[QHead].gx && ney==Que[QHead].gy)
                {
                    ngx=nowex;
                    ngy=nowey;
                }
                else
                {
                    ngx=Que[QHead].gx;
                    ngy=Que[QHead].gy;
                }
                if (!vst[nex][ney][ngx][ngy])
                {
                    vst[nex][ney][ngx][ngy]=true;
                    ++QTail;
                    Que[QTail].ex=nex;
                    Que[QTail].ey=ney;
                    Que[QTail].gx=ngx;
                    Que[QTail].gy=ngy;
                    Que[QTail].step=Que[QHead].step+1;
                    if (ngx==TX[qid] && ngy==TY[qid])
                    {
                        return Que[QTail].step;
                    }
                }
            }
        }
    }
    return -1;
}

void Input()
{
    int tmp;
    scanf("%d%d%d", &n, &m, &q);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            scanf("%d", &tmp);
            if (tmp==1)
                ditu[i][j]=true;
        }
    for (int i=1; i<=q; ++i)
    {
        scanf("%d%d%d%d%d%d", &EX[i], &EY[i], &SX[i], &SY[i], &TX[i], &TY[i]);
    }
}

int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    Input();
    for (int i=1; i<=q; ++i)
        printf("%d\n",bfs(i));
    return 0;
}
