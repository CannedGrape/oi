#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<algorithm>
#define M int(3e05)
#define N int(1e05+50)
using namespace std;
int f0[M],f1[M];
int h[N];
struct jh
{
       int h,no;
       }x[N];
bool cmp(const jh &x,const jh &y)
{
     return x.h<y.h;
     }
void xiu_0(int no,int l,int r,int x,int z)
{
     if(x<l||x>r) return;
     if(l==r&&l==x)
     {
      f0[no]=z;
      return;
      }
     int mid=(l+r)/2;
     xiu_0(no*2,l,mid,x,z);
     xiu_0(no*2+1,mid+1,r,x,z);
     f0[no]=max(f0[no*2],f0[no*2+1]);
     return;
     }
void xiu_1(int no,int l,int r,int x,int z)
{
     if(x<l||x>r) return;
     if(l==r&&l==x)
     {
      f1[no]=z;
      return;
      }
     int mid=(l+r)/2;
     xiu_1(no*2,l,mid,x,z);
     xiu_1(no*2+1,mid+1,r,x,z);
     f1[no]=max(f1[no*2],f1[no*2+1]);
     return;
     }
int find_0(int no,int l,int r,int x,int y)
{
    if(x<=l&&y>=r) return f0[no];
    if(x>r||y<l) return 0;
    int mid=(l+r)/2;
    return max(find_0(no*2,l,mid,x,y),find_0(no*2+1,mid+1,r,x,y));
    }
int find_1(int no,int l,int r,int x,int y)
{
    if(x<=l&&y>=r) return f1[no];
    if(x>r||y<l) return 0;
    int mid=(l+r)/2;
    return max(find_1(no*2,l,mid,x,y),find_1(no*2+1,mid+1,r,x,y));
    }
int main()
{
    freopen("flower.in","r",stdin);freopen("flower.out","w",stdout);
    int n,mh=0,ans=0,no=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
     scanf("%d",&h[i]);
     x[i].no=i;x[i].h=h[i];
     }
    sort(x+1,x+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
            ++no;
            h[x[i].no]=no;
            while(x[i].h==x[i+1].h&&i<n)
            {
                                        ++i;
                                        h[x[i].no]=no;
                                        }
            }
    mh=no;
    for(int i=1;i<=n;i++)
    {
            int tem1,tem2;
            tem1=find_0(1,0,mh,0,h[i]-1);
            tem2=find_1(1,0,mh,h[i]+1,mh);
            if(tem1+1>ans)
            ans=tem1+1;
            if(tem2+1>ans)
            ans=tem2+1;
            xiu_1(1,0,mh,h[i],tem1+1);
            xiu_0(1,0,mh,h[i],tem2+1);
            }
    cout<<ans;
    fclose(stdin);fclose(stdout);
    return 0;
    }
