#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n,m,f[10001][10001];
bool mp[10001][10001];
int bg[50001],ed[50001],xz[50001];
int dl[1000000];
bool pd[10001];
int q,x,y;
void search()
{
     int t=1,w=2;
     dl[t]=bg[1];
     pd[dl[t]]=1;
     while(t<=w){
             for(int i=1;i<=n;i++){
                        if(f[dl[t]][i]!=-1)
                        {
                        for(int j=1;j<=n;j++)
                        if(f[i][j]!=-1&&min(f[dl[t]][i],f[i][j])>f[dl[t]][j])
                        {
                        f[dl[t]][j]=min(f[dl[t]][i],f[i][j]);
                        if(!pd[j]){pd[j]=1;dl[w]=j;w++;}
                        }
                        }
                        }
                        pd[dl[t]]=0;
                        t++;
                        }
                }
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    cin>>n>>m;
    memset(f,-1,sizeof(f));
    memset(pd,false,sizeof(pd));
    for(int i=1;i<=m;i++)
    {
            scanf("%d%d%d",&bg[i],&ed[i],&xz[i]);
            f[bg[i]][ed[i]]=max(f[bg[i]][ed[i]],xz[i]);
            f[ed[i]][bg[i]]=max(f[ed[i]][bg[i]],xz[i]);
    }
    search();
    cin>>q;
    for(int i=1;i<=q;i++)
       {
            scanf("%d%d",&x,&y);
            printf("%d\n",f[x][y]);
        }
    return 0;
}
