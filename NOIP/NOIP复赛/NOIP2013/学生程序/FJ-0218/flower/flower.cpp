#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#define LL long long
using namespace std;
//很抱歉，我先写个暴力搜索
LL plts;
LL ans,bestans = 0;
const LL maxp = 100000 + 3;
long long pnts[maxp][2] = {};
long long hei[maxp] = {};
void find(LL p,LL h, char want,char direction,LL got) {
LL next;
//cout << "i am at"<<p<<"looking "<<want<<" than "<<h<<"got "<<got<<"already"<<endl;
if (p == 0){
ans += got;
return;
}
if (p > plts) {
ans += got;
return;
}
if (direction == 'l') next = p-1;
if (direction == 'r') next = p+1;
if (want == 'u'){
    if (hei[p] > h) find(next,hei[p],'d',direction,got+1);
    else find(next,h,'u',direction,got);
} else {
    if (hei[p] < h) find(next,hei[p],'u',direction,got+1);
    else find(next,h,'d',direction,got);
}

}
int main(){
freopen("flower.in","r",stdin);
freopen("flower.out","w",stdout);

    scanf("%lld",&plts);
    for (LL p=1;p<=plts;p++) {
        scanf("%lld",&hei[p]);
    }
    for (LL p=1;p<=plts;p++) {
        ans = 1;
        find(p,hei[p],'u','l',0);
        find(p,hei[p],'u','r',0);
        if (ans == 2) ans = 0;
        bestans = max(ans,bestans);
    }
    printf("%lld",bestans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
