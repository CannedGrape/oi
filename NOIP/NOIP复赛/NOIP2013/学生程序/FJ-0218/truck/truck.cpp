#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#define LL long long
using namespace std;
//编译了大概五秒。。每次编译都五秒多。。
//不得不说这题给我信心。。
LL pls,rds,qs,q,pl,rd;
LL dis[10005][10005] = {};
LL spfa(LL from, LL to) {
LL  dist[10005];
bool inq[10005] = {};
queue<LL> searchQue;
for (int i=1;i<=pls;i++) {
    if (dis[from][i]) {
        dist[i] = dis[from][i];
        searchQue.push(i);
        inq[i]  = true;
    }
    else {
        dist[i] = -1;
        inq[i]  = false;
    }
}
while (!searchQue.empty()) {
    int sp = searchQue.front();
    searchQue.pop();
    inq[sp] = false;
    for (int i=1;i<=pls;i++) {
        if (i == sp) continue;
        if (!dis[sp][i]) continue;
        //没有链接就链接
        //载重更大就更新
        //Yeah!!!!!!!
        if (dist[i] == -1) {
            dist[i] = min(dist[sp],dis[sp][i]);
            
            if (!inq[i]) {
            searchQue.push(i);
            inq[i]  = true;        
            }
        }
        if (dist[i] < min(dist[sp],dis[sp][i])) {
            dist[i] = min(dist[sp],dis[sp][i]);
            
            if (!inq[i]) {
            searchQue.push(i);
            inq[i]  = true;        
            }
        }
        
    }

}
return dist[to];

}
int main(){

    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%lld%lld",&pls,&rds);
    for (rd=1;rd<=rds;rd++) {
    LL from,to,wei;
    scanf("%lld%lld%lld",&from,&to,&wei);
    if (dis[from][to] && dis[from][to] > wei) continue;
    dis[from][to] = dis[to][from] = wei;
    }
    scanf("%lld",&qs);
    for (q=1;q<=qs;q++) {
    LL from,to;
    scanf("%lld%lld",&from,&to);
    LL wei = spfa(from,to);
    printf("%lld\n",wei);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
