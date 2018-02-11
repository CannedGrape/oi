#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    int *a[1000],*b[1001];
    int i,j,n,m,ans=1;
    int f[1000];
    
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    
    a[0]=new int [1000];
    for(i=1;i<=999;i++) a[i]=new int [1000];
    b[0]=new int [1001];
    for(i=1;i<=999;i++) b[i]=new int [1001];
    
    scanf("%d%d",&n,&m);
    
    for(i=0;i<=m;i++) {
        for(j=0;j<=n;j++) b[i][j]=0;
    }
    
    for(i=0;i<=m-1;i++) {
        scanf("%d",&f[0]);
        for(j=0;j<=f[0]-1;j++) {
            scanf("%d",&a[i][j]);
            b[i][a[i][j]]=1;
        }
    }
    
    for(i=1;i<=m-1;i++) {
        for(j=1;j<=n;j++) {
            if((b[i][j]==0 && b[i-1][j]==1) || (b[i][j]==1 && b[i-1][j]==0)) {
                ans++;
                break;
            }
        }
    }
    
    cout<<ans;
    
    return 0;
}
