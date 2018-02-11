#include <iostream>
#define FOR(i,a,b) for(int i = a;i <= b;++i)
using namespace std;

int n,m,q;
int dis[10001][10001];
template <typename t> t MAX(t a,t b){return (a > b)?a:b;}
template <typename t> t MIN(t a,t b){return (a < b)?a:b;}

int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    //read n & m
    scanf("%d%d",&n,&m);
    
    //init dis[] to -1
    FOR(i,1,n)
        FOR(j,1,n)
            dis[i][j] = -1;
    
    //read data1
    FOR(i,1,m)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (c > dis[a][b]) dis[a][b] = dis[b][a] = c;
    }
    //read q
    scanf("%d",&q);
    if (q == 0) return 0;
    
    //init dis[] to real data
    FOR(k,1,n)
        FOR(i,1,n)
            FOR(j,1,n)
                dis[i][j] = MAX(dis[i][j],MIN(dis[i][k],dis[k][j]));
    
    //read data2
    FOR(i,1,q)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a > n || b > n) printf("-1");
        printf("%d\n",dis[a][b]);
    }
    //scanf("%*");
    fclose(stdin);fclose(stdout);
    return 0;
}
