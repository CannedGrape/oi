#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
//int A[100000];
//int B[100000];
using namespace std;
const int maxn=10001;
const int maxm=50001;
const int INF=0x7fffffff;
int n,m;
struct map{int now,to,cost;map():cost(0x7fffffff){};}F[maxm];
bool used[maxn];
bool cmp(map a,map b)
{return a.cost>b.cost;}
int pbmaps[maxn][maxn];
int maps[maxn][maxn];
bool useds[maxn];
void kruskal()
{
   sort(F,F+m,cmp);
   for(int i=0;i<m;i++)
      if(!used[F[i].now]|| !used[F[i].to])
      {maps[F[i].now][F[i].to]=F[i].cost;
       maps[F[i].to][F[i].now]=F[i].cost;
        used[F[i].now]=1,used[F[i].to]=1;
      }
}
int dfs(int x,int y)
{
   if(x==y)return INF;
   if(pbmaps[x][y]!=0)return pbmaps[x][y];
   int ans=INF;
   useds[x]=true;
   for(int i=0;i<n;i++)
      if(maps[x][i]!=INF && !useds[i])
         ans=dfs(i,y);
   useds[x]=false;
   pbmaps[x][y]=min(maps[x][y],ans);
     return pbmaps[x][y];
}
void init()
{
  scanf("%d%d",&n,&m);
       for(int i=0;i<=n;i++)
       for(int j=0;j<=n;j++)
          maps[i][j]=INF;
  int x,y,z;
//  cout<<m<<endl;
  int i=0;
  while(i<m)
  {scanf("%d%d%d",&x,&y,&z);
       F[i].now=x;
       F[i].to=y;
       F[i].cost=z;
     i++;
       }
    kruskal();
 //   system("pause");
   int q;
  scanf("%d",&q);
  int temp;
  for(int i=0;i<q;i++)
     { scanf("%d%d",&x,&y);   
      temp=dfs(x,y);
      cout<<(temp==INF?-1:temp)<<"\n";
      }
}
int main()
{
   
   freopen("truck.in","r",stdin);
  freopen("truck.out","w",stdout);
    init();
    //system("pause");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
