#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN=1000010;

int N,M,K,X,R[MAXN];

int count1();

int main(){
  freopen("circle.in","r",stdin);
  freopen("circle.out","w",stdout);
  cin >> N >> M >> K >> X;
  int cir=count1();
  ll ans=1,c=10;
  for (;K;K>>=1){
    if (K&1) ans=ans*c%cir;
    c=c*c%cir;
  }
  cout << R[ans] << endl;
  return 0;
}

int count1(){
  R[0]=X;
  int i=1;
  for (;;++i){
    R[i]=(R[i-1]+M)%N;
    if (R[i]==X) break;
  }
  return i;
}
