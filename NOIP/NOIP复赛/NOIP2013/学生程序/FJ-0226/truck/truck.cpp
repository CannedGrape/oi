#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,x,y,z,qes;
struct road
{
 int ch;
 int next[3000];
 int v[3000];	
};
road a[3000];	
int d[3000][3000];
int v[3000],pre[3000];
int DFS(int s)
{
 for(int i=1; i<=a[s].ch; i++)
 {
  int h=a[s].next[i];			
  if(v[h]!=-1)
  {
   v[h]=-1;
   pre[h]=s;
   d[s][h]=max(d[s][h],a[s].v[i]);
   int k=pre[s];
   while(k!=0)
   {
	d[k][h]=min(d[k][s],a[s].v[i]);	
	k=pre[k];
   }
   DFS(h);
   v[h]=1;		
  }
 }	
}


int main()
{
 freopen("truck.in","r",stdin);
 freopen("truck.out","w",stdout);	
 scanf("%d%d",&n,&m);
 for(int i=1; i<=m; i++) 
 {
  scanf("%d%d%d",&x,&y,&z);
  a[x].next[++a[x].ch]=y;
  a[x].v[a[x].ch]=z;
  a[y].next[++a[y].ch]=x;	
  a[y].v[a[y].ch]=z;	
 }	
 for(int i=1; i<=n; i++)
  for(int j=1; j<=n; j++) d[i][j]=-1;
 scanf("%d",&qes);
 for(int i=1; i<=qes; i++)
 {
  scanf("%d%d",&x,&y);
  if(x>y){int tmp=x; x=y; y=tmp;}
  if(d[x][y]==-1) 
  {
	for(int j=1; j<=n; j++) v[j]=1;	
	v[x]=-1;
	pre[x]=0;
	DFS(x); 
	printf("%d\n",d[x][y]); 
  }
  else if(d[x][y]>0) printf("%d\n",d[x][y]);
       else printf("%d\n",d[y][x]);
  	   		
 }
 return 0;
}
