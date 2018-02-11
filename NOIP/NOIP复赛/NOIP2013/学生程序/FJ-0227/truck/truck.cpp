#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

const int N=10011;
const int M=50011;
struct Point
{
  int next;
  Point() {next=-1;}
}P[N];
struct Egde
{
  int to,c;
  int next;
}E[2*M];
int Enum=-1,n,m;
int mid;
int x,y,z;
bool check[N];

void Ins(int from,int to,int qz)
{
  Enum++;
  E[Enum].to=to; E[Enum].next=P[from].next; E[Enum].c=qz;
  P[from].next=Enum;
}

void dfs(int no)
{
  check[no]=1;
  if (check[y]) return;
  for (int p=P[no].next;p!=-1;p=E[p].next)
  {
    if (check[E[p].to]) continue;
    if (E[p].c<mid) continue;
    dfs(E[p].to);
    if (check[y]) return;
  }
}

int main()
{
  freopen("truck.in","r",stdin);
  freopen("truck.out","w",stdout);
  scanf("%d%d",&n,&m);
  int maxi=0;
  for (int i=1;i<=m;i++)  
  {
    scanf("%d%d%d",&x,&y,&z);
    Ins(x,y,z);  
    Ins(y,x,z);
    maxi=max(maxi,z);
  }
  int q;
  scanf("%d",&q);
  for (int T=1;T<=q;T++)
  {
    scanf("%d%d",&x,&y);
    int l=0,r=maxi;
    while (l<r)
    {
      mid=(l+r)/2;
      for (int i=1;i<=n;i++) check[i]=false;    
      dfs(x);
      if (check[y]) l=mid+1; else r=mid-1;
    }
    mid=l;
    for (int i=1;i<=n;i++) check[i]=false;
    dfs(x);
    if (!check[y]) l--;
    printf("%d\n",l);
  } 
  return 0;
}
