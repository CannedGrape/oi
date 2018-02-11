#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <climits>
#include <algorithm>
#include <vector>
#define LL long long
using namespace std;
LL t,l1,l2,r1,r2,n;
LL p;
vector<LL> l,r;
void swap(LL q,LL w,char p){
if (p=='r') {
LL tmp = r[q];
r[q] = r[w];
r[w] = tmp;
} else{
LL tmp = l[q];
l[w] = l[q];
l[q] = tmp;
}



}
void diff(LL l1, LL l2,LL l3,LL r1,LL r2,LL r3) {
        //解决两边不同递增或递减的问题吧少年！！
        //如果上面破坏？如果下面破坏？如果都破坏？如果都不？
    if ((!(l2 <= l3)^(r1 <= r3)) && ((l1 <= l3)^(r2 <= r3))) {
    swap(r2,r1,'r');return;
    }
    if ((!(l1 <= l3)^(r2 <= r3)) && ((l2 <= l3)^(r1 <= r3))) {
    swap(l1,l2,'l');return;
    }
        //感觉我的算法在这里有错，
        //和样例2相悖
    swap(r2,r1);
    return;
}
int main(){
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%lld",&n);
    for (LL i=1;i<=n; i++)
        scanf("%lld",&t), l.push_back(t);
    for (LL i=1;i<=n; i++)
        scanf("%lld",&t), r.push_back(t);
    l1 = l2 = l[0];
    r1 = r2 = r[0];
    LL ans = 0;
    //在尝试的时候我曾在这里加入n循环枚举n，就像冒泡排序一样
    //感觉这东西和冒泡有点相似的。尼玛，冒泡做做看？。。。

    //好吧，最后我还是交这个版本，毕竟样例都对了。
    for (p=1;p<n;p++) {
        //Paste!
        l1 = l2;
        r1 = r2;
        //Get!
        l2 = l[p];
        r2 = r[p];
        bool linc = l2 >= l1;
        bool rinc = r2 >= r1;
        if (!(l2-l1)) continue;
        if (!(r2-r1)) continue;
        if (linc == rinc) continue;
        ans ++;
        if (p != n-1) {
        LL l3 = l[p+1];
        LL r3 = r[p+1];
        diff (l1,l2,l3,r1,r2,r3);
        }
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
