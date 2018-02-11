#include<iostream>
#include<cstdio>
using namespace std;
int n=0,k=0,m=0,s=0,t=0,c[101]={},a[101][101]={},ln=0,ans=2000000000;
int way=0,temp[101]={};
bool b[101][101]={},h[101]={};
bool panduan(int now,int to)
{   if(h[c[to]])
      return false;
    int i;
    for(i=1;i<=k;i++)
      if(h[i] && b[c[to]][i])
        return false;
    if(a[now][to]==0)
      return false;
    return true;
}
void tryy(int now)
{   int i=0;
    for(i=1;i<=n;i++)
      if(panduan(now,i))
        {h[c[i]]=true;
         way+=a[now][i];
         if(i==t)
           {if(way<ans)
              ans=way;
           }
         else
           tryy(i);
         h[c[i]]=false;
         way-=a[now][i];
        }
}
int main()
{   freopen("culture.in","r",stdin);
    freopen("culture.out","w",stdout);
    cin>>n>>k>>m>>s>>t;
    int i=0,j=0,u=0,v=0,d=0;
    for(i=1;i<=n;i++)
      scanf("%d",&c[i]);
    for(i=1;i<=k;i++)
      for(j=1;j<=k;j++)
        scanf("%d",&b[i][j]);
    for(i=1;i<=m;i++)
      {scanf("%d%d%d",&u,&v,&d);
       if(a[u][v]==0 || d<a[u][v])
         a[v][u]=a[u][v]=d;
      }
    h[c[s]]=true;
    tryy(s);
    if(ans==2000000000)
      printf("-1\n");
    else
      printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
