#include <iostream>
#include <stdio.h>
using namespace std;
const int maxn = 100001;
int n,h[maxn],ans1[maxn],ans2[maxn],ans;
int main(){
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
      scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d",&h[i]);
    for(int i=1;i<=n;i++){
      ans1[i]=1;
      ans2[i]=1;
    }
    for(int i=2;i<=n;i++){
       for(int j=1;j<i;j++)
         if(h[i]<h[j]&&ans2[j]+1>ans1[i])
           ans1[i]=ans2[j]+1;
       for(int j=1;j<i;j++)
         if(h[i]>h[j]&&ans1[j]+1>ans2[i])
           ans2[i]=ans1[j]+1;
    }
    ans=1;
    for(int i=1;i<=n;i++){
        if(ans1[i]>ans) ans=ans1[i];
        if(ans2[i]>ans) ans=ans2[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
