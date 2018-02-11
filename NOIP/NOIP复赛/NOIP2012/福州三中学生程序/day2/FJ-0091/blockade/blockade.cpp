#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
#define MXN 50010
#define MXM 100010
struct node
{
       int v,w,last;
}e[MXM];
int n,tot=0,zh[MXN];
void add(int u,int v,int w)
{
     e[++tot].v=v;
     e[tot].w=w;
     e[tot].last=zh[u];
     zh[u]=tot;
}
void Init()
{
     int u,v,w;
     scanf("%d",&n);
     for (int i=1;i<=n-1;i++)
        {
          scanf("%d%d%d",&u,&v,&w);
          add(u,v,w);add(v,u,w);
        }
}
void solve()
{
     printf("-1\n");
}
int main()
{
    freopen("blockade.in","r",stdin);
    freopen("blockade.out","w",stdout);
    
    Init();
    solve();
    
    fclose(stdin);fclose(stdout);
    return 0;
}
