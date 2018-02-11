#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <memory.h>
using namespace std;
int maxn=200000;
int number,n,m;
int q[30010][2],ans[30010];
int edge[60010]={},lastedge[10010]={},nextedge[60010]={},numedge[10010]={},length[60010],tot;
int edge0[60010]={},lastedge0[10010]={},nextedge0[60010]={},numedge0[10010]={},rq[60010],tot0;
int father[30010];
int dis[10010];

void add(int a,int b,int c)
{
     if(numedge[a]==0)
     {edge[a]=b;
      lastedge[a]=a;
      numedge[a]++;
      length[a]=c;}
     else
     {tot++;
      numedge[a]++;
      edge[tot]=b;
      nextedge[ lastedge[a] ]=tot;
      lastedge[a]=tot;
      length[tot]=c;
     }
}

void add0(int a,int b,int c)
{
     if(numedge0[a]==0)
     {edge0[a]=b;
      lastedge0[a]=a;
      numedge0[a]++;
      rq[a]=c;}
     else
     {tot0++;
      numedge0[a]++;
      edge0[tot0]=b;
      nextedge0[ lastedge0[a] ]=tot0;
      lastedge0[a]=tot0;
      rq[tot0]=c;
     }
}

/*int getfather(int qb)
{
    if( father[qb]==qb ) return qb;
    else return getfather(father[qb]);
    father[qb]=father[father[qb]];
}*/

void spfa(int x)
{
     int j=x;
     for(int i=1;i<=numedge[x];i++)
     {if( min(dis[x],length[j])>dis[edge[j]] ) {
        dis[edge[j]]=min(dis[x],length[j]);
        spfa(edge[j]);}
        j=nextedge[j];
     }
}

void init()
{
     int x,y,z,k,x1,x2;
     scanf("%d%d",&number,&n);
     tot=number;tot0=number;
     for(int i=1;i<=n;i++){
       scanf("%d%d%d",&x,&y,&z);
       add(x,y,z);add(y,x,z);}
     scanf("%d",&m);
     for(int i=1;i<=m;i++){
       scanf("%d%d",&q[i][0],&q[i][1]);
       add0(q[i][0],q[i][1],i);
       add0(q[i][1],q[i][0],i);}
     /*
     for(int i=1;i<=n;i++) father[i]=i;    
     for(int i=1;i<=n;i++){
       k=i;
       for(int j=1;j<=numedge[i];j++)
       {x1=getfather(i),x2=getfather(edge[k]);
        if(x1!=x2)  father[x1]=x2;
        k=nextedge[k];}
       }*/
     
  //   for(int i=1;i<=tot0;i++)
  //     cout<<edge0[i]<<" ";cout<<endl;
  //   for(int i=1;i<=tot0;i++)
   //    cout<<rq[i]<<" ";cout<<endl;
}

void work()
{
     int x1,x2,l1,l2,k0;
     
     for(int i=1;i<=m;i++)
     if(ans[i]==0){
     x1=q[i][0],x2=q[i][1];
     /*l1=getfather(x1),l2=getfather(x2);
     if( father[x1]!=father[x2] )
     {ans[i]=-1;}
     else*/
     {for(int j=1;j<=number;j++) dis[j]=-1;
      dis[x1]=maxn;
      spfa(x1);
      
    //  cout<<x1<<endl;
   //   for(int j=1;j<=number;j++) cout<<dis[j]<<" ";cout<<endl;
      
      k0=x1;//cout<<k0<<" "<<numedge0[k0]<<endl;
      for(int j=1;j<=numedge0[x1];j++){
        if(ans[rq[k0]]==0){
       // cout<<x1<<" "<<edge0[k0]<<" "<<dis[edge0[k0]]<<endl;
        ans[rq[k0]]=dis[edge0[k0]];}
        k0=nextedge0[k0];}
     }
     }
}

void print()
{
     for(int i=1;i<=m;i++)
       printf("%d\n",ans[i]);
}

int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    init();
    work();
    print();
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
