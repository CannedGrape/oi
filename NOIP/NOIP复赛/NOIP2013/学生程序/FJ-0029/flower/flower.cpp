#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<stdio.h>
#include<string.h>
using namespace std;
int n,h[100010];
int fff[100010][3]={};
void baoli(){
    int ans=1;
    for (int i=1;i<=n;i++) scanf("%d",&h[i]);
    if (n>1 && h[2]!=h[1]) ans=2;
    for (int i=2;i<=n;i++){
        fff[i][2]=1;
        if (h[i]>h[1]) fff[i][1]=2;
        if (h[i]<h[1]) fff[i][0]=2;
        for (int j=2;j<=i-1;j++){
            if (h[i]>h[j]) {
                fff[i][1]=max(fff[i][1],fff[j][2]+1);
                fff[i][2]=max(fff[i][2],fff[j][0]+1);
                ans=max(ans,fff[i][2]);
                ans=max(ans,fff[i][1]);
            }
            if (h[i]<h[j]){
                fff[i][0]=max(fff[i][0],fff[j][2]+1);
                fff[i][2]=max(fff[i][2],fff[j][1]+1);
                ans=max(ans,fff[i][2]);
                ans=max(ans,fff[i][0]);
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&n);
    if (n<=1000) baoli();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
