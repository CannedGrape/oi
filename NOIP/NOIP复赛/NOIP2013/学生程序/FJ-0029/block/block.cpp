#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<stdio.h>
#include<string.h>
#define inf 0x3fffffff
using namespace std;
int n;
int gen;
int qz[100010];
int zw=1;
struct pointt{
    int w;int ll,rr;
} dke[100010];
int tot=1;
int ans=0;
void dkeinsert(int i){
    zw++;
    bool pd=0;
    while (zw>1 && dke[qz[zw-1]].w>dke[i].w) {zw--;pd=1;}
    if (pd) dke[i].ll=qz[zw];
    if (zw>1) dke[qz[zw-1]].rr=i;
    qz[zw]=i;
}
void dfs(int i,int lj){
    ans+=(dke[i].w-lj);
    if (dke[i].ll) dfs(dke[i].ll,dke[i].w);
    if (dke[i].rr) dfs(dke[i].rr,dke[i].w);
}
int main(){
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    scanf("%d",&n);
    int h;
    scanf("%d",&h);
    qz[1]=1;
    dke[1].w=h;
    for (int i=2;i<=n;i++){
        scanf("%d",&dke[i].w);
        dkeinsert(i);
    }
    dfs(qz[1],0);
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
