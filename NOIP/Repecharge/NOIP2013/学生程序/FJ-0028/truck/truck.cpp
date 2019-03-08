#include <iostream>
#include <stdio.h>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <memory.h>
#include <stdlib.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int N = 10000,M = 50000,Q = 30000,geps = 10;
struct ROAD{
    int x,y,z;
}r[M+geps];
int n,m,q,ans[Q+geps];
int toedge[N+geps]={},ededge[2*Q+geps]={},nextedge[2*Q+geps]={},nowedge=0,mean[2*Q+geps]={};
int father[N+geps],sons[N+geps],edge[N+geps]={},eedge[2*N+geps]={},nedge[2*N+geps]={},value[2*N+geps]={},nowe=0;
inline void addedge(int a,int b,int k){
    ededge[++nowedge]=b;
    nextedge[nowedge]=toedge[a];
    toedge[a]=nowedge;
    mean[nowedge]=k;
}
inline void addedge2(int a,int b,int v){
    eedge[++nowe]=b;
    nedge[nowe]=edge[a];
    edge[a]=nowe;
    value[nowe]=v;
}
int getfather(int f){
    if(father[f] == f) return f;
    father[f]=getfather(father[f]);
    return father[f];
}

inline bool cmp(const ROAD a,const ROAD b){
    return a.z > b.z;
}
inline void make_tree(){
    rep(i,1,n) sons[i]=1,father[i]=i;
    sort(r+1,r+m+1,cmp);
    rep(i,1,m){
        int a=getfather(r[i].x),b=getfather(r[i].y);
        if(a != b){
            father[b]=a;
            addedge2(r[i].x,r[i].y,r[i].z);
            addedge2(r[i].y,r[i].x,r[i].z);
            sons[a]+=sons[b];
            sons[b]=0;
            if(sons[a] == n) return;
        }
    }
}
int lcaf[N+geps],len[N+geps];
int asktoedge[N+geps]={},askededge[2*Q+geps]={},askvalue[2*Q+geps]={},asknextedge[2*Q+geps]={},asknowedge=0;
int getf(int k){
    if(lcaf[k] == k) return k;
    int kk=lcaf[k];
    lcaf[k]=getf(lcaf[k]);
    len[k]=min(len[k],len[kk]);
    return lcaf[k];
}
inline void addk(int a,int b,int c){
    askededge[++asknowedge]=b;
    askvalue[asknowedge]=c;
    asknextedge[asknowedge]=asktoedge[a];
    asktoedge[a]=asknowedge;
}
void LCA(int now,int f){
     lcaf[now]=now;
     len[now]=2147483647;
     for(int i=edge[now];i != 0;i=nedge[i]){
         if(eedge[i] != f){
             LCA(eedge[i],now);
             lcaf[eedge[i]]=now;
             len[eedge[i]]=value[i];
         }
     }
     for(int i=asktoedge[now];i != 0;i=asknextedge[i]){
         getf(askvalue[i]);
         ans[askededge[i]]=min(ans[askededge[i]],len[askvalue[i]]);
     }
     for(int i=toedge[now];i != 0;i=nextedge[i]){
         if(ans[mean[i]] == 0 && lcaf[ededge[i]] != ededge[i]){
             addk(getf(ededge[i]),mean[i],now);
             ans[mean[i]]=len[ededge[i]];
         }
     }
}
inline void Init(){
    scanf("%d%d",&n,&m);
    rep(i,1,m) scanf("%d%d%d",&r[i].x,&r[i].y,&r[i].z);
    make_tree();
    scanf("%d",&q);
    int a,b;
    rep(i,1,q){
        scanf("%d%d",&a,&b);
        if(getfather(a) != getfather(b)){
            ans[i]=-2;
        }else{
            addedge(a,b,i),addedge(b,a,i),ans[i]=0;
        }
    }
}
inline void Solve(){
    Init();
    LCA(1,1);
    rep(i,1,q) ans[i] == -2 ? printf("-1\n") : printf("%d\n",ans[i]);
}
int main(){
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    Solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
