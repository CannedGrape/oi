#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    int i,
        j,
        t,
        k,
        count=0,
        n,
        x;
    int a[10];
    
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d%d",&n,&x);
    for(i=1;i<=n;i++) {
        t=10;
        j=i;
        k=0;
        while(j>0) {
            a[k]=j%t;
            j=j/t;
            t=t*10;
            k++;
        }
        for(j=0;j<=k;j++) {
            if(a[j]==x) count++;
        }
    }
    
    printf("%d",count);
    return 0;
}
