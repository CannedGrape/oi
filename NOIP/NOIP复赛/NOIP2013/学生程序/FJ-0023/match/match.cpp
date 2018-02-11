#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MO=99999997;
const int MAXN=100001,MAXS=100001*2*15;
struct MAT
{
  int v,p;
} a[MAXN],b[MAXN];
char buf[MAXS];
int n,pp,ans;
int tar[MAXN],tmpt[MAXN];

void file_open()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
}

void file_close()
{
    fclose(stdin); fclose(stdout);
}

int analyse()
{
    while (buf[pp]>'9' || buf[pp]<'0') pp++;
    int tmp=0;
    while (buf[pp]>='0' && buf[pp]<='9')
    {
      tmp=tmp*10+buf[pp]-'0';
      pp++;
    }
    return tmp;
}

int init()
{
    int len=fread(buf,1,MAXS,stdin);
    buf[len]='\0';
    n=analyse();
    for (int i=1;i<=n;i++) 
    {
      a[i].v=analyse();
      a[i].p=i;
    }
    for (int i=1;i<=n;i++) 
    {
      b[i].v=analyse();
      b[i].p=i;
    }
    return 0;
}

int cmp(const MAT &x,const MAT &y)
{
    return x.v<y.v;
}

int gb_sort(int l,int r)
{
    if (l>=r) return 0;
    int mid=(l+r)/2;
    gb_sort(l,mid);
    gb_sort(mid+1,r);
    
    int i=l,j=mid+1,k=l;
    do
    {
      if (tar[i]<tar[j])
      {
        tmpt[k]=tar[i];
        i++; k++;
      }
      else
      {
        ans=(ans+(mid-i+1))%MO;
        tmpt[k]=tar[j];
        j++; k++;
      }
    }
    while (i<=mid && j<=r);
    
    while (i<=mid) 
    {
      tmpt[k]=tar[i];
      i++; k++;
    }
    
    while (j<=r)
    {
      tmpt[k]=tar[j];
      j++; k++;
    }
    
    for (int ll=l;ll<=r;ll++)
      tar[ll]=tmpt[ll];
    return 0;
}

int work()
{
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
    for (int i=1;i<=n;i++)
      tar[a[i].p]=b[i].p;
    
    gb_sort(1,n);
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
