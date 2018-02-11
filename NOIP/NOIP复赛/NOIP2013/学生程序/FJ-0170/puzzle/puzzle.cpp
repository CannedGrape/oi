#include <cstdio>
#include <algorithm>

using std::min;

const int maxS=30;

int N,M,Q;
int a[maxS+2][maxS+2];
int p[maxS+1][maxS+1][6];

struct Pair
{
    int r,c;
};
Pair operator+(Pair a, Pair b)
{
    Pair r;
    r.r=a.r+b.r;
    r.c=a.c+b.c;
    return r;
}
inline bool operator==(const Pair a, const Pair b)
{
    return a.r==b.r && a.c==b.c;
}

Pair up,down,left,right;
Pair pms[6],pmt[6];
Pair m4[4];
int trans[4][4];

Pair SPtarget;
const int Infi=maxS*100;
bool SP_dis[maxS+1][maxS+1];

int SP(Pair p)
{
    int r=p.r,c=p.c;
    if(a[r][c]==0)  return Infi;
    if(p==SPtarget)   return 0;
    if(SP_dis[r][c]==Infi+1)
    {
        int ret = Infi;

        for(int i=0;i<4;i++)
            ret = min(ret, SP(p+m4[i])+1 );

        SP_dis[r][c]=ret;
    }
    return SP_dis[r][c];
}

// -1 if impossible
int sp(Pair s, Pair t)
{
    if(a[t.r][t.c]==0)
        return -1;
    for(int i=1;i<=maxS;i++)
        for(int j=1;j<=maxS;j++)
            SP_dis[i][j]=Infi+1;
    SPtarget = t;
    int tmp=SP(s);
    if(tmp==Infi)
        return -1;
    return tmp;
}

Pair FAtarget;
int FAmem[4][maxS+1][maxS+1];
bool FAvisited[4][maxS+1][maxS+1];

int FAs(int e, Pair s)
{
    int r=s.r,c=s.c;
    if(a[r][c]==0)
        return Infi;
    if(FAvisited[e][r][c])
        return Infi;
    if(s==FAtarget)
        return 0;
    FAvisited[e][r][c]=true;
    if(FAmem[e][r][c]==Infi+1)
    {
        int ret = Infi;

        // fprintf(stderr,"124 %d %d %d\n",e,r,c);
        for(int dir=0;dir<4;dir++)
        {
            if(dir==e) continue;
            int pp=p[r][c][trans[e][dir]];
            if(pp!=-1)
                ret = min(ret, pp+1+FAs(dir^1,s+m4[dir]));
        }
        // fprintf(stderr,"120 %d %d %d\n",e,r,c);

        FAmem[e][r][c]=ret;
    }
    return FAmem[e][r][c];
}

int find_ans(Pair e, Pair s)
{
    int r=s.r,c=s.c;
    if(a[r][c]==0)
        return -1;
    int ans=Infi;
    for(int i=0;i<4;i++)
    {
        a[r][c]=0;
        int ret=sp(e,s+m4[i]);
        a[r][c]=1;
        if(ret!=-1)
        {
            for(int dir=0;dir<4;dir++)
                for(int xx=1;xx<=maxS;xx++)
                    for(int yy=1;yy<=maxS;yy++)
                    {
                        FAmem[dir][xx][yy]=Infi+1;
                        FAvisited[dir][xx][yy]=false;
                    }
            int rr=FAs(i,s);
            if(rr!=-1)
                ans=min(ans, ret+rr);
        }
    }
    if(ans==Infi)
        return -1;
    else return ans;
}

void work()
{
    up.r=-1;
    down.r=1;
    up.c=down.c=0;
    left.c=-1;
    right.c=1;
    left.r=right.r=0;
    m4[0] = up; m4[1] = down; m4[2]=left; m4[3]=right;
    pms[0] = up; pmt[0] = down;
    pms[1] = up; pmt[1] = left;
    pms[2] = up; pmt[2] = right;
    pms[3] = left; pmt[3] = right;
    pms[4] = left; pmt[4] = down;
    pms[5] = right; pmt[5] = down;

    trans[0][1] = trans[1][0] = 0;
    trans[0][2] = trans[2][0] = 1;
    trans[0][3] = trans[3][0] = 2;
    trans[2][3] = trans[3][2] = 3;
    trans[2][1] = trans[1][2] = 4;
    trans[3][1] = trans[1][3] = 5;

    scanf("%d%d%d",&N,&M,&Q);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=N;i++)
        a[i][0]=a[i][M+1]=0;
    for(int j=1;j<=M;j++)
        a[0][j]=a[N+1][j]=0;

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(a[i][j]==1)
            {
                a[i][j]=0;
                Pair cur;
                cur.r=i; cur.c=j;
                for(int dir=0;dir<6;dir++)
                    p[i][j][dir] = sp(cur+pms[dir],cur+pmt[dir]);
                a[i][j]=1;
            }

    while(Q--)
    {
        Pair s,t,e;
        scanf("%d%d",&e.r,&e.c);
        scanf("%d%d",&s.r,&s.c);
        scanf("%d%d",&t.r,&t.c);
        FAtarget=t;
        int r=find_ans(e,s);
        //if(r==-1)
        //    printf("-1\n");
        printf("%d\n",r);
    }
}

int main()
{
    freopen("puzzle.in" ,"r",stdin );
    freopen("puzzle.out","w",stdout);
    work();
    return 0;
}
