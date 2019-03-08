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
const int N = 100000,geps = 10,MOD = 99999997;
struct NODE{
    int x,ind;
}ka[N+geps],kb[N+geps];
int n,a[N+geps],b[N+geps],t[N+geps];
inline bool cmp(const NODE _a,const NODE _b){
    return _a.x < _b.x;
}
inline void Init(){
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]),ka[i].x=a[i],ka[i].ind=i;
    rep(i,1,n) scanf("%d",&b[i]),kb[i].x=b[i],kb[i].ind=i;
}

int tree[5*N+geps]={};
void pushin(int k,int L,int R,int rt){
    tree[rt]++;
    if(L != R){
        int mid=(L+R)>>1;
        if(k <= mid) pushin(k,L,mid,rt<<1);
        else pushin(k,mid+1,R,rt<<1|1);
    }
}
int askk(int l,int r,int L,int R,int rt){
    if(l <= L && R <= r)
        return tree[rt];
    int mid=(L+R)>>1,ret=0;
    if(l <= mid) ret+=askk(l,r,L,mid,rt<<1);
    if(mid < r) ret+=askk(l,r,mid+1,R,rt<<1|1);
    return ret;
}
inline void Solve(){
    int ans=0;
    Init();
    sort(ka+1,ka+n+1,cmp);
    sort(kb+1,kb+n+1,cmp);
    rep(i,1,n) t[ka[i].ind]=kb[i].ind;
    rep(i,1,n) ans+=t[i]-i+askk(t[i]+1,n,1,n,1),pushin(t[i],1,n,1),ans%=MOD;
    printf("%d\n",ans);
}
int main(){
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    Solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
