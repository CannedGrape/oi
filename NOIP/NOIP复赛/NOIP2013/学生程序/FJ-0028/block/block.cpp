#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <memory.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int N = 100000,geps = 10;
int n,w[N+geps];
int tree[5*N+geps]={},add[5*N+geps]={};
struct NODE{
    int l,r,s;
};
void pushin(int k,int num,int L,int R,int rt){
    if(L == R && L == k){
         tree[rt]=num;
         return;
    }
    int mid=(L+R)/2;
    if(k <= mid) pushin(k,num,L,mid,rt*2);
    else pushin(k,num,mid+1,R,rt*2+1);
    tree[rt]=min(tree[rt*2],tree[rt*2+1]);
}
int gett(int l,int r,int L,int R,int rt){
    if(l <= L && R <= r) return tree[rt];
    int mid=(L+R)/2,ret=2147483647;
    if(l <= mid) ret=min(ret,gett(l,r,L,mid,rt*2));
    if(r > mid) ret=min(ret,gett(l,r,mid+1,R,rt*2+1));
    return ret;
}
void Init(){
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&w[i]),pushin(i,w[i],1,n,1);
}
queue<NODE>q;
int nowedge,ededge[N+geps];
void Solve(){
    while(!q.empty())q.pop();
    int ans=0;
    Init();
    NODE k;
    k.l=1,k.r=n,k.s=0;
    q.push(k);
    while(!q.empty()){
        NODE now=q.front();
        q.pop();
        nowedge=0;
        ededge[0]=now.l-1;
        int f=gett(now.l,now.r,1,n,1);
        rep(i,now.l,now.r) if(w[i] == f) ededge[++nowedge]=i;
        ededge[nowedge+1]=now.r+1;
        ans+=f-now.s;
        rep(i,0,nowedge){
            k.l=ededge[i]+1,k.r=ededge[i+1]-1,k.s=f;
            if(k.l <= k.r)q.push(k);
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    Solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
