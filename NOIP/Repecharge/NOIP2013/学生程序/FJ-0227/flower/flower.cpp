#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int ans=0;
const int N=100011;
int h[N];
int f[N][2]={0};
int n;
struct Node
{
  int h;
  int no;
}lsh[N];
bool cmp(Node A,Node B) {return A.h<B.h;}
int nh=0;
struct Tree
{
  int l,r;
  int maxi[2];
}T[N*4];

void init()
{
  sort(lsh+1,lsh+n+1,cmp);
  lsh[n+1].h=2000000000;
  for (int i=1;i<=n;i++)
  {
    int j=i;
    nh++;
    while (lsh[j+1].h==lsh[i].h) j++;
    for (int k=i;k<=j;k++) h[lsh[k].no]=nh;
    i=j;
  }
}

void Build_Tree(int i,int l,int r)
{
  T[i].l=l; T[i].r=r;
  T[i].maxi[0]=T[i].maxi[1]=0;
  if (l==r) return;
  int mid=(l+r)/2;
  Build_Tree(i*2,l,mid); Build_Tree(i*2+1,mid+1,r);
}

void Insert(int i,int no)
{
  if (T[i].l==T[i].r)
  {
    T[i].maxi[0]=max(T[i].maxi[0],f[no][0]);
    T[i].maxi[1]=max(T[i].maxi[1],f[no][1]);
    return;
  }
  int mid=(T[i].l+T[i].r)/2;
  if (h[no]<=mid) Insert(i*2,no); else Insert(i*2+1,no);
  T[i].maxi[0]=max(T[i*2].maxi[0],T[i*2+1].maxi[0]);
  T[i].maxi[1]=max(T[i*2].maxi[1],T[i*2+1].maxi[1]);
}

int Query(int i,int l,int r,int j)
{
  if (l>r) return 0;
  if (T[i].l==l&&T[i].r==r) return T[i].maxi[j];
  int mid=(T[i].l+T[i].r)/2; 
  return max(Query(i*2,l,min(r,mid),j),Query(i*2+1,max(mid+1,l),r,j));
}

int main()
{
  freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
  scanf("%d",&n);
  for (int i=1;i<=n;i++) {scanf("%d",&lsh[i].h); lsh[i].no=i;}
  init();
  Build_Tree(1,1,nh);
  for (int i=1;i<=n;i++)
  {
    f[i][0]=f[i][1]=1;//1比前面大  0比前面小
    f[i][0]=max(f[i][0],Query(1,h[i]+1,nh,1)+1);
    f[i][1]=max(f[i][1],Query(1,1,h[i]-1,0)+1);
    /*for (int j=1;j<i;j++)
    {
      if (h[j]<h[i]) f[i][1]=max(f[i][1],f[j][0]+1);
      if (h[j]>h[i]) f[i][0]=max(f[i][0],f[j][1]+1);    
    }*/
    ans=max(ans,f[i][1]);
    ans=max(ans,f[i][0]);
    Insert(1,i);
  }
  printf("%d\n",ans);
  return 0;
}
