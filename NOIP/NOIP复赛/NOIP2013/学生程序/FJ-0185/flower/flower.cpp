#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN=100010;

int N,h[MAXN],f[MAXN][2],c0[MAXN],c1[MAXN],
  tempxnum=0,tempx[MAXN],xnum=0,X[MAXN];

void discretize();
void DP();
int query(int[],int);
void add(int[],int,int);

int main(){
  freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
  cin >> N;
  for (int i=1;i<=N;++i){
    scanf("%d",&h[i]);
    tempx[++tempxnum]=h[i];
  }
  discretize();
  DP();
  int ans=0;
  for (int i=1;i<=N;++i){
    ans=max(ans,f[i][0]);
    ans=max(ans,f[i][1]);
  }
  cout << ans << endl;
  return 0;
}

void discretize(){
  sort(tempx+1,tempx+1+tempxnum);
  xnum=0;
  for (int i=1;i<=tempxnum;++i)
    if (i==1 || tempx[i]!=tempx[i-1]) X[++xnum]=tempx[i];
  for (int i=1;i<=N;++i){
    int l=1,r=xnum,mid;
    for (;;){
      mid=(l+r)>>1;
      if (h[i]==X[mid]) break;
      if (h[i]<X[mid]) r=mid-1;
      else l=mid+1;
    }
    h[i]=mid;
  }
}

void DP(){
  for (int i=1;i<=xnum;++i) c0[i]=c1[i]=0;
  add(c0,h[1],1); add(c1,xnum-h[1]+1,1);
  for (int i=1;i<=N;++i) f[i][0]=f[i][1]=1;
  for (int i=2;i<=N;++i){
    f[i][0]=max(f[i][0],query(c1,xnum-h[i])+1);
    f[i][1]=max(f[i][1],query(c0,h[i]-1)+1);
    add(c0,h[i],f[i][0]);
    add(c1,xnum-h[i]+1,f[i][1]);
  }
}

int query(int c[],int r){
  int ans=0;
  for (int i=r;i>=1;i-=i&-i) ans=max(ans,c[i]);
  return ans;
}

void add(int c[],int pos,int val){
  for (int i=pos;i<=xnum;i+=i&-i) c[i]=max(c[i],val);
}
