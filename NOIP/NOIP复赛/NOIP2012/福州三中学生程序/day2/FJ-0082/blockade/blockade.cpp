#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=50000;
int n,m,next[100001],point[100001],edge[50001],v[100001],vis[50001];
int army[50001],d[50001];
bool cover[50001],leave[50001];
void find(int x,int last)
{
     vis[x]=1;
     if(cover[last])
       cover[x]=1;
     int j=edge[x],y;
     while(j)
       {y=point[j];
        if(!vis[y])
          find(y,x);
        j=next[j];
        }
}
int main()
{
    freopen("blockade.in","r",stdin);
    freopen("blockade.out","w",stdout);
    
    int i,x,y,z;
    scanf("%d",&n);
    for(i=1;i<=n-1;i++)
      {scanf("%d%d%d",&x,&y,&z);
       point[i]=y;
       v[i]=z;
       next[i]=edge[x];
       edge[x]=i;
       d[x]++;
       point[i+maxn]=x;
       v[i+maxn]=z;
       next[i+maxn]=edge[y];
       edge[y]=i+maxn;
       d[y]++;
       v[0]=max(v[0],v[i]);
       }
    for(i=2;i<=n;i++)
      if(d[i]==1)
        leave[i]=1;
    scanf("%d",&m);
    for(i=1;i<=m;i++)
      {scanf("%d",&x);
       army[x]++;
       cover[x]=1;
       }
    
    //find(1,0);
    
    for(i=1;i<=n;i++)
      army[0]+=army[i];
    if(d[1]>army[0])
      printf("-1\n");
    else
      printf("%d\n",v[0]);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
