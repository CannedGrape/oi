#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int xz[4]={0,1,0,-1},yz[4]={1,0,-1,0};
int n,m,q;
int len[32][32][32][32][2];
int mapp[31][31];
queue<int >qx;
queue<int> qy;
void init(){
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=n;i++)
      for (int j=1;i<=m;j++)
        scanf("%d",&mapp[i][j]);
    int k,h;
    int xxx,yyy;
    bool vis[31][31];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (mapp[i][j]){
                for (k=1;k<=n;k++)
                {  for (h=1;h<=m;h++)
                    {vis[k][h]=false;len[i][j][k][h][0]=1000;len[i][j][k][h][1]=1000;}}
                len[i][j][i][j][0]=0;
                len[i][j][i][j][1]=0;
                while (!qx.empty()) qx.pop();
                while (!qy.empty()) qy.pop();
                qx.push(i);qy.push(j);
                vis[i][j]=true;
                while (!qx.empty()){
                    k=qx.front();h=qy.front();
                    qx.pop();qy.pop();
                    for (int ii=0;ii<=3;ii++){
                        xxx=k+xz[ii];yyy=h+yz[ii];
                        if (xxx>=1 && xxx<=n && yyy>=1 && yyy<=m && mapp[xxx][yyy]){
                            if (!vis[xxx][yyy]){
                                qx.push(xxx);qy.push(yyy);
                                vis[xxx][yyy]=true;
                                len[i][j][xxx][yyy][0]=len[i][j][k][h][0]+1;
                            }
                            else len[i][j][xxx][yyy][1]=min(len[i][j][xxx][yyy][1],len[i][j][k][h][0]+1);
                        }
                    }
                }
            }
        }
    }
}
void solve(){
    int ex,ey,sx,sy,tx,ty;
    int ans,now;
    for (int i=1;i<=q;i++){
        scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
        ans=0;
        if (len[sx][sy][tx][ty][0]==1000){
            cout<<"-1\n"<<endl;
        }
        else{
            int xxx,yyy;
            int k,h;
            bool vis[31][31];
            int lenn[31][31];
            for (int i=1;i<=n;i++)
              for (int j=1;j<=m;j++)
                vis[i][j]=false,lenn[i][j]=1000;
            while (!qx.empty()) qx.pop();
            while (!qy.empty()) qy.pop();
            qx.push(ex);qy.push(ey);
            vis[ex][ey]=true;
            lenn[ex][ey]=0;
            while (!qx.empty()){
                k=qx.front();h=qy.front();
                qx.pop();qy.pop();
                for (int ii=0;ii<=3;ii++){
                    xxx=k+xz[ii];yyy=h+yz[ii];
                    if (xxx>=1 && xxx<=n && yyy>=1 && yyy<=m && mapp[xxx][yyy] && !vis[xxx][yyy] && !(xxx==sx && yyy==sy)){
                        qx.push(xxx);qy.push(yyy);
                        vis[xxx][yyy]=true;
                        lenn[xxx][yyy]=lenn[k][h]+1;
                    }
                }
            }
            queue<int>qex;
            queue<int>qey;
            int ssx,ssy;
            int lennn[31][31];
            for (int i=0;i<=3;i++){
                ex=sx;ey=sy;
                now=0;
                xxx=sx+xz[i];yyy=sy+yz[i];
                if (lenn[xxx][yyy]!=1000){
                    now+=lenn[xxx][yyy]+1;
                    while (!qx.empty()) qx.pop();
                    while (!qex.empty()) qex.pop();
                    while (!qey.empty()) qey.pop();
                    while (!qy.empty()) qy.pop();
                    qx.push(xxx);qy.push(yyy);qex.push(sx);qey.push(sy);
                    for (int j=1;i<=n;j++)
                      for (k=1;k<=m;k++)
                        lennn[j][k]=0x3fffffff;
                    lennn[xxx][yyy]=now;
                    while (!qx.empty){
                        ex=qex.front();ey=qey.front();
                        ssx=qx.front();
                        ssy=qy.front();
                        for (int jj=0;jj<=3;jj++){
                            xxx=ssx+xz[i];
                            yyy=ssy+yz[i];
                            if (xxx>=1 && xxx<=n && yyy>=1 && yyy<=m && mapp[xxx][yyy] && !(xxx==ex && yyy==ey))){
                                lennn[xxx][yyy]=min(lennn[xxx][yyy],lennn[ssx][ssy]+len[ex][ey][xxx][yyy][1]+1);
                                qx.push(xxx);qy.push(yyy);qex.push(ssx);qey.push(ssy);
                            }
                        }
                    }
                }
            }
        }
    }
}
int main(){
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    init();
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
