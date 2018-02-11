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
struct NODE{
    int w,ind;
}k[N+geps];
int n,s[N+geps],rn=0;
inline bool cmp(NODE a,NODE b){
    return a.w < b.w;
}
void Init(){
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&k[i].w),k[i].ind=i;
    sort(k+1,k+n+1,cmp);
    k[0].w=-2000000000;
    rep(i,1,n){
        if(k[i].w != k[i-1].w) rn++;
        s[k[i].ind]=rn;
    }
}
int tree[5*N+geps][2]={};
void pushin(int k,int ak,int bk,int L,int R,int rt){
    if(L == R && L == k){
        tree[rt][0]=ak;
        tree[rt][1]=bk;
        return;
    }
    int mid=(L+R)>>1;
    if(k <= mid) pushin(k,ak,bk,L,mid,rt<<1);
    else pushin(k,ak,bk,mid+1,R,rt<<1|1);
    tree[rt][0]=max(tree[rt<<1][0],tree[rt<<1|1][0]);
    tree[rt][1]=max(tree[rt<<1][1],tree[rt<<1|1][1]);
}
int findd(int l,int r,int k,int L,int R,int rt){
    if(l > r) return 0;
    if(l <= L && R <= r) return tree[rt][k];
    int mid=(L+R)>>1,ret=0;
    if(l <= mid) ret=max(ret,findd(l,r,k,L,mid,rt<<1));
    if(mid < r) ret=max(ret,findd(l,r,k,mid+1,R,rt<<1|1));
    return ret;
}
void Solve(){
    Init();
    int ak,bk;
    ak=1;bk=1;
    pushin(s[1],1,1,1,rn,1);
    rep(i,2,n){
        bk=findd(1,s[i]-1,0,1,rn,1)+1;
        ak=findd(s[i]+1,rn,1,1,rn,1)+1;
        pushin(s[i],ak,bk,1,rn,1);
    }
    printf("%d\n",max(findd(1,rn,0,1,rn,1),findd(1,rn,1,1,rn,1)));
}
int main(){
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    Solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
