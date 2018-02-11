/********************************
    noip2013 - Day2 - T3 puzzle
    Author : RsEnts
    Qiu AC~
    Bu Neng Dui Pai..>_<
********************************/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 35

using namespace std;

struct State {
    int x, y;
}Que[MaxN * MaxN * 10];

struct NowQueue {
    int x, y, dir;
}nowQ[2000010];

int N, M, Q, mapp[MaxN][MaxN], Dist[MaxN][MaxN][4][4], Qhead, Qtail, Dis1[MaxN][MaxN], Dis2[MaxN][MaxN][4], Ans;
bool vis[MaxN][MaxN], vis1[MaxN][MaxN][4];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int EX, EY, SX, SY, TX, TY;

bool CanArrive(int xx, int yy) {
    if(xx <= 0 || xx > N || yy <= 0 || yy > M) return false;
    if(mapp[xx][yy] == 1) return false;
    return true;
}

int Min(int a, int b) {
    return a < b ? a : b;
}

void Init() {
    int i, j;
    scanf("%d%d%d", &N, &M, &Q);
    for(i = 1; i <= N; ++i)
        for(j = 1; j <= M; ++j) {
            scanf("%d", &mapp[i][j]);
            mapp[i][j] ^= 1;
        }
}

void Search1(int s1, int t1) {
    int j;
    memset(Dis1, 63, sizeof(Dis1));
    memset(vis, 0, sizeof(vis));
    Dis1[s1][t1] = 0;
    vis[s1][t1] = 1;
    Que[Qhead = Qtail = 1].x = s1; Que[1].y = t1;
    for( ; Qhead <= Qtail; ++Qhead) {
        for(j = 0; j < 4; ++j) {
            int tx = Que[Qhead].x + dx[j], ty = Que[Qhead].y + dy[j];
            if(!CanArrive(tx,ty))
                continue;
            if(!vis[tx][ty]) {
                Dis1[tx][ty] = Dis1[Que[Qhead].x][Que[Qhead].y] + 1;
                vis[tx][ty] = 1;
                ++Qtail; Que[Qtail].x = tx; Que[Qtail].y = ty;
            }
        }
    }
}

void Search(int s1, int t1) {
    int i, j;
    mapp[s1][t1] = 1;
    for(i = 0; i < 4; ++i)
        if(CanArrive(s1 + dx[i], t1 + dy[i])) {
            Search1(s1 + dx[i], t1 + dy[i]);
            for(j = 0; j < 4; ++j)
                if(CanArrive(s1 + dx[j], t1 + dy[j]))
                    Dist[s1][t1][i][j] = Dis1[s1 + dx[j]][t1 + dy[j]];
        }
    mapp[s1][t1] = 0;
}

void PreWork_MinDist() {
    int i, j;
    memset(Dist, 63, sizeof(Dist));
    for(i = 1; i <= N; ++i)
        for(j = 1; j <= M; ++j)
            if(mapp[i][j] == 0)
                Search(i, j);
}

void Spfa() {
    int i;
    Ans = 1000000000;
    mapp[SX][SY] = 1;
    Search1(EX, EY);
    Qhead = 1; Qtail = 0;
    memset(Dis2, 63, sizeof(Dis2));
    memset(vis1, 0, sizeof(vis1));
    for(i = 0; i < 4; ++i)
        if(CanArrive(SX + dx[i], SY + dy[i])) {
            if(Dis1[SX + dx[i]][SY + dy[i]] <= 10000000) {
                ++Qtail;
                nowQ[Qtail].x = SX; nowQ[Qtail].y = SY; nowQ[Qtail].dir = i; Dis2[SX][SY][i] = Dis1[SX + dx[i]][SY + dy[i]];
                vis1[SX][SY][i] = 1;
            }
        }
    mapp[SX][SY] = 0;
    for( ; Qhead <= Qtail; ++Qhead) {
        int nx = nowQ[Qhead].x, ny = nowQ[Qhead].y, nd = nowQ[Qhead].dir;
        if(Dis2[nx + dx[nd]][ny + dy[nd]][(nd + 2) & 3] > Dis2[nx][ny][nd] + 1) {
            Dis2[nx + dx[nd]][ny + dy[nd]][(nd + 2) & 3] = Dis2[nx][ny][nd] + 1;
            if(!vis1[nx + dx[nd]][ny + dy[nd]][(nd + 2) & 3]) {
                vis1[nx + dx[nd]][ny + dy[nd]][(nd + 2) & 3] = 1;
                ++Qtail; nowQ[Qtail].x = nx + dx[nd]; nowQ[Qtail].y = ny + dy[nd]; nowQ[Qtail].dir = ((nd + 2) & 3);
            }
        }
        for(i = 0; i < 4; ++i)
            if(CanArrive(SX + dx[i], SY + dy[i])) {
                int tx = nx, ty = ny; // nd -> i
                if(Dis2[nx][ny][nd] + Dist[nx][ny][nd][i] < Dis2[tx][ty][i]) {
                    Dis2[tx][ty][i] = Dis2[nx][ny][nd] + Dist[nx][ny][nd][i];
                    if(!vis1[tx][ty][i]) {
                        vis1[tx][ty][i] = 1;
                        ++Qtail; nowQ[Qtail].x = tx; nowQ[Qtail].y = ty; nowQ[Qtail].dir = i;
                    }
                }
            }
        vis1[nx][ny][nd] = 0;
    }
    for(i = 0; i < 4; ++i)
        Ans = Min(Ans, Dis2[TX][TY][i]);
    if(Ans >= 50000000)
        puts("-1");
    else
        printf("%d\n", Ans);
}

void Solve() {
    int i;
    for(i = 1; i <= Q; ++i) {
        cin >> EX >> EY >> SX >> SY >> TX >> TY;
        Spfa();
    }
}

int main() {
    freopen("puzzle.in", "r", stdin);
    freopen("puzzle.out", "w", stdout);
    Init();
    PreWork_MinDist();
    Solve();
    return 0;
}
