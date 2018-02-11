#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,l[1001],r[1001];
long long cj=1,s=0;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
      scanf("%d%d",&l[i],&r[i]);
    for(int i=1;i<=n;i++){
      cj=1;
      for(int j=0;j<=i-1;j++)
        cj*=l[j];
      cj/=r[i];
      if(cj>s)s=cj;}
    printf("%lld\n",s);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
