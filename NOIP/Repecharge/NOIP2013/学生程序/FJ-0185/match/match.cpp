#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN=100010,MOD=99999997;

typedef long long ll;

struct match{
  int a,b;
}h[MAXN];

int N,X[MAXN],c[MAXN],a[MAXN],xnum=0;

bool cmp(match,match);
void discretize();
ll count1();

int main(){
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  cin >> N;
  for (int i=1;i<=N;++i) scanf("%d",&h[i].a);
  for (int i=1;i<=N;++i) scanf("%d",&h[i].b);
  sort(h+1,h+1+N,cmp);
  for (int i=1;i<=N;++i){
    a[i]=h[i].a;
    X[++xnum]=a[i];
  }
  discretize();
  cout << count1() << endl;
  return 0;
}

bool cmp(match m1,match m2){return m1.b<m2.b;}

void discretize(){
  sort(X+1,X+1+xnum);
  for (int i=1;i<=N;++i){
    int l=1,r=xnum,mid;
    for (;;){
      mid=(l+r)>>1;
      if (a[i]==X[mid]) break;
      if (a[i]<X[mid]) r=mid-1;
      else l=mid+1;
    }
    a[i]=mid;
  }
}

ll count1(){
  for (int i=1;i<=xnum;++i) c[i]=0;
  ll ans=0;
  for (int i=N;i>=1;--i){
    for (int j=a[i]-1;j>=1;j-=j&-j){
      ans+=c[j];
      if (ans>=MOD) ans-=MOD;
    }
    for (int j=a[i];j<=xnum;j+=j&-j){
      ++c[j];
      if (c[j]>=MOD) c[j]-=MOD;
    }
  }
  return ans;
}
