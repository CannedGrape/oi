#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<string>
using namespace std;
struct shuzu{
    int w,xb;
}a[100010],b[100010];
int px[100010],summ[100010]={};
int n;
bool cmp(shuzu a,shuzu b){
    if (a.w<b.w) return true;
    return false;
}
int lowbit(int i){
    return (i&(-i));
}
void addqj(int x){
    while (x>0){
        summ[x]++;
        x-=lowbit(x);
    }
}
int getzh(int x){
    int ret=0;
    while (x<=n){
        ret+=summ[x];
        x+=lowbit(x);
    }
    return ret;
}
int main(){
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i].w);
        a[i].xb=i;
    }
    for (int i=1;i<=n;i++){
        scanf("%d",&b[i].w);
        b[i].xb=i;
    }
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
    for (int i=1;i<=n;i++){
        px[a[i].xb]=b[i].xb;
    }
    int j,k;
    int ans=0;
    for (int i=1;i<=n;i++){
        j=px[i]+getzh(px[i]);
        k=j-i;
        if (k<0) k=-k;
        ans=(ans+k)%99999997;
        addqj(px[i]-1);
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
