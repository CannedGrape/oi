#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
long int n,k,m,s,t;
long int lt[1001][1001];
long int cul[1001];
bool pc[1001][1001];
long int final=0;
long int lj[1001];
long int been;
long int fa;
long int finalans;
int md(long int test)
{
    bool flag=false;
    long int i;
    for(i=1;i<=been-1;i++)
    {
       if(pc[test][lj[i]]==true)
         flag=true;
    }
    return flag;
}
int hl(long int test)
{
    long int i;
    bool flag=false;
    for(i=1;i<=been-1;i++)
    {
       if(test==lj[i])
         flag=true;
    }
    return flag;
}
void tryy(long int now)
{
     long int i;
     for(i=1;i<=n;i++)
     {
        if((md(cul[i])==false)&&(i!=now)&&((lt[now][i]>=0)||(lt[i][now]>0))&&(hl(i)==false))
        {
           final+=lt[now][i];
           lj[been]=s;
           been++;
           if(i==t)
           {
              if((finalans==0)||(final<finalans))
                 finalans=final;
           }
           else
             tryy(i);
            final-=lt[now][i];
            lj[been]=0;
            been--; 
        }
     }
}
int main()
{
    freopen("culture.in","r",stdin);
    freopen("culture.out","w",stdout);
    finalans=0;
    memset(lt,0,sizeof(lt));
    memset(cul,0,sizeof(cul));
    memset(pc,0,sizeof(pc));
    memset(lj,0,sizeof(lj));
    long int u,v,d;
    fa=false;
    been=1;
    long int i,j;
    cin>>n>>k>>m>>s>>t;
    for(i=1;i<=n;i++)
     cin>>cul[i];
    for(i=1;i<=k;i++)
      for(j=1;j<=k;j++)
      {
         cin>>pc[i][j];           
      }
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>d;
        if((d<=lt[u][v])||(lt[u][v]==0))
        {
         lt[u][v]=d;
         lt[v][u]=d;
        }           
 
    }
    lj[1]=s;
    been++;
    if(md(cul[t])==true)
      cout<<"-1"<<endl;
    else
    {
    tryy(s);
    if(finalans==0)
     cout<<"-1"<<endl;
    else
      cout<<finalans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
