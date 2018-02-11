#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <cstring>
#include <memory.h>
#define MAN 50010
#define MAM 50010
using namespace std;
struct node
{
       int v,w,next;
}edge[MAN<<1];
int head[MAN],tot,tots,n,m,c[MAN];
long long dis[MAN];
bool flag[MAN];
void addedge(int v1,int v2,int w)
{
     edge[++tot].v=v2;
     edge[tot].next=head[v1];
     head[v1]=tot;
     edge[tot].w=w;
}
int main()
{
    freopen("blockade.in","r",stdin);
    freopen("blockade.out","w",stdout);
	long long ans;
    int i,u,v,w;
    ans=0;
    scanf("%d",&n);
    for (i=1;i<n;i++)
      {scanf("%d%d%d",&u,&v,&w);
       addedge(u,v,w);
       addedge(v,u,w);
      }
    scanf("%d",&m);
    for (i=1;i<=m;i++) scanf("%d",&c[i]);
    tots=0;
    for (i=head[1];i;i=edge[i].next) tots++;
    dis[0]=0;
    if (tots>m) printf("-1\n");
    else
      {for (i=head[1];i;i=edge[i].next) ans+=edge[i].w;
       cout<<ans<<endl;  
      }
    fclose(stdin);
    fclose(stdout);  
    return 0;
}
