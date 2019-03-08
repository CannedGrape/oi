#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
int n,m,q,w[10010][10010];
bool can[10010][10010],disban[10010]={0};
using namespace std;
int main()
{
freopen("truck.in","r",stdin);
freopen("truck.out","w",stdout);
    memset(w,0,sizeof(w));
    memset(can,0,sizeof(can));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
    int x,y,z;
    cin>>x>>y>>z;
    if(z!=0){
    w[x][y]=max(w[x][y],z);
    w[y][x]=max(w[y][x],z);
    can[x][y]=true;can[y][x]=true;disban[x]=true;disban[y]=true;}
    }
    cin>>q;
    for(int i=1;i<=n;i++)
    {
        if(disban[i]==false)continue;
        for(int j=1;j<=n;j++)
        {
            if(disban[j]==false)continue;
            for(int k=1;k<=n;k++)
            {
                if(disban[k]==false)continue;
                if(can[i][k]&&can[k][j])
                     {w[i][j]=max(min(w[i][k],w[k][j]),w[i][j]);can[i][j]=true;}
            }
        }
    }
    for(int i=1;i<=q;i++)
    {int x,y;cin>>x>>y;
    if(can[x][y]&&x!=y)cout<<w[x][y]<<endl;else cout<<-1<<endl;}
    return 0;
}
