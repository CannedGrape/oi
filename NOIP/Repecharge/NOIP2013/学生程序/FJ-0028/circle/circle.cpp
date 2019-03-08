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
ll n,m,k,x;
ll mypow(ll a,ll b){
    ll s=1;
    for(;b;b>>=1){
        if(b & 1) s=s*a%n;
        a=a*a%n;
    }return s;
}
inline void Solve(){
     scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
     printf("%lld\n",(x+((mypow(10,k)*m)%n))%n);
}
int main(){
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    Solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
