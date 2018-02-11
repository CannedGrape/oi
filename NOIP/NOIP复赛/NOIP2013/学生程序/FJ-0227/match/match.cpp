#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MOD=99999997;
const int N=100011;
struct Node
{
  int qz;
  int no;
}a[N],b[N];
int r[N];
bool cmp(Node A,Node B) {return A.qz<B.qz;}
int n;
int T[N]={0};

int lowbit(int x) {return x&-x;}

void Insert(int p)
{
  for (int i=p;i<=n;i+=lowbit(i)) T[i]++;
}

int Solve(int p)
{
  int re=0;
  for (int i=p;i>0;i-=lowbit(i)) re+=T[i];
  return re;
}

int main()
{
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  scanf("%d",&n);
  for (int i=1;i<=n;i++)
  {
    scanf("%d",&a[i].qz);
    a[i].no=i;
  }
  for (int i=1;i<=n;i++)
  {
    scanf("%d",&b[i].qz);
    b[i].no=i;
  }
  sort(a+1,a+n+1,cmp);
  sort(b+1,b+n+1,cmp);
  for (int i=1;i<=n;i++) r[a[i].no]=b[i].no;
  int ans=0;
  Insert(r[1]);
  for (int i=2;i<=n;i++)
  {
    int delta=Solve(n)-Solve(r[i]-1);
    ans=(ans+delta)%MOD;
    Insert(r[i]);
  }
  printf("%d\n",ans);
  return 0;
}
