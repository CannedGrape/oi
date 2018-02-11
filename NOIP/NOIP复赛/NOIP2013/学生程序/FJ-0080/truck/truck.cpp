#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int t[10001][10001];
int n,m,q;
struct Q
{
    int s,t,v;
};
Q a[50001];
int c[10001][10001];
void  doing(int x,int y)
{
    if(t[y][0]==0)
    return;
    for(int i=1;i<=t[y][0];i++)
    {
            doing(x,c[y][i]);
            t[y][c[y][i]]=max(t[y][c[y][i]],t[x][c[y][i]]);
            t[x][c[y][i]]=max(t[x][c[y][i]],min(t[x][y],t[y][c[y][i]]));
    }
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int x,y,z;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    t[i][j]=-1;
    for(int i=1;i<=m;i++)
    {
            scanf("%d %d %d",&x,&y,&z);
            t[min(x,y)][max(x,y)]=z;
            t[min(x,y)][0]++;
            c[min(x,y)][t[min(x,y)][0]]=max(x,y);
    }
    /*for(int j=n;j>1;j--)
    for(int i=n-1;i>=1;i--)
    if(i<=j)
    {
            if(t[i][j]=-1)
            {
                           if(t[j][0]>0)
                           {
                                        int tot=0;
                                        while(tot<t[j][0])
                                        {
                                                          tot++;
                                                          t[i][c[j][tot]]=max(t[i][c[j][tot]],min(t[i][j],t[j][c[j][tot]]));
                                        }
                           }
            }
    }*/
    for(int i=1;i<n;i++)
    for(int j=2;j<=n;j++)
    if(i<j)
    {
           if(t[i][j]!=-1)
           doing(i,j);
    }
    cin>>q;
    for(int i=1;i<=q;i++)
    {
            scanf("%d %d",&x,&y);
            printf("%d\n",t[x][y]);
    }
}
