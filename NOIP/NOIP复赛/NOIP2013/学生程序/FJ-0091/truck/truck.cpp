#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int maxn = 1010;
int map[maxn][maxn],n,m,q;
void input ()
{
     int i,j,x,y,z;
     scanf ("%d %d", &n, &m);
     for (i=1; i<=n; i++) for (j=1; j<=n; j++) map[i][j]=-1;
     
     for (i=1; i<=m; i++)
     {
         scanf ("%d %d %d", &x, &y, &z);
         if (z>map[x][y] && z>map[y][x]) map[x][y]=map[y][x]=z;
     }
}

void doing ()
{
     int i,j,k;
     for (k=1; k<=n; k++)
         for (i=1; i<=n; i++)
             for (j=1; j<=n; j++)
                 if (i!=j && min(map[i][k],map[k][j])>map[i][j])
                    map[i][j] = map[j][i] = min(map[i][k],map[k][j]);
}

void output ()
{
     int i,x,y;
     scanf ("%d", &q);
     for (i=1; i<=q; i++)
     {
         scanf ("%d %d", &x, &y);
         cout<<map[x][y]<<endl;
     }
}
int main()
{
    freopen ("truck.in", "r", stdin);
    freopen ("truck.out","w",stdout);
    input ();
    doing ();
    output ();
    return 0;
}
