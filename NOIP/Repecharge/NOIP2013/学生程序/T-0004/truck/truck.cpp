#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int n,m,q;
int w[1001][1001];

int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; ++i)
    {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(z>w[x][y])
            w[x][y]=w[y][x]=z;   
            }
    for(int k=1; k<=n; ++k)
            for(int i=1; i<=n; ++i)
                    for(int j=1; j<=n; ++j)
                            if(w[i][k] && w[k][j])
                                       w[i][j]=max(w[i][j],min(w[i][k],w[k][j]));                                 
    scanf("%d",&q); 
    for(int i=1; i<=q; ++i)
    {
            int x,y;
            scanf("%d%d",&x,&y);
            if(w[x][y]) printf("%d\n",w[x][y]);
            else printf("-1\n");
            } 
    fclose(stdin);
    fclose(stdout);        
    return 0;           
}
