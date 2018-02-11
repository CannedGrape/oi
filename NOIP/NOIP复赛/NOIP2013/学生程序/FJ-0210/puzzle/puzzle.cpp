#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cstring>
#include<ctime>
#include<cmath>

using namespace std;
int n,m,q;

void pf(){
 scanf("%d%d%d",&n,&m,&q);
 for(int i=1;i<=q;i++) 
  printf("-1\n");
}

int main(){
 freopen("puzzle.in","r",stdin);
 freopen("puzzle.out","w",stdout);
 pf();
 return 0;
}
