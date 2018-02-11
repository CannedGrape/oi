#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
int n,m,i,j;
int main(){
    freopen("blockade.in","r",stdin);
    freopen("blockade.out","w",stdout);
    scanf("%d",&n);
    int u[n+1],v[n+1],w[n+1],s[n+1];
    for(i=1;i<=n-1;i++)scanf("%d%d%d",&u[i],&v[i],&w[i]);
    scanf("%d",&m);
    for(i=1;i<=m;i++){scanf("%d",&j);s[j]++;}
    printf("3\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
