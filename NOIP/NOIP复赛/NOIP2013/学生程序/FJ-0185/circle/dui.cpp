#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
  int N,M,K,X;
  cin >> N >> M >> K >> X;
  int e=1;
  for (int i=1;i<=K;++i) e*=10;
  for (int i=1;i<=e;++i)
    X=(X+M)%N;
  cout << X << endl;
  return 0;
}
