#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,m,q;
long long path[1001][1001],anss[1001],x[1001],y[1001],b[1001],z,num=0;
bool flag[1001];
void solve(int tip)
{
     int i;
     int minn=100001;
     num++;
     for (i=1;i<=tip;i++)
       if (b[i]<minn)
         minn=b[i];
     anss[num]=minn;
     }
void dfs(int k,int tip)
{
     int i;
     for (i=1;i<=n;i++)
     {
             if (path[k][i]!=0 && flag[i]==true)
             {
               flag[i]=false;
               b[tip]=path[k][i];
               if (i==z)
                 solve(tip);
               else
                 dfs(i,tip+1);
               flag[i]=true;
               }
               }
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int i,a,b,j,mxnn;
    memset(path,0,sizeof(path));
    cin>>n>>m;
    for (i=1;i<=m;i++)
    {
        cin>>a>>b;
        cin>>path[a][b];
        path[b][a]=path[a][b];
        }
    cin>>q;
    for (i=1;i<=q;i++)
        cin>>x[i]>>y[i];
    for (i=1;i<=q;i++)
    {
        memset(flag,true,sizeof(flag));
        num=0;
        mxnn=-1;
        flag[x[i]]=false;
        z=y[i];
        dfs(x[i],1);
        for (j=1;j<=num;j++)
            if (anss[j]>mxnn)
              mxnn=anss[j];
        if (mxnn==0)
          cout<<-1<<endl;
        else
          cout<<mxnn<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
    }
        
        
    
    
