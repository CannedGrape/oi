#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN=100010;

int h[MAXN],S[MAXN];

int main(){
  freopen("block.in","r",stdin);
  freopen("block.out","w",stdout);
  int N; cin >> N;
  for (int i=1;i<=N;++i) scanf("%d",&h[i]);
  int top=1; ll ans=h[1]; S[1]=1;
  for (int i=1;i<=N;++i){
    if (h[i]>h[S[top]]) ans+=h[i]-h[S[top]];
    for (;top && h[i]>=h[S[top]];--top);
    S[++top]=i;
  }
  cout << ans << endl;
  return 0;
}
