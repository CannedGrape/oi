#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

typedef long long ll;

int main(){
  srand(time(0));
  int N=100000;
  cout << N << endl;
  map <int,int> M;
  for (int i=1;i<=2;++i){
    M.clear();
    for (int i=1;i<=N;++i){
      for (;;){
        int t=(ll)rand()*rand()%2147483647;
        if (!M.count(t)){cout << t << " "; M[t]=i; break;}
      }
    }
    cout << endl;
  }
}
