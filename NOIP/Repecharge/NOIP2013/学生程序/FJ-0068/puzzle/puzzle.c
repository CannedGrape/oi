#include <stdio.h>
#include <string.h>
int n,m,quest,ei,ej,si,sj,fi,fj,map[32][32] = {0},q[901][3] = {0},q2[2001][4] = {0},head,tail,from[2001] = {0},minlen;
short dir[4][2] = {0,1,1,0,-1,0,0,-1},vis[31][31] = {0},vis2[31][31][2] = {0};
int min(int a,int b)
{
    return a<b?a:b;
}
short check(int id)
{
    if(q2[id][0]==si)
    {
        if(q2[id][1]==sj+1) return 1;
        if(q2[id][1]==sj-1) return 1;
    }
    else if(q2[id][1]==sj)
    {
        if(q2[id][0]==si+1) return 1;
        if(q2[id][0]==si-1) return 1;
    }
    return 0;
}
short find(int id,int ii,int jj)
{
    int i;
    for(i=id;i>1;i=from[i]) if(q2[i][0]==ii&&q2[i][1]==jj&&q2[i][2]==0) return 1;
    return 0;
}
void bfs(int ii,int jj,int ffi,int ffj)
{
    memset(vis,0,sizeof(vis));
    int i,ni,nj;
    head = 1;
    q[head][0] = ii;
    q[head][1] = jj;
    q[head][2] = 0;
    vis[ii][jj] = 1;
    tail = 2;
    while(head<tail)
    {
        for(i=0;i<4;i++)
        {
            ni = dir[i][0]+q[head][0];
            nj = dir[i][1]+q[head][1];
            if(!vis[ni][nj]&&map[ni][nj]&&!(ni==si&&nj==sj))
            {
                vis[ni][nj] = 1;
                q[tail][0] = ni;
                q[tail][1] = nj;
                q[tail][2] = q[head][2]+1;
                if(ni==ffi&&nj==ffj) return;
                tail++;
            }
        }
        head++;
    }
}
void bfs2(int ii,int jj,int ffi,int ffj)
{
    memset(vis2,0,sizeof(vis2));
    int i,ni,nj,nk;
    head = 1;
    q2[head][0] = ii;
    q2[head][1] = jj;
    q2[head][2] = 0;
    q2[head][3] = 0;
    vis2[ii][jj][0] = 1;
    tail = 2;
    while(head<tail)
    {
        for(i=0;i<4;i++)
        {
            ni = dir[i][0]+q2[head][0];
            nj = dir[i][1]+q2[head][1];
            nk = q2[head][2];
            if(!vis2[ni][nj][nk]&&map[ni][nj])
            {
                if(nk==1) if(find(head,ni,nj)) continue;
                vis2[ni][nj][nk] = 1;
                q2[tail][0] = ni;
                q2[tail][1] = nj;
                q2[tail][2] = nk;
                q2[tail][3] = q2[head][3]+1;
                if(ni==ffi&&nj==ffj)
                {
                    q2[tail][2] = 1;
                    if(!minlen) minlen = q2[tail][3];
                }
                from[tail] = head;
                if(ni==ii&&nj==jj&&nk==1) return;
                tail++;
            }
        }
        head++;
    }
}
void work()
{
    int i,ans = 99999999,r;
    if((si==fi&&sj==fj+1)||(si==fi&&sj==fj-1)||(sj==fj&&si==fi+1)||(sj==fj&&si==fi-1))
    {
        if(ei==fi&&ej==fj)
        {
            printf("1\n");
            return;
        }
        bfs(ei,ej,fi,fj);
        if(q[tail][0]==fi&&q[tail][1]==fj) printf("%d\n",q[tail][2]+1);
        else printf("-1\n");
        return;
    }
    else
    {
        minlen = 0;
        bfs2(si,sj,fi,fj);
        if(minlen>0)
        {
            r = q2[tail][3];
            for(i=tail;i>1;i=from[i])
            {
                if(check(i))
                {
                    bfs(ei,ej,q2[i][0],q2[i][1]);
                    if(q[tail][0]==q2[i][0]&&q[tail][1]==q2[i][1])
                    {
                        if(q2[i][2] == 0) ans = min(ans,q[tail][2]+(r-1)*(minlen-1)+1);
                        else ans = min(ans,q[tail][2]+(r-1)*(r-minlen-1)+1);
                    }
                }
            }
        }
        if(ans!=99999999) printf("%d\n",ans);
        else printf("-1\n");
    }
    return;
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int i,j,qq;
    scanf("%d%d%d",&n,&m,&quest);
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%d",&map[i][j]);
    for(qq=1;qq<=quest;qq++)
    {
        scanf("%d%d%d%d%d%d",&ei,&ej,&si,&sj,&fi,&fj);
        if(!map[ei][ej]||!map[si][sj]||!map[fi][fj]) printf("-1\n");
        else if(si==fi&&sj==fj) printf("0\n");
        else work();
    }
    return 0;
}
