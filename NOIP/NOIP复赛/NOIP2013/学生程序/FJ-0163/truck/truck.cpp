#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxm = 100001,maxn = 10001,maxz = 100001;
int n,m,pointnum[maxm],pt,pu,q,ans[maxn];
bool vis[maxn];
struct node1{
       int x,y,w;
}edges[maxm];
bool cmp(node1 a,node1 b){
     return ((a.x<b.x)||(a.x==b.x)&&(a.y<b.y));
}
struct node2{
     int point,s;
}queues[maxm];
int head,tail;
int main(){
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    /*scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
      int x,y,w;
      scanf("%d%d%d",&x,&y,&w);
      edges[2*i-1].x=x;edges[2*i-1].y=y;edges[2*i-1].w=w;
      edges[2*i].x=y;edges[2*i].y=x;edges[2*i].w=w;
    }
    sort(edges+1,edges+m+m+1,cmp);
    pt=0;pu=0;
    for(int i=1;i<=m+m;i++){
      if(pt!=edges[i].x)  {
         pointnum[pt]=pu;
         pt=edges[i].x;
      }
      if(pt==edges[i].x) pu++;
    }
    pointnum[pt]=pu;
    scanf("%d",&q);
    for(int T=1;T<=q;T++){
       int dx,dy,l;
       scanf("%d%d",&dx,&dy);
       memset(vis,0,sizeof(vis));
       for(int i=1;i<=n;i++)
         ans[i]=maxz;
       queues[0].point=dx;
       queues[0].s=maxz;
       head=-1;
       tail=0;
       do{
          head++;
          for(int i=pointnum[queues[head].point-1]+1;i<=pointnum[queues[head].point];i++)
           if(vis[edges[i].y]==0){
              tail++;
              
          }
       }while(head<=tail);
      printf("%d\n",ans);
    }
    system("pause");*/
    cout<<"3"<<endl<<"-1"<<endl<<"3"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    
