#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=100001;
struct FLO
{
  int v,p;
} b[MAXN];
int n,t0,t1,tot=0,ans=0;
int a[MAXN],f[MAXN][2];
int tree_0[MAXN*4],tree_1[MAXN*4];

void file_open()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
}

void file_close()
{
    fclose(stdin); fclose(stdout);
}

int cmp(const FLO &x,const FLO &y)
{
    return x.v<y.v;
}

int init()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      b[i].v=a[i];
      b[i].p=i;
    }
    sort(b+1,b+n+1,cmp);
    
    b[0].v=-1;
    for (int i=1;i<=n;i++)
    {
      if (b[i].v!=b[i-1].v) tot++;
      a[b[i].p]=tot;
    }
    
    return 0;
}

int find_0(int k,int l,int r,int x,int y)
{
    if (l>r) return 0;
    if (r<x || l>y) return 0;
    if (l>=x && r<=y)
    {
      t0=max(t0,tree_0[k]);
      return 0;
    }
    
    int mid=(l+r)/2;
    find_0(k*2,l,mid,x,y);
    find_0(k*2+1,mid+1,r,x,y);
    return 0;
}

int find_1(int k,int l,int r,int x,int y)
{
    if (l>r) return 0;
    if (r<x || l>y) return 0;
    if (l>=x && r<=y)
    {
      t1=max(t1,tree_1[k]);
      return 0;
    }
    
    int mid=(l+r)/2;
    find_1(k*2,l,mid,x,y);
    find_1(k*2+1,mid+1,r,x,y);
    return 0;
}

int change_0(int k,int l,int r,int x,int v)
{
    if (l>r) return 0;
    if (r<x || l>x) return 0;
    if (l==r && r==x)
    {
      tree_0[k]=max(tree_0[k],v);
      return 0;
    }
    
    int mid=(l+r)/2;
    change_0(k*2,l,mid,x,v);
    change_0(k*2+1,mid+1,r,x,v);
    tree_0[k]=max(tree_0[k*2],tree_0[k*2+1]);
    return 0;
}

int change_1(int k,int l,int r,int x,int v)
{
    if (l>r) return 0;
    if (r<x || l>x) return 0;
    if (l==r && r==x)
    {
      tree_1[k]=max(tree_1[k],v);
      return 0;
    }
    
    int mid=(l+r)/2;
    change_1(k*2,l,mid,x,v);
    change_1(k*2+1,mid+1,r,x,v);
    tree_1[k]=max(tree_1[k*2],tree_1[k*2+1]);
    return 0;
}

int work()
{
    memset(tree_0,0,sizeof(tree_0));
    memset(tree_1,0,sizeof(tree_1));
    memset(f,0,sizeof(f));
    
    for (int i=1;i<=n;i++)
    {
      t1=t0=0;
      find_1(1,1,tot,1,a[i]-1); 
      find_0(1,1,tot,a[i]+1,tot);
      
      f[a[i]][0]=max(f[a[i]][0],t1+1);
      f[a[i]][1]=max(f[a[i]][1],t0+1);
      
      change_0(1,1,tot,a[i],f[a[i]][0]);
      change_1(1,1,tot,a[i],f[a[i]][1]);
      
      ans=max(ans,max(f[a[i]][0],f[a[i]][1]));
    }
    
    cout<<ans<<endl;
    return 0;
}

int main()
{
    file_open();
    init();
    work();
    //system("pause");
    file_close();
    return 0;
}
