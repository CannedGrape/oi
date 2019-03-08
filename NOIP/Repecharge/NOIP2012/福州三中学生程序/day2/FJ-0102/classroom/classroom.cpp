#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
int n,m,i,j;
bool flag;
int main(){
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    scanf("%d%d",&n,&m);
    int a[n+1],d[m+1],s[m+1],t[m+1];
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=m;i++)scanf("%d%d%d",&d[i],&s[i],&t[i]);
    for(i=1;i<=m;i++){
      flag=1;
      for(j=s[i];j<=t[i];j++){a[j]-=d[i];if(a[j]<0)flag=0;}
      if(!flag)break;}
    if(!flag) printf("-1\n%d\n",i);
    else printf("0\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
