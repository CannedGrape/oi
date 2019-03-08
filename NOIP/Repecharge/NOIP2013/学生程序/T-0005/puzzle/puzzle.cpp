#include <queue>
#include <stdio.h>
#include <cstring>
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define MST(i,a) memset(i,a,sizeof(i))
using namespace std;

const int dx[4] = { 0, 0, 1,-1};
const int dy[4] = { 1,-1, 0, 0};

struct Poi
{
    int x,y;
    Poi Move(int direction)
    {
        Poi k;
        k.x = x + dx[direction];
        k.y = y + dy[direction];
        return k;
    }
    bool operator==(Poi a)
    {
         return a.x == x && a.y == y;
    }
};

int   n,m,q;
bool  Map   [31][31];
bool  Posv  [31][31];
bool  Gone  [31][31];

Poi Empty,Start,End;

int Doonce()
{
    queue<Poi> q;
    Poi a,b;//Temp
    bool done = false;
    bool fl;//flag
    q.push(Empty);
    Gone[Empty.x][Empty.y] = true;
    int step = 0;
    do
    {
        a = q.front();q.pop();
        ++step;
        fl = true;
        FOR(i,1,4)
        {
            b = a.Move(i);
            if (b.x > n || b.y > m || b.x <= 0|| b.y <= 0) continue;
            if (Map[b.x][b.y]) continue;
            if (Gone[b.x][b.y]) continue;
            if (Posv[b.x][b.y]) Posv[b.x][b.y] = false,Posv[a.x][a.y] = true;
            if (a == End && Posv[a.x][a.y]){done = true;break;}
            Gone[b.x][b.y] = true;
            fl = false;
            q.push(b);
        }
        if (done) break;
        //if (fl) break;
    }
    while (!q.empty());
    if (done) return step;
    return -1;
}

int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    int a;//Temp
    FOR(i,1,n)
        FOR(j,1,m)
            scanf("%d",&a),Map[i][j] = (a == 0);
    FOR(i,1,q)
    {
        MST(Posv,0);MST(Gone,0);
        scanf("%d%d%d%d%d%d",&Empty.x,&Empty.y,&Start.x,&Start.y,&End.x,&End.y);
        Posv[Start.x][Start.y] = true;
        printf("%d\n",Doonce());
    }
    return 0;
}
