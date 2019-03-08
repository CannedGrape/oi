#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=100005,INF=99999999;
int n;
int h[MAXN]; 
LL ans;
int Get()
{ 
  char ch; int sum=0; bool f=false;
  while (!isdigit(ch=getchar()))
    if (ch=='-') f=true;sum=ch-48;
  while (isdigit(ch=getchar())) sum=sum*10+ch-48;
  if (f) return -sum;else return sum;
}
void init()
{ 
  n=Get();
  for (int i=1;i<=n;i++) h[i]=Get();
}
void work(int l,int r)
{ 
  int _min=INF,x;
  for (int i=l;i<=r;i++)    
    if (h[i]<_min) x=i,_min=h[i];
  for (int i=l;i<=r;i++) h[i]-=_min;
  ans+=LL(_min);
  if (l<=x-1) work(l,x-1); 
  if (r>=x+1) work(x+1,r);
}
void output()
{ 
  cout<<ans<<endl;
}
void solve()
{ 
  work(1,n);
}
int main()
{  
  freopen("block.in","r",stdin);
  freopen("block.out","w",stdout);
  init();
  solve();
  output();
  return 0;
}
