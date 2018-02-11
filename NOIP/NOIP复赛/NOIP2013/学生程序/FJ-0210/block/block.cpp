#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cstring>
#include<ctime>
#include<cmath>

using namespace std;
const int maxn=100000+10,maxm=10000+10;
int n,s[maxn],h[maxn],tot=0,f[maxm],Feng[maxm],Gu[maxm];
long long ans=0;

void init(){
 scanf("%d",&n);
 for(int i=1;i<=n;i++) 
  scanf("%d",&s[i]);
}

void pf(){
 int maxh=0;
 for(int i=1;i<=n;i++) maxh=max(maxh,s[i]);
 for(int i=1;i<=maxh;i++){
  for(int i=1;i<=n;i++) 
   if(s[i]>0 &&s[i-1]<=0) ans++;
  for(int i=1;i<=n;i++)
   if(s[i]>0) s[i]--;
 }
 printf("%lld\n",ans);
}

void work(){
 int maxh=0;
 for(int i=1;i<=n;i++) maxh=max(maxh,s[i]);
 s[0]=-1;
 for(int i=1;i<=n;i++)
  if(s[i]!=s[i-1]) h[++tot]=s[i];
 for(int i=2;i<tot;i++){
  if(h[i]>h[i-1] && h[i]>h[i+1]) Feng[h[i]]++;
  if(h[i]<h[i-1] && h[i]<h[i+1]) Gu[h[i]]++;
 }
 if(h[1]>h[2]) Feng[h[1]]++;
 if(h[tot]>h[tot-1]) Feng[h[tot]]++;
 f[0]=1;
 for(int i=1;i<=maxh;i++)
  f[i]=f[i-1]+Gu[i-1]-Feng[i-1];
 for(int i=1;i<=maxh;i++)
  ans+=f[i];
 printf("%lld\n",ans);
}

int main(){
 freopen("block.in","r",stdin);
 freopen("block.out","w",stdout);
 init();
 if(n<=1000) pf();
 else work();
 return 0;
}
  /* while(st<=n){
    while(s[st]<=0) st++;
	if(st>=n) break;	
    en=st;
    while(s[en+1]>0) en++;
    ans++;
    st=en+1;
   }*/
