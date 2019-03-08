#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string>
using namespace std;
int road[1001][1001]={},i,j,k,s,last=-1;
int n,m;
int ans[1001]={};
int v[1001]={};
int did[1001]={};
bool f[1001][1001]={};
void putin()
{
 for (int q=0;q<m;q++)
  {
   scanf("%d%d%d",&i,&j,&k);
   road[i][j]=max(road[i][j],k);
   road[j][i]=road[i][j];
  }
}

void re()
{
 for (int q=1;q<=n;q++)
  for (int p=1;p<=n;p++)
   if (road[q][p]>0)
    f[q][p]=1;
   else f[q][p]=0;
}

void find(int x,int y)
{
 re();
 memset(ans,0,sizeof(ans));
 memset(v,0,sizeof(v));
 memset(did,0,sizeof(did));
 int head=0,tail=0;
 v[head]=x;
 for (int q=1;q<=n;q++) 
  ans[q]=road[x][q];
 
 while (head<=tail)
 {
  for (int q=1;q<=n;q++)
   if (road[ v[head] ][ q] > 0 && f[ v[head]] [q] ==1)
    {
     f[ v[head]] [q] =0;  f[ q] [v[head]] =0;
     if (did[q]==0) { tail++; v[tail]=q; did[q]=tail; 
                     ans[q]=max(ans[q],min(ans[v[head]],road[v[head]][q]));}
     else { ans[q]=max( ans[q],min(ans[v[head] ],road[ v[head] ][q]));}
    }
   head++;
 }
 
 if (ans[y]<=0) printf("-1\n");
 else 
 printf("%d\n",ans[y]);
}


int main()
{
freopen("truck.in","r",stdin); freopen("truck.out","w",stdout);
scanf("%d%d",&n,&m);
if (n<=1000) { putin(); scanf("%d",&s);
               for (int q=0;q<s;q++) 
                {
                 scanf("%d%d",&i,&j);
                 if (last==i) { if (ans[j]<=0) printf("-1\n");else printf("%d\n",ans[j]);}
                 else  find(i,j);
                 last=i;
                }
            }
else {
      scanf("%d",&s);
      for (int q=0;q<s;q++)
       printf("-1\n");
     }
fclose(stdin);fclose(stdout);
return 0;
} 
