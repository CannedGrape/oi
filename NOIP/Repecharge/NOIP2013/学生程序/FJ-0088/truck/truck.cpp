#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<cstring>
using namespace std;
int truck[30001][3];
bool flag[1001];
int path[1001][1001];
int f[1001][1001];
int pre[1001];
int minn=100001,n;
int s,t;
int j;
bool b;
void dfs(int k)
{
     int temp=minn;
     if(k==t)
     {
     b=true;
     if(truck[j][2]<minn)
     truck[j][2]=minn;
     return;
     }
     else 
     for(int i=1;i<=n;i++)
     {
     if(path[k][i]>0&&!flag[i])
     {
     flag[i]=true;
     if(minn>path[k][i])
     minn=path[k][i];
     dfs(i);
     flag[i]=false;
     minn=temp;
     }
     }
}
     
     
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int m,i,x,y,z;
    cin>>n>>m;
    memset(f,0,sizeof(f));
    memset(flag,false,sizeof(flag));
    for(i=1;i<=m;i++)
    {
    scanf("%d%d%d",&x,&y,&z);
    path[x][y]=max(path[x][y],z);
    path[y][x]=max(path[y][x],z);
     }
    int q;
    cin>>q;
    for(i=1;i<=q;i++)
    scanf("%d%d",&truck[i][0],&truck[i][1]);
    for(i=1;i<=q;i++)
    {
    flag[truck[i][0]]=true;
    j=i;b=false;
    t=truck[i][1];
    dfs(truck[i][0]);
    if(b)
   printf("%d\n",truck[i][2]);
    else
    printf("%d\n",-1);
    flag[truck[i][0]]=false;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
