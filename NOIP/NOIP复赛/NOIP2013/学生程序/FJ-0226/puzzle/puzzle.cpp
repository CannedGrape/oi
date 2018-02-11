#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<iostream>
using namespace std;
int n,m,q;
int fx,fy,ex,ey,wx,wy;
int ms[30][30];

int work()
{
 if(ex==wx&&ey==wy) 
 {		
  printf("%d\n",0);		
 }
 else 
 {
  if(abs(ex-wx)+abs(ey-wy)==1&&abs(fx-wx)+abs(fy-wy)==1&&ms[wx][wy]!=0&&ms[ex][ey]!=0) printf("%d\n",2);
  else printf("%d\n",-1);
 }	
}

int main()
{
 freopen("puzzle.in","r",stdin);
 freopen("puzzle.out","w",stdout);	
 scanf("%d%d%d",&n,&m,&q);
 for(int i=1; i<=n; i++)
  for(int j=1; j<=m; j++) scanf("%d",&ms[i][j]);
 for(int i=1; i<=q; i++) 
 { 
  scanf("%d%d%d%d%d%d",&fx,&fy,&ex,&ey,&wx,&wy);
  work(); 		
 }	
 return 0;	
}
