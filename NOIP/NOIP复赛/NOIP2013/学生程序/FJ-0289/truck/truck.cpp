#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
const int N=10002,M=100002;
using namespace std;
int k,Last[N],Next[M],To[M],s[M],x[M],y[M],len=0,d[1001][1001],n,m;
bool p[N],check[N];
queue<int>q;
void addedge(int x,int y,int z)
{
	Next[++len]=Last[x]; Last[x]=len; To[len]=y; s[len]=z;
	Next[++len]=Last[y]; Last[y]=len; To[len]=x; s[len]=z;
}
void spfa(int k)
{
   for (int i=1;i<=n;i++) check[i]=false,d[k][i]=999999999;
   q.push(k);
   check[k]=true;
   //d[k][k]=0;
   while (!q.empty())
    {
	   int now=q.front();
	   for (int i=Last[now];i;i=Next[i])
		{
		  if (d[k][now]<=s[i]&&(d[k][To[i]]<s[i]||d[k][To[i]]==999999999)) d[k][To[i]]=d[k][now];
	      if (d[k][now]>s[i]&&(d[k][To[i]]<s[i]||d[k][To[i]]==999999999))
		   {	
		     d[k][To[i]]=s[i];
		     if (!check[To[i]]) q.push(To[i]);
		   }		
		}
	   q.pop();
	   check[now]=false;	
	}
}
int main(){
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	   scanf("%d%d",&n,&m);
	   for (int i=1;i<=m;i++)
	    {
		  int a,b,c;
		  scanf("%d%d%d",&a,&b,&c);
		  addedge(a,b,c);
		}
	   scanf("%d",&k);
	   memset(p,false,sizeof(p));
	   for (int i=1;i<=k;i++)
	    {
		  scanf("%d%d",x+i,y+i);
		  p[x[i]]=true;
		}
       for (int i=1;i<=n;i++)
	    if (p[i]) spfa(i);	
	   for (int i=1;i<=k;i++)
	   if (d[x[i]][y[i]]==999999999)  printf("-1\n");
	   else
	    printf("%d\n",d[x[i]][y[i]]);	
	fclose(stdin);fclose(stdout);
}
