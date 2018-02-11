#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cstring>
#include<ctime>
#include<cmath>

using namespace std;
const int maxn=100000+10;
int n,s[maxn],h[maxn],ans=2,tot=0;

void init(){
 scanf("%d",&n);
 for(int i=1;i<=n;i++) scanf("%d",&s[i]);
}

void work(){
 s[0]=-1;
 for(int i=1;i<=n;i++) 
  if(s[i]!=s[i-1]) h[++tot]=s[i];
 for(int i=2;i<tot;i++)
  if((h[i]>h[i-1] && h[i]>h[i+1] )||( h[i]<h[i-1] && h[i]<h[i+1] )) ans++;
 printf("%d\n",ans);
}

int main(){
 freopen("flower.in","r",stdin);
 freopen("flower.out","w",stdout);
 init();
 work();
 return 0;
}

 //
 /*for(int i=1;i<=tot;i++)
  printf("%d ",h[i]);*/
 //
