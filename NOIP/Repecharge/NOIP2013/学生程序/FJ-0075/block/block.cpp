#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int N,h[100010]={};long long S=0;
int main(){
    freopen("block.in","r",stdin);freopen("block.out","w",stdout);
    scanf("%d",&N);
    for(int i=1;i<=N;++i){
        scanf("%d",&h[i]);
        S+=h[i];
    }
    int i,j,t;long long ans=0;
    while(S>0){
             i=1;
             while(i<=N){
                          t=0x3fffffff;
                          while(i<=N && h[i]==0){++i;}
                          j=i;
                          while(i<=N && h[i]>0){
                                     if(h[i]<t)t=h[i];
                                     ++i;
                          }
                          if(j==i)break;
                          for(int k=j;k<=i-1;++k){
                                  h[k]-=t;S-=t;
                                  }
                          ans+=t;
                          }
    }
    printf("%lld\n",ans);
    fclose(stdin);fclose(stdout);
    return 0;
}
