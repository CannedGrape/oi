#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n;
int h[100001];
int ll,rr;
bool flag[100001];
int ansl=0,ansr=0;
void solve1l(int l,int r)
{
    int i,j,tr,tl;
    bool found=false;
    for (i=r-1;i>=l;i--)
    {
        for (j=1;j<=i-1;j++) 
          if (h[i]<h[r] && h[i]<h[j])
          {
           flag[i]=false;
           ansl+=2;
           found=true;
           tl=1;
           tr=j;
           break;
             } 
      if (found==true)
        break;  
    }
    if (tr>tl+1)
      solve1l(tl,tr);
}
void solve1r(int l,int r)
{
    int i,j,tr,tl;
    bool found=false;
    for (i=l+1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++) 
          if (h[i]<h[l] && h[i]<h[j])
          {
           flag[i]=false;
           ansr+=2;
           found=true;
           tl=j;
           tr=n;
           break;
             } 
      if (found==true)
        break;  
    }
    if (tr-1>tl)
      solve1r(tl,tr);
}
void solve2l(int l,int r)
{
    int i,j,tr,tl;
    bool found=false;
    for (i=r-1;i>=l;i--)
    {
        for (j=1;j<=i-1;j++) 
          if (h[i]>h[r] && h[i]>h[j])
          {
           flag[i]=false;
           ansl+=2;
           found=true;
           tl=1;
           tr=j;
           break;
             } 
      if (found==true)
        break;  
    }
    if (tr>tl+1)
      solve2l(tl,tr);
}
void solve2r(int l,int r)
{
    int i,j,tr,tl;
    bool found=false;
    for (i=l+1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++) 
          if (h[i]>h[l] && h[i]>h[j])
          {
           flag[i]=false;
           ansr+=2;
           found=true;
           tl=j;
           tr=n;
           break;
             } 
      if (found==true)
        break;  
    }
    if (tr-1>tl)
      solve2r(tl,tr);
}
bool lj1(int k)
{
     int i,j;
     for (i=k-1;i>=1;i--)
     {
         if (h[i]>h[k])
           for (j=k+1;j<=n;j++)
             if (h[j]>h[k])
             {
               ll=i;
               rr=j;
               return true;
               }
               }
     return false;
     }
bool lj2(int k)
{
     int i,j;
     for (i=k-1;i>=1;i--)
     {
         if (h[i]<h[k])
           for (j=k+1;j<=n;j++)
             if (h[j]<h[k])
             {
               ll=i;
               rr=j;
               return true;
               }
               }
     return false;
     }
int solvemin()
{
    int i;
    int maxx=0,max0=0;
    memset(flag,true,sizeof(flag));
    for (i=2;i<=n;i++)
    {
        if (flag[i]==true)
          if (lj1(i)==true)
          {
            ansl=0;
            ansr=0;
            maxx=3;
            flag[i]=false;
            solve1l(1,ll);
            solve1r(rr,n);
            maxx+=ansl+ansr;
            }
        if (maxx>max0)
          max0=maxx;
        }
    return max0;
} 
int solvemax()
{
    int i;
    int maxx=0,max0=0;
    memset(flag,true,sizeof(flag));
    for (i=2;i<=n;i++)
    {
        if (flag[i]==true)
          if (lj2(i)==true)
          {
            ansl=0;
            ansr=0;
            maxx=3;
            flag[i]=false;
            solve2l(1,ll);
            solve2r(rr,n);
            maxx+=ansl+ansr;
            }
        if (maxx>max0)
          max0=maxx;
        }
    return max0;
}  
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i;
    int minn;
    int maxx;
    cin>>n;
    for (i=1;i<=n;i++)
      scanf("%d",&h[i]);
    minn=solvemin();
    maxx=solvemax();
    if(minn>maxx)
      cout<<minn<<endl;
    else
      cout<<maxx<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    
