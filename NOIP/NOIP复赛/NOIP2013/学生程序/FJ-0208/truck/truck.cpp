#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=100005,MOD=99999997;
int n;
int ta[MAXN],tb[MAXN];
struct node
{ 
  int value,num;
}a[MAXN],b[MAXN];
int c[MAXN];
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
  for (int i=1;i<=n;i++) a[i].value=Get(),a[i].num=i,ta[i]=a[i].value;
  for (int i=1;i<=n;i++) b[i].value=Get(),b[i].num=i,tb[i]=b[i].value;
} 
int cmp(const node &a,const node &b)
{ 
  return a.value<b.value;
}
int Lowbit(int x) { return x&(-x); }
int getsum(int x)
{
  int res=0;
  while (x>0) 
    {
	  res+=c[x];
	  x-=Lowbit(x); 
	}
  return res;
}
void add(int x,int value)
{
  while (x<=n)  
    { 
	  c[x]+=value;
	  x+=Lowbit(x);
	}
}
int find(int x)
{
  int l=1,r=n;
  while (l+2<r) 
    { 
	  int mid=(l+r)/2;
	  if (a[mid].value==x) return mid;
	  if (a[mid].value<x) l=mid;
	  else r=mid;
	}
  for (int i=l-1;i<=r+1;i++) 
    if (a[i].value==x) return i;
  return 0;
}
void solve()
{ 
  sort(a+1,a+n+1,cmp); sort(b+1,b+n+1,cmp);
  for (int i=1;i<=n;i++) add(i,1);
  for (int i=1;i<=n;i++)
    { 
	   int t=find(ta[b[i].num]);
	   if (t<i) ans=ans+LL(getsum(i)-getsum(t-1)); 
	   else ans=ans+LL(getsum(t)-getsum(i-1)); 
	   ans%=MOD;
	   add(t,-1);
	}
}
void output()
{ 
  cout<<ans<<endl;
}
int main()
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  init();
  solve();
  return 0;
}
{ 
  init();
  solve();
  return 0;
} 
