#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
using namespace std;
const int maxn=100000+10,mod=99999997;

int n,ans=0;

struct node{
 int num,pos;
}s1[maxn],s2[maxn];

bool operator<(const node &a,const node &b){
 return a.num<b.num;
}

void init(){
 scanf("%d",&n);
 for(int i=1;i<=n;i++){ 
  scanf("%d",&s1[i].num);
  s1[i].pos=i;
 }
  //
 //for(int i=1;i<=n;i++) 
 // cout<<s1[i].pos<<" "<<s1[i].num<<endl;
 //cout<<endl;
 //
 sort(s1+1,s1+n+1);
 for(int i=1;i<=n;i++){ 
  scanf("%d",&s2[i].num);
  s2[i].pos=i;
 }
   //
 //for(int i=1;i<=n;i++) 
 // cout<<s2[i].pos<<" "<<s2[i].num<<endl;
// cout<<endl;
 //
 sort(s2+1,s2+n+1);
}

void work(){
 //
 //for(int i=1;i<=n;i++) 
 // cout<<s1[i].pos<<" "<<s1[i].num<<endl;
 //cout<<endl;
 //
  //
 //for(int i=1;i<=n;i++) 
 // cout<<s2[i].pos<<" "<<s2[i].num<<endl;
// cout<<endl;
 //
 for(int i=1;i<=n;i++)
  for(int j=i+1;j<=n;j++)
   if(s1[i].pos==s2[j].pos) ans=(ans+1)%mod;
 printf("%d\n",ans);
}

int main(){
 freopen("match.in","r",stdin);
 freopen("match.out","w",stdout);
 init();
 work();
 return 0;
}
