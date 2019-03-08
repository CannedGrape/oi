#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int last[10001],next[10001],T,s[10001],a[1001][1001];
int d[1001][1001];
int n,m,qq;
int q[100001];
bool in[10001],v[10001];
void add(int x,int y)
{
  T++;
  next[T]=last[x];
  last[x]=T;
  s[T]=y; 	
}
void go(int x)
{
  int l=0;
  int r=1;
  memset(v,true,sizeof(v));
  d[x][x]=0;
  q[1]=x;
  v[x]=false;
   while (l<=r)
    {
	  l++;
	  int xx=q[l];
	  for (int i=last[xx]; i; i=next[i])
	   if (a[xx][s[i]]>=d[x][s[i]])
	    {
		  if (d[x][xx]!=0) d[x][s[i]]=max(d[x][s[i]],min(a[xx][s[i]],d[x][xx]));
		  else d[x][s[i]]=a[xx][s[i]];
		  if (v[s[i]]) 	
		  r++;
		  q[r]=s[i];
		  v[s[i]]=false;
		}
	v[xx]=true;	
	} 	
}
int main(){
  freopen("truck.in","r",stdin);
  freopen("truck.out","w",stdout);
  scanf("%d%d",&n,&m);
  for (int i=1; i<=m; i++)
    {
	  int x,y,z;	
	  scanf("%d%d%d",&x,&y,&z);
	  if (x>y) swap(x,y);
	  if (a[x][y]==0)
		  add(x,y);
	  a[x][y]=max(a[x][y],z);	  
	}
   scanf("%d",&qq);
   for (int i=1; i<=qq; i++)
    {
	 int x,y;
	 scanf("%d%d",&x,&y);
	 if (x>y) swap(x,y);
     if (!in[x]) {go(x); in[x]=true;}
	 if (d[x][y]!=0) printf("%d\n",d[x][y]); else printf("-1\n");
	}	
  fclose(stdin); fclose(stdout);
}

