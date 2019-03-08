#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#include<queue>

using namespace std;
const int maxn=10000+10,maxm=50000+10,lgn=20,inf=100000000+10;

int n,m,Q,pa[maxn],pre[maxn],tot=0,f[maxn][lgn+2],d[maxn][lgn],dep[maxn];
bool is_root[maxn],vis[maxn];
queue<int>q;


struct node{
 int from,to,cost;
 bool can_build;
}a[maxm];

struct edge{
 int to,cost,next;
}s[maxn*2+10];

bool operator<(const node &x1,const node &y1){
 return x1.cost<y1.cost;
}

int find(int x){return x==pa[x]? x: pa[x]=find(pa[x]);}

void Link(int x,int y,int z){
 s[++tot].to=y,s[tot].cost=z;
 s[tot].next=pre[x],pre[x]=tot;
}

void init(){
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++) 
  scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].cost);
 sort(a+1,a+m+1);
}

void kruskal(){
 for(int i=1;i<=n;i++) pa[i]=i;//bcj pa[i]=i!!!
 
 for(int i=m;i>=1;i--){
  int f1=find(a[i].from),f2=find(a[i].to);
 
  if(f1!=f2){
   pa[f1]=f2;
   a[i].can_build=1;//,fanzhezuo可以生成maxtree 
  }
  
 }  
 
}

void build_edge(){
 for(int i=1;i<=n;i++){
  int fa=find(i);
  is_root[fa]=1;
 }
 for(int i=1;i<=n;i++)
  if(is_root[i]){
   Link(n+1,i,0);
   Link(i,n+1,0); 
  }
 for(int i=1;i<=m;i++)
  if(a[i].can_build==1){
   Link(a[i].from,a[i].to,a[i].cost);
   Link(a[i].to,a[i].from,a[i].cost);
  }//zai shu shang de bian 
}

void bfs(){
 dep[n+1]=1;
 q.push(n+1),vis[n+1]=1;
 while(!q.empty()){
  int x=q.front();
  for(int i=pre[x];i;i=s[i].next){
   int y=s[i].to;
   if(!vis[y]){
	q.push(y),vis[y]=1;//chadianwangle!
    int z=s[i].cost;
    f[y][0]=x,d[y][0]=z;
    dep[y]=dep[x]+1;
   }
  }
  q.pop();
 }
}

void build_kmp(){
 bfs(); 
 for(int j=1;j<lgn;j++)
  for(int i=1;i<=n;i++){
   f[i][j]=f[f[i][j-1]][j-1];
   d[i][j]=min(d[i][j-1],d[f[i][j-1]][j-1]);
  }
}

int ask(int x,int y){
 int ret=inf;
 
 if(dep[x]<dep[y]) swap(x,y);
 
 for(int i=lgn;i>=0;i--)
  if(dep[f[x][i]]>=dep[y]){
   ret=min(ret,d[x][i]);
   x=f[x][i];
  }
  
 if(x!=y){
  for(int i=lgn;i>=0;i--)
   if(f[x][i]!=f[y][i]){
    ret=min(ret,d[x][i]);
    x=f[x][i];
    ret=min(ret,d[y][i]);
    y=f[y][i];
   }
  ret=min(ret,d[x][0]);
  ret=min(ret,d[y][0]);
 }
 
 return ret;
}

void work(){
 scanf("%d",&Q);
 for(int i=1;i<=Q;i++){
  int x,y;
  scanf("%d%d",&x,&y);
  int numb=ask(x,y);
  if(numb==0) printf("%d\n",-1);
  else printf("%d\n",numb);
 }
}

int main(){
 freopen("truck.in","r",stdin);
 freopen("truck.out","w",stdout);
 init();
 kruskal();
 build_edge();
 build_kmp();
 work();
 return 0;
}

//,pos;
//a[i].pos=i;
 //
 /*for(int i=1;i<=m;i++)
  printf("%d %d %d %d\n",a[i].from,a[i].to,a[i].cost,a[i].pos);*/
 //
 
  //
 /*for(int i=1;i<=m;i++)
  printf("%d %d %d %d %d\n",a[i].can_build,a[i].from,a[i].to,a[i].cost,a[i].pos);
 *///
