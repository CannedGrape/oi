#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

typedef long long ll;

int main(){
  srand(time(0));
  int N=(ll)rand()*rand()%1000000+1;
  int M=(ll)rand()*rand()%(N-1)+1;
  int K=rand()%7+1;
  int X=rand()%N;
  printf("%d %d %d %d\n",N,M,K,X);
}
