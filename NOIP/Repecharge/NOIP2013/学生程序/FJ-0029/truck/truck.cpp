#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<string>
#include<queue>
using namespace std;
const int maxh = 15;
queue<int>qq;
int n,m,q;
int fa[30010],f[30010][20],dep[30010];
struct zdy{
    int w;
    int ll,rr;
} dhb[30010];
struct line{
    int u,v,ww;
} biann[50010],bian[10010];
bool cmp(line a,line b){
     if (a.ww>b.ww) return 1;
     return 0;
}
int getfather(int i){
    if (fa[i]==i) return i;
    fa[i]=getfather(fa[i]);
    return fa[i];
}
int lcaa(int a,int b){
    int i,j;
    if (dep[a]>dep[b]){
        i=a;a=b;b=i;
    }
    i=dep[b]-dep[a];j=0;
    while (i){
        if (i&1) b=f[b][j];
        j++;i>>=1;
    }
    for (i=15;i>=0;i--){
        if (f[a][i]!=f[b][i]){
            a=f[a][i];b=f[b][i];
        }
    }
    if (a==b) return a;
    return f[a][0];
}
int main(){
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d%d",&n,&m);
    int x,y,z;
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        biann[i].u=x;biann[i].v=y;biann[i].ww=z;
    }
    sort(biann+1,biann+m+1,cmp);
    for (int i=1;i<=n;i++) fa[i]=i;
    int mm;
    mm=m;
    m=0;
    int j,k;
    for (int i=1;i<=mm;i++){
        j=biann[i].u;
        k=biann[i].v;
        if (getfather(j)!=getfather(k)){
            fa[getfather(j)]=getfather(k);
            bian[++m].u=j;bian[m].v=k;bian[m].ww=biann[i].ww;
            dhb[n+m].w=biann[i].ww;
        }
        if (m==n-1) break;
    }
    for (int i=1;i<=n+m;i++) fa[i]=i;
    for (int i=1;i<=m;i++){
        j=getfather(bian[i].u);
        k=getfather(bian[i].v);
        if (j!=k){
            dhb[n+i].ll=j;
            dhb[n+i].rr=k;
            fa[j]=n+i;
            fa[k]=n+i;
            f[j][0]=n+i;
            f[k][0]=n+i;
        }
    }
    for (int i=1;i<=n+m;i++){
        if (fa[i]==i){
            dep[i]=1;
            for (j=0;j<=15;j++) f[i][j]=i;
            while (!qq.empty()) qq.pop();
            if (dhb[i].ll) {qq.push(dhb[i].ll);dep[dhb[i].ll]=dep[i]+1;}
            if (dhb[i].rr) {qq.push(dhb[i].rr);dep[dhb[i].rr]=dep[i]+1;}
            while (!qq.empty()){
                j=qq.front();
                qq.pop();
                if (dhb[j].ll) {qq.push(dhb[j].ll);dep[dhb[j].ll]=dep[j]+1;}
                if (dhb[j].rr) {qq.push(dhb[j].rr);dep[dhb[j].rr]=dep[j]+1;}
                for (k=1;k<=15;k++) f[j][k]=f[f[j][k-1]][k-1];
            }
        }
    }
    scanf("%d",&q);
    for (int i=1;i<=q;i++){
        scanf("%d%d",&x,&y);
        if (getfather(x)!=getfather(y)) printf("%d\n",-1);
        else{
            z=lcaa(x,y);
            printf("%d\n",dhb[z].w);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
